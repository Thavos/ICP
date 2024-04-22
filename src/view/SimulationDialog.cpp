#include "SimulationDialog.h"


SimulationDialog::SimulationDialog(QWidget *parent)
    : QDialog(parent),
      map(1000.0, 1000.0),
      view(this, map),   
      controller(map, view) {
    setWindowTitle("Simulation");

    loadFile();
    view.resizeView();

    playButton = new QPushButton("Play", this);
    stopButton = new QPushButton("Stop", this);
    menuButton = new QPushButton("Menu", this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(playButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(stopButton, 0, Qt::AlignCenter);
    buttonLayout->addWidget(menuButton, 0, Qt::AlignCenter);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(&view);
    mainLayout->addLayout(buttonLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);

    connect(playButton, &QPushButton::clicked, this, &SimulationDialog::startSimulation);
    connect(stopButton, &QPushButton::clicked, this, &SimulationDialog::stopSimulation);
    connect(menuButton, &QPushButton::clicked, this, &SimulationDialog::closeWindow);


    // Vector2D pos1(30.0, 200.0), dir1(1.0, 0.0);
    // Vector2D pos2(200.0, 30.0), dir2(-1.0, 0.0);
    // Vector2D pos3(50.0, 50.0), dir3(1.0, 0.0);
    // Vector2D pos4(100.0, 100.0), dir4(-1.0, 0.0);
    // Vector2D pos5(150.0, 150.0), dir5(1.0, 0.0);
    // Vector2D pos6(200.0, 200.0), dir6(-1.0, 0.0);

    // std::vector<Robot> robots;
    // robots.emplace_back(pos1, dir1);
    // robots.emplace_back(pos2, dir2);

    // std::vector<Obstacle> obstacles;
    // obstacles.emplace_back(pos3);
    // obstacles.emplace_back(pos4);
    // obstacles.emplace_back(pos5);
    // obstacles.emplace_back(pos6);

    // map.setRobots(std::move(robots));
    // map.setObstacles(std::move(obstacles));

    // QVBoxLayout *layout = new QVBoxLayout(this);
    // layout->addWidget(view.viewport());
    // setLayout(layout);

    // controller.startSimulation();
}

SimulationDialog::~SimulationDialog() {  }

void SimulationDialog::startSimulation() {
    controller.resumeSimulation();
}

void SimulationDialog::stopSimulation() {
    controller.pauseSimulation();
}

void SimulationDialog::closeWindow() {
    controller.pauseSimulation();
    close();
}

void SimulationDialog::loadFile() {
    Vector2D size;
    std::vector<Robot> robots;
    std::vector<Obstacle> obstacles;

    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt)"));
    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly)) {
            QTextStream in(&file);
            // get map
            QString firstLine = in.readLine();
            QStringList sizeParts = firstLine.split("x", QString::SkipEmptyParts);
            if (sizeParts.size() == 2) {
                bool ok;
                size.x = sizeParts[0].toDouble(&ok);
                if(!ok) qDebug() << "Error opening file";
                
                size.y = sizeParts[1].toDouble(&ok);
                if(!ok) qDebug() << "Error opening file";
            }

            // get robots
            while (!firstLine.isNull() && !firstLine.startsWith("robots:"))
                firstLine = in.readLine();

            while (!in.atEnd()) {
                QString line = in.readLine();
                if (line.isEmpty() || line.startsWith("obstacles:")) break;
                QStringList parts = line.split(";", QString::SkipEmptyParts);
                if (parts.size() == 7) {
                    double posX = parts[0].toDouble();
                    double posY = parts[1].toDouble();
                    double dirX = parts[2].toDouble();
                    double dirY = parts[3].toDouble();
                    double angle = parts[4].toDouble();
                    double range = parts[5].toDouble();
                    double speed = parts[6].toDouble();

                    Vector2D pos(posX, posY);
                    Vector2D dir(dirX, dirY);

                    Robot robot(pos, dir, angle, range, speed);
                    robots.emplace_back(robot);

                    qDebug() << "x: " << pos.x << " | y: " << pos.y;
                }
            }

            // get obstacles
            while (!firstLine.isNull() && !firstLine.startsWith("obstacles:"))
                firstLine = in.readLine();

            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList parts = line.split(";", QString::SkipEmptyParts);
                if (parts.size() == 2) {
                    double posX = parts[0].toDouble();
                    double posY = parts[1].toDouble();

                    Obstacle obstacle(posX, posY);
                    obstacles.emplace_back(obstacle);
                }
                qDebug() << "obstacle";
            }
        } 
        else
          qDebug() << "Error opening file";
    }

    map.setSize(size);
    map.setRobots(std::move(robots));
    map.setObstacles(std::move(obstacles));

    qDebug() << "map x:" << map.getSize().x << " y:" << map.getSize().y;
}