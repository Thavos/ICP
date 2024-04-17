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


const std::vector<Robot>& Map::getRobots() const {
    return robots;
}

const std::vector<Obstacle>& Map::getObstacles() const {
    return obstacles;
}

void Map::setRobots(std::vector<Robot>&& setRobots) {
    robots = std::move(setRobots);
}

void Map::setObstacles(std::vector<Obstacle>&& setObstacles) {
    obstacles = std::move(setObstacles);
}

Vector2D Map::getSize() {
    return size;
}
