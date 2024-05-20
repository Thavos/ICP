#include "Obstacle.h"

// xhruzs00

Obstacle::Obstacle(Vector2D pos) : pos(pos) {}
Obstacle::~Obstacle() {}

Vector2D Obstacle::GetPos() const {
    return pos;
}

bool Obstacle::Intersects(Vector2D start, Vector2D end) {
    // Bounding box + some offset
    double minX = pos.x - 23; 
    double minY = pos.y - 23; 
    double maxX = pos.x + 23;
    double maxY = pos.y + 23;

    // Check for intersections
    if (start.x >= minX && start.x <= maxX && start.y >= minY && start.y <= maxY) {
        return true;
    }
    if (end.x >= minX && end.x <= maxX && end.y >= minY && end.y <= maxY) {
        return true;
    }


    // Prepare corners of edges
    Vector2D corners[] = {
        Vector2D(pos.x - 23, pos.y - 23),  // Top-Left 
        Vector2D(pos.x + 23, pos.y - 23),  // Top-Right 
        Vector2D(pos.x + 23, pos.y + 23),  // Bottom-Right 
        Vector2D(pos.x - 23, pos.y + 23),  // Bottom-Left 
        Vector2D(pos.x - 23, pos.y - 23)   // Top-Left - just to close loop so we can comfortably loop through this
    };

    for (int i = 0; i < 4; ++i) {
        // Create a edge
        Vector2D edgeStart = corners[i];
        Vector2D edgeEnd = corners[i + 1];

        // Check if our raycast line intersects the edge
        if (LineIntersects(start, end, edgeStart, edgeEnd)) {
            return true;
        }
    }

    return false;
}

bool Obstacle::LineIntersects(Vector2D start1, Vector2D end1, Vector2D start2, Vector2D end2) {
    // Get the dir of the vecotrs so we can calculate dot product
    Vector2D dir1 = end1 - start1;
    Vector2D dir2 = end2 - start2;

    // Calculate dot product
    double dot = dir1.Cross(dir2);

    // When dot product is zero line are paralel
    if (dot == 0) {
        return false;
    }

    // Get the parameters so we can rule out if they are crossing
    double t1 = ((start2.x - start1.x) * dir2.y - (start2.y - start1.y) * dir2.x) / dot;
    double t2 = ((start2.x - start1.x) * dir1.y - (start2.y - start1.y) * dir1.x) / dot;

    // If both parameters are in between of <0; 1> they are not crossing, otherwise they crossed 
    return (t1 >= 0 && t1 <= 1 && t2 >= 0 && t2 <= 1);
}