#include "SimulationMapView.h"

// xhruzs00

/**
 * @brief Constructs a new SimulationMapView object.
 * @param parent The parent widget, default is nullptr.
 */
SimulationMapView::SimulationMapView(QWidget *parent, Map &simulationMap)
    : QGraphicsView(parent), map(simulationMap) {
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(0,0,800,600);

    populateScene();
}

/**
 * @brief Destroys the SimulationMapView object.
 */
SimulationMapView::~SimulationMapView() {
}

void SimulationMapView::populateScene() {
    scene->clear();

    for(Robot& robot : *(map.getRobots())){
        Vector2D pos = robot.getPos();
        scene->addEllipse(pos.x - 10, pos.y - 10, 20, 20, QPen(), QBrush(Qt::blue));
    }

    for(Obstacle& obstacle : *(map.getObstacles())){
        Vector2D pos = obstacle.getPos();
        scene->addRect(pos.x - 10, pos.y - 10, 30, 30, QPen(), QBrush(Qt::red));
    }
}

void SimulationMapView::updateRobotPositions() {
    populateScene();
}

