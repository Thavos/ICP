#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Obstacle.h"
#include "Robot.h"
#include "./src/util/Vector2D.h"

// xhruzs00

/**
 * @brief The Map class represents the simulation environment.
 *
 * This class stores the layout and properties of the simulation environment,
 * including obstacles and robots.
 */
class Map {
public:
    /**
     * @brief Constructs a new Map object.
     */
    Map();

    /**
     * @brief Destroys the Map object.
     */
    ~Map();

    /**
     * @brief Sets the size of the map.
     *
     * @param newSize The new size of the map.
     */
    void SetSize(Vector2D newSize);

    /**
     * @brief Gets the size of the map.
     *
     * @return Vector2D The size of the map.
     */
    Vector2D GetSize();

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
     * @brief Creates a new robot and adds it to the map.
     *
     * @param pos The position of the new robot.
     * @param dir The direction of the new robot.
     * @param range The detection range of the new robot.
     * @param rotation The rotation angle base of the new robot.
     * @param rotateRight The direction of rotation of the new robot.
     */
    void CreateRobot(Vector2D pos, Vector2D dir, double range, double rotation, bool rotateRight);
   
    /**
     * @brief Creates a new obstacle and adds it to the map.
     *
     * @param pos The position of the new obstacle.
     */
    void CreateObstacle(Vector2D pos);

    /**
     * @brief Deletes the robot at the specified position from the map.
     *
     * @param pos The position of the robot to delete.
     */
    void DeleteRobot(Vector2D pos);

    /**
     * @brief Deletes the obstacle at the specified position from the map.
     *
     * @param pos The position of the obstacle to delete.
     */
    void DeleteObstacle(Vector2D pos);

private:
    Vector2D size; /**< The size of the map. */
    std::vector<Robot> robots; /**< Vector containing robots. */
    std::vector<Obstacle> obstacles; /**< Vector containing obstacles. */
};

#endif
