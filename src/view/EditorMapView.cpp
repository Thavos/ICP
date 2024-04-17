#include "EditorMapView.h"

EditorMapView::EditorMapView(QWidget *parent)
        : QGraphicsView(parent), map(new Map()) {
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(0, 0, 800, 600);
    editMode = "Robot";
}

void EditorMapView::setEditMode(const QString& mode) {
    editMode = mode;
}

void EditorMapView::mousePressEvent(QMouseEvent *event) {
    QPointF scenePos = mapToScene(event->pos());
    if (editMode == "Robot") {
        addRobotAtPosition(scenePos);
    } else if (editMode == "Obstacle") {
        addObstacleAtPosition(scenePos);
    }
}

void EditorMapView::addRobotAtPosition(const QPointF& pos) {
    auto item = scene->addEllipse(pos.x() - 10, pos.y() - 10, 20, 20, QPen(), QBrush(Qt::blue));
}

void EditorMapView::addObstacleAtPosition(const QPointF& pos) {
    auto item = scene->addRect(pos.x() - 10, pos.y() - 10, 20, 20, QPen(), QBrush(Qt::gray));
}

QString EditorMapView::getMapDataAsString() const {
    return "";
}