#include "Obstacle.h"

// xhruzs00

Obstacle::Obstacle(Vector2D pos) : pos(pos) {}
Obstacle::Obstacle(double x, double y) {
    pos.x = x;
    pos.y = y;
}
Obstacle::~Obstacle() {}

Vector2D Obstacle::getPos() { return pos; }

void Obstacle::setPos(Vector2D newPos) {
    pos = newPos;
}

