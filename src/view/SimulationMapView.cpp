#include "SimulationMapView.h"
#include <QDebug>

// xhruzs00

/**
 * @brief Constructs a new SimulationMapView object.
 * @param parent The parent widget, default is nullptr.
 */
SimulationMapView::SimulationMapView(QWidget *parent) : QGraphicsView(parent), simulationMap(nullptr){
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    scene->setSceneRect(0,0,800,600);
}

/**
 * @brief Destroys the SimulationMapView object.
 */
SimulationMapView::~SimulationMapView() {
}

void SimulationMapView::setSimulationMap(std::unique_ptr<Map> map) {
    simulationMap = std::move(map);

    populateScene();
}

void SimulationMapView::populateScene() {
    if(!simulationMap) return;

    scene->clear();

    for(auto& robot : simulationMap->getRobots()){
        auto pos = robot.getPos();
        scene->addEllipse(pos.x - 10, pos.y - 10, 20, 20,QPen(), QBrush(Qt::blue));
        qDebug() << "Adding robot at position:" << pos.x << pos.y;
    }

    for(auto& obstacle : simulationMap->getObstacles()){
        auto pos = obstacle.getPos();
        scene->addRect(pos.x - 10, pos.y - 10, 30, 30,QPen(), QBrush(Qt::red));
        qDebug() << "Adding obstacle at position:" << pos.x << pos.y;
    }
}

