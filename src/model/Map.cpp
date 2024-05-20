#include "Map.h"

// xhruzs00

Map::Map() {}
Map::~Map() {}

void Map::SetSize(Vector2D newSize) {
    size = newSize;
}

Vector2D Map::GetSize() {
    return size;
}

std::vector<Robot>& Map::GetRobots() {
    return robots;
}

std::vector<Obstacle>& Map::GetObstacles() {
    return obstacles;
}

void Map::CreateRobot(Vector2D pos, Vector2D dir, double range, double rotation, bool rotateRight) {
    Robot newRobot(pos, dir, range, rotation, rotateRight);
    robots.emplace_back(newRobot);
}

void Map::CreateObstacle(Vector2D pos) {
    Obstacle newObstacle(pos);
    obstacles.emplace_back(newObstacle);
}

void Map::DeleteRobot(Vector2D pos) {
    robots.erase(std::remove_if(robots.begin(), robots.end(), [&pos](const Robot& robot) {
        return robot.GetPos() == pos;
    }), robots.end());
}

void Map::DeleteObstacle(Vector2D pos) {
    obstacles.erase(std::remove_if(obstacles.begin(), obstacles.end(), [&pos](const Obstacle& obstacle) {
        return obstacle.GetPos() == pos;
    }), obstacles.end());
}