#include "SimulationController.h"

// xhruzs00

SimulationController::SimulationController(Map &simulationMap, SimulationMapView &simulationView) 
    : map(simulationMap), mapView(simulationView) {
    connect(this, &SimulationController::robotPositionsUpdated, &mapView, &SimulationMapView::updateRobotPositions);
    robots = map.getRobots();
    obstacles = map.getObstacles();
}
SimulationController::~SimulationController() {}

void SimulationController::startSimulation() {
    isRunning = true;
    qDebug() << "Simulation started";

    QTimer::singleShot(0, this, &SimulationController::updateRobots);
}

void SimulationController::pauseSimulation() {
    isRunning = false;
    qDebug() << "Simulation paused";
}

void SimulationController::resumeSimulation() {
    isRunning = true;
    qDebug() << "Simulation resumed";
}

void SimulationController::updateRobots() {
    qDebug() << "Updating robots...";

    if (robots.empty()) {
        qDebug() << "robots vector is empty!";
        return;
    }

    for (Robot& robot : robots)
    {
        qDebug() << "Updating robot position...";
        robot.updatePos();
    }

    QTimer::singleShot(33, this, &SimulationController::updateRobots);
    emit robotPositionsUpdated();
}
