#ifndef EDITORCONTROLLER_H
#define EDITORCONTROLLER_H

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
#include "src/util/Vector2D.h"

// xhruzs00

/**
 * @brief The EditorController class controls and manages the editing of the simulation environment.
 *
 * This class is responsible for handling user interactions related to editing the simulation environment,
 * including adding and removing robots and obstacles, as well as saving and loading the simulation state.
 */
class EditorController {
public:
    /**
     * @brief Constructs a new EditorController object.
     */
    EditorController();

    /**
     * @brief Destroys the EditorController object.
     */
    ~EditorController();
    
    /**
     * @brief Saves the current simulation state to a file.
     *
     * @param filePath The path to the file where the simulation state will be saved.
     */
    void SaveFile(QString filePath);

    /**
     * @brief Loads a simulation state from a file.
     *
     * @param filePath The path to the file containing the simulation state to load.
     */
    void LoadFile(QString filePath);

    /**
     * @brief Sets the size of the map.
     *
     * @param size The size of the map.
     */
    void SetMapSize(Vector2D size);

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

    /**
     * @brief Creates a new robot in the simulation environment.
     *
     * @param pos The position of the new robot.
     * @param angle The orientation angle of the new robot (in degrees).
     * @param range The detection range of the new robot.
     * @param rotation The rotation angle base of the new robot.
     * @param rotateRight The direction of rotation of the new robot.
     */
    void CreateRobot(Vector2D pos, double angle, double range, double rotation, bool rotateRight);
    
    /**
     * @brief Creates a new obstacle in the simulation environment.
     *
     * @param pos The position of the new obstacle.
     */
    void CreateObstacle(Vector2D pos);

    /**
     * @brief Deletes a robot from the simulation environment.
     *
     * @param pos The position of the robot to delete.
     */
    void DeleteRobot(Vector2D pos);

    /**
     * @brief Deletes an obstacle from the simulation environment.
     *
     * @param pos The position of the obstacle to delete.
     */
    void DeleteObstacle(Vector2D pos);

private:
    Map map;
};

#endif // EDITORCONTROLLER_H