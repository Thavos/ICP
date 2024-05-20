#ifndef SIMULATIONCONTROLLER_H
#define SIMULATIONCONTROLLER_H

#include <vector>
#include <fstream>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>

#include "src/model/Map.h"
#include "src/model/Obstacle.h"
#include "src/model/Robot.h"

// xhruzs00

/**
 * @brief The SimulationController class controls and manages the robot simulation.
 *
 * This class is responsible for initializing the simulation, managing the simulation loop,
 * and handling interactions between various components like robots and the map.
 */
class SimulationController {
public:
    /**
     * @brief Constructs a new SimulationController object.
     */
    SimulationController();

    /**
     * @brief Destroys the SimulationController object.
     */
    ~SimulationController();  

    /**
     * @brief Processes a file containing simulation data.
     *
     * Reads the data from the specified file and initializes the simulation environment.
     *
     * @param filePath The path to the file containing simulation data.
     */
    void ProcessFile(QString filePath);

    /**
     * @brief Updates the simulation state.
     *
     * This function is called periodically to update the positions of robots and handle interactions.
     */
    void update();

    /**
     * @brief Gets the size of the map.
     *
     * @return Vector2D The size of the map.
     */
    Vector2D GetMapSize();

    /**
     * @brief Gets a reference to the vector containing robots.
     *
     * @return std::vector<Robot>& A reference to the vector containing robots.
     */
    std::vector<Robot>& GetRobots();

    /**
     * @brief Gets a reference to the vector containing obstacles.
     *
     * @return std::vector<Obstacle>& A reference to the vector containing obstacles.
     */
    std::vector<Obstacle>& GetObstacles();

private:
    Map map; /**< The simulation map. */
};

#endif
