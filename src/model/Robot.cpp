#include "Robot.h"

// xhruzs00

Robot::Robot(Vector2D pos, Vector2D dir, double range, double rotation, bool rotateRight) {
    this->pos = pos;
    this->dir = dir;
    this->range = range + 15;
    this->rotation = rotation;
    this->rotateRight = rotateRight;
}
Robot::~Robot() {}

void Robot::SetPos(Vector2D newPos) {
    pos = newPos;
}

Vector2D Robot::GetPos() const {
    return pos;
}

Vector2D Robot::GetDir() const {
    return dir;
}

Vector2D Robot::GetEndOfRange() const {
    return pos + dir * (range + 10);
}

double Robot::GetRange() const {
    return range;
}

double Robot::GetRotation() const {
    return rotation;
}

bool Robot::GetRotateRight() const {
    return rotateRight;
}

void Robot::UpdatePos(Vector2D mapSize, std::vector<Obstacle>& obstacles) {
    if (flag)
        return;

    Vector2D newPos = pos + dir * speed;
    if (Raycast(mapSize, obstacles)) {
        Rotate();
    } else if (newPos.x >= 0 && newPos.x <= mapSize.x && newPos.y >= 0 && newPos.y <= mapSize.y) {
        pos = newPos;
    } else {
        Rotate();
    }
}

bool Robot::Raycast(Vector2D mapSize, std::vector<Obstacle>& obstacles) {
    Vector2D endPoint = pos + dir.normalized() * range;

    for (Obstacle& obstacle : obstacles) {
        if (obstacle.Intersects(pos, endPoint)) {
            return true;
        }
    }

    if (endPoint.x < 5 || endPoint.x > mapSize.x - 5 || endPoint.y < 5 || endPoint.y > mapSize.y - 5) { // Robot is 10 radius therefore it cant go closer then 5 point from map edge
        return true;
    }

    return false;
}

bool Robot::RaycastBackward(Vector2D mapSize, std::vector<Obstacle>& obstacles) {
    Vector2D endPoint = pos - dir.normalized(); // We do not add the range here because we want to be able to hit walls with robot bodies

    for (Obstacle& obstacle : obstacles) {
        if (obstacle.Intersects(pos, endPoint)) {
            return true;
        }
    }

    if (endPoint.x < 5 || endPoint.x > mapSize.x - 5|| endPoint.y < 5 || endPoint.y > mapSize.y - 5) {
        return true;
    }

    return false;
}

void Robot::Rotate() {
    double angleRad;
    if(rotateRight) 
        angleRad = rotation * M_PI / 180.0;
    else 
        angleRad = -rotation * M_PI / 180.0;

    double cosAngle = cos(angleRad);
    double sinAngle = sin(angleRad);

    double newX = dir.x * cosAngle - dir.y * sinAngle;
    double newY = dir.x * sinAngle + dir.y * cosAngle;

    dir.x = newX;
    dir.y = newY;
}

void Robot::Rotate(bool right) {
    // Degrees to rad conversion, i truly should have added this into Vector2D at this point or stored it as a rad... well... to lazy to do it now *//::TODO::\\*
    double angleRad;
    if(right) 
        angleRad = rotation * M_PI / 180.0;
    else 
        angleRad = -rotation * M_PI / 180.0;

    double cosAngle = cos(angleRad);
    double sinAngle = sin(angleRad);

    double newX = dir.x * cosAngle - dir.y * sinAngle;
    double newY = dir.x * sinAngle + dir.y * cosAngle;
    
    dir.x = newX;
    dir.y = newY;
}

void Robot::SetFlag(bool setFlag) {
    flag = setFlag;
}

void Robot::Forward(Vector2D mapSize, std::vector<Obstacle>& obstacles) {
    Vector2D newPos = pos + dir * speed;
    if (Raycast(mapSize, obstacles) == false && 
        (newPos.x >= 0 && newPos.x <= mapSize.x && newPos.y >= 0 && newPos.y <= mapSize.y)) {
        pos = newPos;
    }
}

void Robot::Backward(Vector2D mapSize, std::vector<Obstacle>& obstacles) {
    Vector2D newPos = pos - dir * speed;
    if (RaycastBackward(mapSize, obstacles) == false && 
        (newPos.x >= 0 && newPos.x <= mapSize.x && newPos.y >= 0 && newPos.y <= mapSize.y)) {
        pos = newPos;
    }
}

void Robot::Left() {
    Rotate(false);
}

void Robot::Right() {
    Rotate(true);
}