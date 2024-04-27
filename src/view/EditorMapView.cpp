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
    qDebug() << "currently at this scene pos:" << scenePos;
    if (mode == "Placement Mode") {
        if (placementMode == "Robot") {
            addRobotAtPosition(scenePos);
        } else if (placementMode == "Obstacle") {
            addObstacleAtPosition(scenePos);
        }
    } else if (mode == "Editing Mode") {
        QGraphicsItem *item = scene->itemAt(scenePos, QTransform());
        if (item) {
            auto *robotItem = dynamic_cast<QGraphicsEllipseItem *>(item);
            auto *obstacleItem = dynamic_cast<QGraphicsRectItem *>(item);

            if (robotItem || obstacleItem) {
                if (selectedItem && selectedItem != item) {
                    qDebug() << "farbim tehoto kkta:" << item->pos();
                    setBackItemColor(selectedItem);
                    selectedItem->setFlag(QGraphicsItem::ItemIsMovable, false);
                }

                if (selectedItem != item) {
                    selectedItem = item;
                    item->setFlag(QGraphicsItem::ItemIsMovable, true);
                    initialPos = item->pos();
                    initialMousePos = mapToScene(event->pos());
                    setItemColor(item, Qt::green);
                }
            }
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void EditorMapView::mouseReleaseEvent(QMouseEvent *event) {
    QGraphicsView::mouseReleaseEvent(event);

    if (selectedItem && mode == "Editing Mode") {
        QPointF diff = mapToScene(event->pos()) - initialMousePos;

        QPointF newPos = initialPos + diff;

        if (checkOverlap(selectedItem, newPos, selectedItem->boundingRect().size())) {
            selectedItem->setPos(initialPos);
        } else {
            selectedItem->setPos(newPos);
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

void EditorMapView::setBackItemColor(QGraphicsItem *item) {
    auto *rectItem = dynamic_cast<QGraphicsRectItem *>(item);
    auto *ellipseItem = dynamic_cast<QGraphicsEllipseItem *>(item);
    qDebug() << "Mam farbit naspatky";
    if (rectItem) {
        rectItem->setBrush(QBrush(Qt::gray)); // Set obstacle color to gray
    } else if (ellipseItem) {
        ellipseItem->setBrush(QBrush(Qt::blue)); // Set robot color to blue
    }
}

void EditorMapView::addRobotAtPosition(const QPointF &pos, const double &direction, double detectionRange, double turningAngle, bool turningDirection) {
    if (!checkOverlap(nullptr, pos, QSizeF(20, 20))) {
        qDebug() << "Adding robot at position:" << pos;

        Vector2D vectorPos = Vector2D(pos.x(), pos.y());
        Vector2D vectorDirection = directionVectorFromDegrees(direction);

        Robot robot(vectorPos, vectorDirection, detectionRange, turningAngle, turningDirection);
        map->addRobot(robot);
        auto item = new QGraphicsEllipseItem(-10, -10, 20, 20); // Position relative to the item's top-left corner
        item->setPos(pos); // Set the position in scene coordinates
        item->setPen(Qt::NoPen);
        item->setBrush(Qt::blue);
        scene->addItem(item);
    }
}

void EditorMapView::addObstacleAtPosition(const QPointF &pos) {
    if (!checkOverlap(nullptr, pos, QSizeF(20, 20))) {
        qDebug() << "Adding obstacle at position:" << pos;
        auto item = new QGraphicsRectItem(-10, -10, 20, 20); // Position relative to the item's top-left corner
        item->setPos(pos); // Set the position in scene coordinates
        item->setPen(Qt::NoPen);
        item->setBrush(Qt::gray);
        scene->addItem(item);
    }
}

bool EditorMapView::checkOverlap(const QGraphicsItem *ignoreItem, const QPointF &pos, const QSizeF &size) const {
    QRectF newRect(pos.x() - size.width() / 2, pos.y() - size.height() / 2, size.width(), size.height());
    qDebug() << "Checking overlap at position:" << pos << "with size:" << size;
            foreach (QGraphicsItem *item, scene->items()) {
            if (item == ignoreItem)
                continue;

            QRectF itemRect = item->sceneBoundingRect();
            if (itemRect.intersects(newRect)) {
                qDebug() << "Overlap detected with item:" << item << "at position:" << item->pos();
                return true; // Overlap detected
            }
        }
    return false; // No overlap detected
}

QString EditorMapView::getMapDataAsString() const {
    return "";
}

Vector2D EditorMapView::directionVectorFromDegrees(double degrees) {
    // Convert degrees to radians
    float radians = qDegreesToRadians(degrees);

    // Calculate the x and y components of the direction vector using trigonometry
    float x = qCos(radians);
    float y = qSin(radians);

    return Vector2D(x, y);
}
