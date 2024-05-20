#include "EditorController.h"

// xhruzs00

EditorController::EditorController() {}
EditorController::~EditorController() {}

void EditorController::SaveFile(QString filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        // Write map size
        Vector2D size = map.GetSize();
        out << size.x << "x" << size.y << endl;


        // Write robots
        out << endl; // empty line in between
        out << "robots:" << endl;
        for (const auto& robot : map.GetRobots()) {
            Vector2D pos = robot.GetPos();
            Vector2D dir = robot.GetDir();
            double angle = atan2(dir.y, dir.x) * 180 / M_PI; // Convert radians to degrees
            out << pos.x << ";" << pos.y << ";" << angle << ";" << robot.GetRange() << ";" << robot.GetRotation() << ";" << (robot.GetRotateRight() ? "right" : "left") << endl;
        }

        // Write obstacles
        out << endl; // empty line in between
        out << "obstacles:" << endl;
        for (const auto& obstacle : map.GetObstacles()) {
            Vector2D pos = obstacle.GetPos();
            out << pos.x << ";" << pos.y << endl;
        }

        file.close();
    } else {
        qDebug() << "Failed to open file for writing:" << filePath;
    }
}

void EditorController::LoadFile(QString filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        QTextStream in(&file);
        while (!in.atEnd()) {
            
            // parse map
            Vector2D size = Vector2D::zero;
            QString firstLine = in.readLine();
            QStringList sizeParts = firstLine.split("x", QString::SkipEmptyParts);
            for (auto& part : sizeParts) {
                part = part.trimmed();
            }
            if (sizeParts.size() == 2) { // format : width x height
                bool ok;
                size.x = sizeParts[0].toDouble(&ok);
                if(!ok) qDebug() << "Error opening file";
                
                size.y = sizeParts[1].toDouble(&ok);
                if(!ok) qDebug() << "Error opening file";
            }
            map.SetSize(size);

            // parse robots
            while (!firstLine.isNull() && !firstLine.startsWith("robots:"))
                firstLine = in.readLine();

            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line.isEmpty() || line.startsWith("obstacles:")) break; // break on end document or obstacles

                QStringList parts = line.split(";", QString::SkipEmptyParts);

                for (auto& part : sizeParts)
                    part = part.trimmed();

                if (parts.size() == 6) { // format : posX ; posY ; anngle in deg ; detection range ; rotation angle base ; turning direction
                    Vector2D pos;
                    pos.x = parts[0].toDouble();
                    pos.y = parts[1].toDouble();

                    Vector2D dir;
                    double rad = parts[2].toDouble() * M_PI / 180;
                    dir.x = cos(rad);
                    dir.y = sin(rad);
                    double magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);
                    dir.x /= magnitude;
                    dir.y /= magnitude;

                    double range = parts[3].toDouble();
                    double rotation = parts[4].toDouble();
                    bool rotateRight = parts[5].toStdString() == "right" ? true : false;

                    map.CreateRobot(pos, dir, range, rotation, rotateRight);
                }
            }

            // get obstacles
            while (!firstLine.isNull() && !firstLine.startsWith("obstacles:"))
                firstLine = in.readLine();

            while (!in.atEnd()) { // format : posX ; posY
                QString line = in.readLine();
                QStringList parts = line.split(";", QString::SkipEmptyParts);
                for (auto& part : sizeParts)
                    part = part.trimmed();

                if (parts.size() == 2) {
                    Vector2D pos = Vector2D::zero;
                    pos.x = parts[0].toDouble();
                    pos.y = parts[1].toDouble();

                    map.CreateObstacle(pos);
                }
            }
        }
        file.close();
    } else {
        qDebug() << "Failed to open file:" << filePath;
    }
}

void EditorController::SetMapSize(Vector2D size) {
    map.SetSize(size);
}

Vector2D EditorController::GetMapSize() {
    return map.GetSize();
}

std::vector<Robot>& EditorController::GetRobots() {
    return map.GetRobots();
}

std::vector<Obstacle>& EditorController::GetObstacles() {
    return map.GetObstacles();
}

void EditorController::CreateRobot(Vector2D pos, double angle, double range, double rotation, bool rotateRight) {
    Vector2D dir = Vector2D::zero;
    double rad = angle * M_PI / 180;
    dir.x = cos(rad);
    dir.y = sin(rad);
    double magnitude = sqrt(dir.x * dir.x + dir.y * dir.y);
    dir.x /= magnitude;
    dir.y /= magnitude;
    
    map.CreateRobot(pos, dir, range, rotation, rotateRight);
}

void EditorController::CreateObstacle(Vector2D pos) {
    map.CreateObstacle(pos);
}

void EditorController::DeleteRobot(Vector2D pos) {
    std::vector<Robot> robots = map.GetRobots();

    for (Robot& robot : robots) {
        Vector2D robotPos = robot.GetPos();
        if (Vector2D::Distance(robotPos, pos) <= 10) {
            map.DeleteRobot(robotPos);
            return;
        }
    }
}

void EditorController::DeleteObstacle(Vector2D pos) {
    std::vector<Obstacle> obstacles = map.GetObstacles();

    for (Obstacle& obstacle : obstacles) {
        Vector2D obstaclePos = obstacle.GetPos();
        if (Vector2D::Distance(obstaclePos, pos) <= 15) {
            map.DeleteObstacle(obstaclePos);
            return;
        }
    }
}