#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include <cmath>
#include <QDebug>

#include "./src/util/Vector2D.h"
#include "Obstacle.h"

// xhruzs00

/**
 * @brief The Robot class represents a robot in the simulation.
 *
 * This class creates, stores and edits the state and behavior of a robot.
 */
class Robot {
public:
    /**
     * @brief Constructs a new Robot object.
     *
     * @param pos Initial position of the robot.
     * @param dir Initial direction of the robot.
     * @param range Detection range of the robot.
     * @param rotation Rotation angle of the robot.
     * @param rotateRight Rotation direction of the robot.
     */
    Robot(Vector2D pos, Vector2D dir, double range, double rotation, bool rotateRight);
    
    /**
     * @brief Destroys the Robot object.
     */
    ~Robot();

    /**
     * @brief Sets the position of the robot.
     *
     * @param newPos New position of the robot.
     */
    void SetPos(Vector2D newPos);

    /**
     * @brief Gets the position of the robot.
     *
     * @return Vector2D Current position of the robot.
     */
    Vector2D GetPos() const;

    /**
     * @brief Gets the direction of the robot.
     *
     * @return Vector2D Current direction of the robot.
     */
    Vector2D GetDir() const;

    /**
     * @brief Gets the end point of the detection range of the robot.
     *
     * @return Vector2D End point of the detection range.
     */
    Vector2D GetEndOfRange() const;

    /**
     * @brief Gets the detection range of the robot.
     *
     * @return double Current detection range of the robot.
     */
    double GetRange() const;

    /**
     * @brief Gets the rotation angle of the robot.
     *
     * @return double Current rotation angle of the robot.
     */
    double GetRotation() const;

    /**
     * @brief Gets the rotation direction of the robot.
     *
     * @return true if the robot rotates right, false otherwise.
     */
    bool GetRotateRight() const;

    /**
     * @brief Updates the position of the robot based on its current state.
     *
     * @param mapSize Size of the map.
     * @param obstacles List of obstacles on the map.
     */
    void UpdatePos(Vector2D mapSize, std::vector<Obstacle>& obstacles);

    /**
     * @brief Performs raycasting to detect obstacles in front of the robot.
     *
     * @param mapSize Size of the map.
     * @param obstacles List of obstacles on the map.
     * @return true if an obstacle is detected, false otherwise.
     */
    bool Raycast(Vector2D mapSize, std::vector<Obstacle>& obstacles);
    
    /**
     * @brief Performs raycasting to detect obstacles behind the robot.
     *
     * @param mapSize Size of the map.
     * @param obstacles List of obstacles on the map.
     * @return true if an obstacle is detected, false otherwise.
     */
    bool RaycastBackward(Vector2D mapSize, std::vector<Obstacle>& obstacles);

    /**
     * @brief Rotates the robot based on its rotation angle and direction.
     */
    void Rotate();

    /**
     * @brief Rotates the robot either clockwise or counterclockwise.
     *
     * @param right If true, rotates the robot clockwise; otherwise, counterclockwise.
     */
    void Rotate(bool right);

    /**
     * @brief Sets the flag indicating whether the robot is controlled by the user.
     *
     * @param setFlag If true, sets the flag; otherwise, clears it.
     */
    void SetFlag(bool setFlag);

    /**
     * @brief Moves the robot forward.
     *
     * @param mapSize Size of the map.
     * @param obstacles List of obstacles on the map.
     */
    void Forward(Vector2D mapSize, std::vector<Obstacle>& obstacles);
    
    /**
     * @brief Moves the robot backward.
     *
     * @param mapSize Size of the map.
     * @param obstacles List of obstacles on the map.
     */
    void Backward(Vector2D mapSize, std::vector<Obstacle>& obstacles);
    
    /**
     * @brief Rotates the robot counterclockwise.
     */
    void Left();
    
    /**
     * @brief Rotates the robot clockwise.
     */
    void Right();

private:
    Vector2D pos = Vector2D::zero;  /**< The position of the robot. */
    Vector2D dir = Vector2D::zero;  /**< The direction of the robot. */

    double range = 10;              /**< The detection range of the robot. */
    double rotation = 10;           /**< The rotation angle of the robot. */
    bool rotateRight = true;        /**< The direction of rotation of the robot. */
    double speed = 1;               /**< The movement speed of the robot. */

    bool flag = false;              /**< Flag indicating if the robot is controlled by the user. */

};

#endif