#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <chrono>
#include <thread>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QCoreApplication>
#include "src/model/Obstacle.h"
#include "src/model/Robot.h"
#include "src/model/Map.h"
#include "src/view/SimulationMapView.h"

// xhruzs00

/**
 * @brief The SimulationController class controls and manages the robot simulation.
 *
 * This class is responsible for initializing the simulation, managing the simulation loop,
 * and handling interactions between various components like robots and the map.
 */
class SimulationController : public QObject {
    Q_OBJECT
public:
    SimulationController(Map &simulationMap, SimulationMapView &simulationView);
    ~SimulationController();

    void startSimulation();
    void pauseSimulation();
    void resumeSimulation();

public slots:
    void updateRobots();    

private:
    Map map;
    SimulationMapView mapView;
    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;

    bool isRunning;

signals:
    void robotPositionsUpdated();
};

#endif
