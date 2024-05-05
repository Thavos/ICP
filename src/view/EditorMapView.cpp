#include "EditorMapView.h"

EditorMapView::EditorMapView(QWidget *parent)
        : QGraphicsView(parent), map(new Map()) {
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    placementMode = "Robot";
    mode = "Placement Mode";
}

void EditorMapView::setEditMode(const QString &mode) {
    placementMode = mode;
}

void EditorMapView::setMode(const QString &m) {
    mode = m;
}

void EditorMapView::mousePressEvent(QMouseEvent *event) {
    QPointF scenePos = mapToScene(event->pos());
    initialMousePos = scenePos;
    if (mode == "Placement Mode") {
        if (placementMode == "Robot") {
            addRobotAtPosition(scenePos);
        } else if (placementMode == "Obstacle") {
            addObstacleAtPosition(scenePos);
        }
    } else if (mode == "Editing Mode") {
        QGraphicsItem *item = scene->itemAt(scenePos, QTransform());
        if (item) {
            selectItem(item);
            initialPos = item->pos();
            qDebug() << "Selected item at position:" << item->pos();
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void EditorMapView::mouseReleaseEvent(QMouseEvent *event) {
    QGraphicsView::mouseReleaseEvent(event);

    if (selectedItem && mode == "Editing Mode") {
        QPointF newPos = mapToScene(event->pos());


        if (checkOverlap(selectedItem, newPos, selectedItem->boundingRect().size())) {
            qDebug() << "Overlap detected, setting back to initial position at" << initialPos;
            selectedItem->setPos(initialPos);

        } else {
            qDebug() << "No overlap detected, setting new position to" << newPos;
            positionChanged(selectedItem, newPos);
            selectedItem->setPos(newPos);
            initialPos = newPos;
        }
    }
}

void EditorMapView::setItemColor(QGraphicsItem *item, const QColor &color) {
    auto *rectItem = dynamic_cast<QGraphicsRectItem *>(item);
    auto *ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item);

    if (rectItem) {
        rectItem->setBrush(QBrush(color));
    } else if (ellipseItem) {
        ellipseItem->setBrush(QBrush(color));
    }
}

QGraphicsEllipseItem* EditorMapView::findRobotItemByPosition(const QPointF& position) {
    QList<QGraphicsItem*> itemsAtPos = scene->items(position, Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
            foreach (QGraphicsItem* item, itemsAtPos) {
            auto* ellipseItem = dynamic_cast<QGraphicsEllipseItem*>(item);
            if (ellipseItem) {
                return ellipseItem; // Return the first ellipse item found
            }
        }
    return nullptr; // Return nullptr if no ellipse item is found at the position
}

void EditorMapView::updateRobotDirection(Robot* robot, QGraphicsEllipseItem* robotGraphics) {
    if (!robotGraphics->childItems().isEmpty()) {
        QGraphicsLineItem* directionLine = dynamic_cast<QGraphicsLineItem*>(robotGraphics->childItems().first());
        if (directionLine) {
            Vector2D dir = robot->getDir();
            // Assuming that the line should originate from the center of the robot and extend outwards
            QPointF center = robotGraphics->boundingRect().center();
            directionLine->setLine(center.x(), center.y(), center.x() + 20 * dir.x, center.y() + 20 * dir.y);
        } else {
            qDebug() << "First child item is not a QGraphicsLineItem";
        }
    } else {
        qDebug() << "No child items found in robotGraphics";
    }
}

void EditorMapView::setBackItemColor(QGraphicsItem *item) {
    auto *rectItem = dynamic_cast<QGraphicsRectItem *>(item);
    auto *ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item);
    if (rectItem) {
        rectItem->setBrush(QBrush(Qt::gray)); // Set obstacle color to gray
    } else if (ellipseItem) {
        ellipseItem->setBrush(QBrush(Qt::blue)); // Set robot color to blue
    }
}

void EditorMapView::addRobotAtPosition(const QPointF &pos) {
    if (!checkOverlap(nullptr, pos, QSizeF(20, 20))) {
        emit robotAdded(pos);

        auto robot = map->getRobot(Vector2D(pos.x(), pos.y()));

        auto item = new QGraphicsEllipseItem(-10, -10, 20, 20);
        item->setPos(pos);
        item->setPen(Qt::NoPen);
        item->setBrush(Qt::blue);

        Vector2D dir = robot->getDir();
        auto* directionLine = new QGraphicsLineItem(0, 0, 20 * dir.x, 20 * dir.y, item);
        directionLine->setPen(QPen(Qt::red, 2));

        scene->addItem(item);
    }
}

void EditorMapView::addObstacleAtPosition(const QPointF &pos) {
    if (!checkOverlap(nullptr, pos, QSizeF(20, 20))) {
        emit obstacleAdded(pos);

        auto item = new QGraphicsRectItem(-10, -10, 20, 20); // Position relative to the item's top-left corner
        item->setPos(pos); // Set the position in scene coordinates
        item->setPen(Qt::NoPen);
        item->setBrush(Qt::gray);
        scene->addItem(item);
    }
}

bool EditorMapView::checkOverlap(const QGraphicsItem *ignoreItem, const QPointF &pos, const QSizeF &size) const {
    QRectF newRect(pos.x() - size.width() / 2, pos.y() - size.height() / 2, size.width(), size.height());
            foreach (QGraphicsItem *item, scene->items()) {
            if (item == ignoreItem)
                continue;

            QRectF itemRect = item->sceneBoundingRect();
            if (itemRect.intersects(newRect)) {
                qDebug() << "Overlap detected at position:" << item->pos();
                return true; // Overlap detected
            }
        }
    return false; // No overlap detected
}

void EditorMapView::positionChanged(QGraphicsItem *item, const QPointF &newPos) {
    auto newPosVector = Vector2D(newPos.x(), newPos.y());
    auto oldPosVector = Vector2D(item->pos().x(), item->pos().y());

    if (item == selectedItem) {
        if (auto *robotItem = dynamic_cast<QGraphicsEllipseItem *>(item)) {
            emit robotPositionChanged(newPosVector, oldPosVector);
        } else if (auto *obstacleItem = dynamic_cast<QGraphicsRectItem *>(item)) {
            emit obstaclePositionChanged(newPosVector, oldPosVector);
        }
    }
}


void EditorMapView::selectItem(QGraphicsItem *item) {
    selectedRobot = nullptr;

    auto robotItem = dynamic_cast<QGraphicsEllipseItem *>(item);
    if (robotItem) {
        // Iterate through robots
        for (Robot &robot : *(map->getRobots())) {
            if (robot.getPos() == Vector2D(item->pos().x(), item->pos().y())) {
                // Robot found
                selectedRobot = &robot;
                if (selectedItem) {
                    // Set previous item color back
                    setBackItemColor(selectedItem);
                }
                selectedItem = item;
                setItemColor(selectedItem, Qt::green);
                return;
            }
        }
    }

    // Check if the item is an obstacle
    auto obstacleItem = dynamic_cast<QGraphicsRectItem *>(item);
    if (obstacleItem) {
        // Iterate through obstacles
        for (auto obstacle : *(map->getObstacles())) {
            if (obstacle.getPos() == Vector2D(item->pos().x(), item->pos().y())) {
                if (selectedItem) {
                    // Set previous item color back
                    setBackItemColor(selectedItem);
                }
                selectedItem = item;
                setItemColor(selectedItem, Qt::green);
                return;
            }
        }
    }
}

Robot *EditorMapView::getSelectedRobot() {
    return selectedRobot;
}




