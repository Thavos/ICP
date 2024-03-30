#include "SimulationController.h"

// xhruzs00

SimulationController::SimulationController() {}
SimulationController::~SimulationController() {}

void SimulationController::startSimulation() {
    isRunning = true;
    while (isRunning) {
        updateRobots();
        // Notify View
        std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
}

void SimulationController::pauseSimulation() {
    isRunning = false;
}

void SimulationController::resumeSimulation() {
    isRunning = true;
}

void SimulationController::updateRobots() {
    for (Robot& robot : robots)
    {
        robot.updatePos();
    }
    // Notify View 
}

void SimulationController::notifyView() {

}
