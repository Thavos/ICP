#include "Map.h"

// xhruzs00

Map::Map() {
    size.x = 0;
    size.y = 0;
}
Map::Map(double x, double y) {
    size.x = x;
    size.y = y;
}
Map::Map(Vector2D size) : size(size) {}
Map::~Map() {}

void Map::setSize(Vector2D setSize) {
    size.x = setSize.x;
    size.y = setSize.y;
}

void Map::setSize(double x, double y) {
    size.x = x;
    size.y = y;
}

void Map::setRobots(std::vector<Robot>&& newRobots) {
    robots = std::move(newRobots);
}

void Map::setObstacles(std::vector<Obstacle>&& newObstacles) {
    obstacles = std::move(newObstacles);
}

std::vector<Robot>* Map::getRobots() {
    return &robots;
}

std::vector<Obstacle>* Map::getObstacles() {
    return &obstacles;
}

void Map::addRobot(const Robot& newRobot) {
    robots.push_back(newRobot);
}

void Map::addObstacle(const Obstacle& newObstacle) {
    obstacles.push_back(newObstacle);
}

Vector2D Map::getSize() {
    return size;
}

void Map::moveRobot(const Vector2D& oldPos, const Vector2D& newPos) {
    for (Robot& robot : robots) {
        if (robot.getPos() == oldPos) {
            robot.setPos(newPos);
            return;
        }
    }
}

void Map::moveObstacle(const Vector2D& oldPos, const Vector2D& newPos) {
    for (Obstacle& obstacle : obstacles) {
        if (obstacle.getPos() == oldPos) {
            obstacle.setPos(newPos);
            return;
        }
    }
}
