#include "Map.h"

#include <utility>

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


void Map::setRobots(std::vector<Robot> robotsVec) {
    robots = std::move(robotsVec);
}

void Map::setObstacles(std::vector<Obstacle> obstacleVec) {
    obstacles = std::move(obstacleVec);
}

std::vector<Robot> Map::getRobots() {
    return robots;
}

std::vector<Obstacle> Map::getObstacles() {
    return obstacles;
}

Vector2D Map::getSize() {
    return size;
}
