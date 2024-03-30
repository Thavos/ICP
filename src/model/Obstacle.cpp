#include "Obstacle.h"

// xhruzs00

Obstacle::Obstacle(Vector2D pos) : pos(pos) {}
Obstacle::~Obstacle() {}

Vector2D Obstacle::getPos() { return pos; }

