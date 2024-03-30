#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <chrono>
#include <thread>
#include "src/model/Obstacle.h"
#include "src/model/Robot.h"
#include "src/model/Map.h"
#include "src/view/MapView.h"

// xhruzs00

/**
 * @brief The SimulationController class controls and manages the robot simulation.
 *
 * This class is responsible for initializing the simulation, managing the simulation loop,
 * and handling interactions between various components like robots and the map.
 */
class SimulationController {
public:
    SimulationController();
    ~SimulationController();

    void startSimulation();
    void pauseSimulation();
    void resumeSimulation();
    void updateRobots();
    void notifyView();

private:
    Map *simulationMap;
    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;

    bool isRunning;
};

#endif
