#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "src/util/Vector2D.h"

// xhruzs00

/**
 * @brief The Robot class represents a robot in the simulation.
 *
 * This class stores the state and behavior of a robot. It can be observed
 * by other objects for changes in its state.
 */
class Robot {
public:
    //Robot(Vector2D pos, Vector2D dir);
    Robot(Vector2D pos, Vector2D dir, double rotationAngle, double detectionRange, bool turningDirection);
    ~Robot();

    void setPos(Vector2D newPos);
    void setDirection(Vector2D newDir);

    Vector2D getPos();
    Vector2D getDir();
    double getSpeed();
    double getRotationAngle();
    double getDetectionRange();
    double getTurningAngle();
    bool getTurningDirection();

    Vector2D updatePos();
    void updateParameters(double newRotationAngle, double newDetectionRange, double newTurningAngle, bool newTurningDirection);

private:
    Vector2D pos = Vector2D(), 
             dir = Vector2D();

    double rotationAngle;
    double detectionRange;
    bool turningDirection; // true = right, false = left
    double speed = 10;


    void setRotationAngle(double newRotationAngle);
    void setDetectionRange(double newDetectionRange);
    void setTurningDirection(bool newTurningDirection);
};

#endif