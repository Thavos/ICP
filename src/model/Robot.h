#ifndef ROBOT_H
#define ROBOT_H

#include <vector>
#include "src/util/Vector2D.h"
#include "src/model/RobotParams.h"

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
    Robot(const Vector2D& pos);


    Robot(const RobotParams& params, const Vector2D& pos);
    ~Robot();

    void setPos(const Vector2D& newPos);
    void setDirection(const Vector2D& newDir);

    Vector2D getPos();
    Vector2D getDir();
    double getSpeed();
    double getRotationAngle();
    double getDetectionRange();
    bool getTurningDirection();


    Vector2D updatePos();
    void updateParameters(const RobotParams& params);
private:
    Vector2D pos = Vector2D(), 
             dir = Vector2D();


    double rotationAngle;   //from 0 to 359 degrees
    double detectionRange;  //TODO: get to know some real values
    bool turningDirection; // true = right, false = left
    double speed = 10;


    void setRotationAngle(double newRotationAngle);
    void setDetectionRange(double newDetectionRange);
    void setTurningDirection(bool newTurningDirection);
};

#endif