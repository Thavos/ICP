#include "SimulationController.h"

// xhruzs00

SimulationController::SimulationController() {}
SimulationController::~SimulationController() {}

void SimulationController::ProcessFile(QString filePath) {
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

void SimulationController::update() {
    std::vector<Robot>& robots = map.GetRobots();
    std::vector<Obstacle>& obstacles = map.GetObstacles();

    Vector2D size = map.GetSize();

    for (Robot& robot : robots) {
        robot.UpdatePos(size, obstacles);
    }
}

Vector2D SimulationController::GetMapSize() {
    return map.GetSize();
}

std::vector<Robot>& SimulationController::GetRobots() {
    return map.GetRobots();
}

std::vector<Obstacle>& SimulationController::GetObstacles() {
    return map.GetObstacles();
}