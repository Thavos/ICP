#include "SimulationController.h"

// xhruzs00

SimulationController::SimulationController(Map &simulationMap, SimulationMapView &simulationView) 
    : map(simulationMap), mapView(simulationView) {
    connect(this, &SimulationController::robotPositionsUpdated, &mapView, &SimulationMapView::updateRobotPositions);
}
SimulationController::~SimulationController() {}

void SimulationController::startSimulation() {
    isRunning = true;
    qDebug() << "Simulation started";

    // robots = map.getRobots();
    // obstacles = map.getObstacles();

    QTimer::singleShot(0, this, &SimulationController::updateRobots);
}

void SimulationController::pauseSimulation() {
    isRunning = false;
    qDebug() << "Simulation paused";
}

void SimulationController::resumeSimulation() {
    isRunning = true;
    qDebug() << "Simulation resumed";
    QTimer::singleShot(0, this, &SimulationController::updateRobots);
}

void SimulationController::updateRobots() {
    if(isRunning == false) 
        return;

    qDebug() << "Updating robots...";
    std::vector<Robot> *robotVec  = map.getRobots();

    if (robotVec->empty()) {
        qDebug() << "Robots vector is empty!";
        return;
    }
    
    for (Robot& robotPtr : *robotVec)
    {
        Vector2D newPos = robotPtr.updatePos();
        if(newPos.x < 0) {
            newPos.x = 0;
        }
        if(newPos.y < 0) {
            newPos.y = 0;
        }

        if(newPos.x > map.getSize().x) {
            newPos.x = map.getSize().x;
        }
        if(newPos.y > map.getSize().y) {
            newPos.y = map.getSize().y;
        }

        robotPtr.setPos(newPos);
    }


    QTimer::singleShot(33, this, &SimulationController::updateRobots);
    emit robotPositionsUpdated();
} 