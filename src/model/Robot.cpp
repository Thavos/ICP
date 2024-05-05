#include "Robot.h"

// xhruzs00

Robot::Robot(const Vector2D& pos)
    : pos(pos) {}

Robot::Robot(const RobotParams& params, const Vector2D& pos)
    : pos(pos), dir(params.direction), rotationAngle(params.rotationAngle), detectionRange(params.detectionRange), turningDirection(params.turningDirection) {}

Robot::~Robot() {}

void Robot::setPos(const Vector2D& newPos) { pos = newPos; }
void Robot::setDirection(const Vector2D& newDir) { dir = newDir; }

Vector2D Robot::getPos() { return pos; }
Vector2D Robot::getDir() { return dir; }

double Robot::getRotationAngle() { return rotationAngle; }
double Robot::getDetectionRange() { return detectionRange; }

bool Robot::getTurningDirection() { return turningDirection; }

void Robot::setRotationAngle(double newRotationAngle) { rotationAngle = newRotationAngle; }
void Robot::setDetectionRange(double newDetectionRange) { detectionRange = newDetectionRange; }
void Robot::setTurningDirection(bool newTurningDirection)  { turningDirection = newTurningDirection; }

void Robot::updateParameters(const RobotParams& params) {
    setRotationAngle(params.rotationAngle);
    setDetectionRange(params.detectionRange);
    setTurningDirection(params.turningDirection);
    setDirection(params.direction);
    qDebug() << "Robot parameters updated";
}



Vector2D Robot::updatePos() {
    Vector2D newPos = pos + dir * speed;
    return newPos;
}