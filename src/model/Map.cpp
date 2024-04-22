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

Vector2D Map::getSize() {
    return size;
}
