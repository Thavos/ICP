#include "Robot.h"

// xhruzs00

//Robot::Robot(Vector2D pos, Vector2D dir) : pos(pos), dir(dir) {}
Robot::Robot(Vector2D pos, Vector2D dir, double rotationAngle, double detectionRange, bool turningDirection)
    : pos(pos), dir(dir), rotationAngle(rotationAngle), detectionRange(detectionRange), turningDirection(turningDirection){}
Robot::~Robot() {}

void Robot::setPos(Vector2D newPos) { pos = newPos; }
void Robot::setDirection(Vector2D newDir) { dir = newDir; }

Vector2D Robot::getPos() { return pos; }
Vector2D Robot::getDir() { return dir; }

double Robot::getRotationAngle() { return rotationAngle; }
double Robot::getDetectionRange() { return detectionRange; }
double Robot::getTurningAngle() { return turningAngle; }

bool Robot::getTurningDirection() { return turningDirection; }

void Robot::setRotationAngle(double newRotationAngle) { rotationAngle = newRotationAngle; }
void Robot::setDetectionRange(double newDetectionRange) { detectionRange = newDetectionRange; }

void Robot::setTurningAngle(double newTurningAngle) { turningAngle = newTurningAngle; }
void Robot::setTurningDirection(bool newTurningDirection)  { turningDirection = newTurningDirection; }

void Robot::updateParameters(double newRotationAngle, double newDetectionRange, double newTurningAngle, bool newTurningDirection) {
    Robot::setRotationAngle(newRotationAngle);
    Robot:: setDetectionRange(newDetectionRange);
    setTurningAngle(newTurningAngle);
    setTurningDirection(newTurningDirection);
}

Vector2D Robot::updatePos() {
    Vector2D newPos = pos + dir * speed;
    return newPos;
}