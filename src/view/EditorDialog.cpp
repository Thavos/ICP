
#include "EditorDialog.h"

EditorDialog::EditorDialog(QWidget *parent) : QDialog(parent) {
    setupUI();
}

void EditorDialog::setupUI(){
    setWindowTitle("Map Editor");

    resize(1200, 1000); // Adjust the size according to your needs
    mapView = new EditorMapView(this);
    btnSave = new QPushButton("Save", this);
    btnAddObstacle = new QRadioButton("Add Obstacle", this);
    btnAddRobot = new QRadioButton("Add Robot", this);
    btnAddRobot->setChecked(true);
    modeBox = new QComboBox(this);
    modeBox->addItem("Placement Mode");
    modeBox->addItem("Editing Mode");
    mapName = new QLineEdit(this);
    btnUpdateRobotParams = new QPushButton("Update Robot Parameters", this);

    robotDirectionInput = new QLineEdit(this);
    detectionRangeInput = new QLineEdit(this);
    turningAngleInput = new QLineEdit(this);
    turningDirectionInput = new QComboBox(this);
    turningDirectionInput->addItem("Left");
    turningDirectionInput->addItem("Right");

    //Hint messages
    robotDirectionInput->setToolTip("Enter the direction of the robot here(degrees)");
    detectionRangeInput->setToolTip("Enter the detection range of the robot here");
    turningAngleInput->setToolTip("Enter the turning angle of the robot here(degrees)");

    mapName->setText("map");

    //Robot parameters starting values
    robotDirectionInput->setText("25");
    detectionRangeInput->setText("50");
    turningAngleInput->setText("45");

    //Robot parameters layout
    auto* robotParamsLayout = new QFormLayout();
    robotParamsLayout->addRow("Direction", robotDirectionInput);
    robotParamsLayout->addRow("Detection Range", detectionRangeInput);
    robotParamsLayout->addRow("Turning Direction", turningDirectionInput);
    robotParamsLayout->addRow("Turning Angle", turningAngleInput);
    robotParamsLayout->addRow(btnUpdateRobotParams);

    auto *groupRobotParams = new QGroupBox("Robot Parameters", this);
    groupRobotParams->setLayout(robotParamsLayout);


    //Layout to arrange the text edit and button
    auto *modeLayout = new QVBoxLayout();
    modeLayout->addWidget(btnAddRobot);
    modeLayout->addWidget(btnAddObstacle);
    modeLayout->addWidget(modeBox);

    auto *groupMode = new QGroupBox("Mode", this);
    groupMode->setLayout(modeLayout);

    //Layout for saving map

    auto* mapSaveLayout = new QFormLayout();
    mapSaveLayout->addRow("Map Name", mapName);
    mapSaveLayout->addRow(btnSave);

    auto* groupMapSave = new QGroupBox("Save Map", this);
    groupMapSave->setLayout(mapSaveLayout);

    //Layout for the left bar

    auto *verticalLayout = new QVBoxLayout();
    verticalLayout->addWidget(groupMode);
    verticalLayout->addWidget(groupRobotParams);
    verticalLayout->addWidget(groupMapSave);

    auto *layout = new QHBoxLayout();
    layout->addLayout(verticalLayout);
    layout->addWidget(mapView);
    setLayout(layout);

    // Connect the save button to the saveMap slot
    connect(btnSave, &QPushButton::clicked, [this]() {
        QString fileName = mapName->text();  // Define the QString value you want to pass
        exportMapToFile(fileName);
    });
    connect(btnAddRobot, &QRadioButton::toggled, [this](bool checked){
        if (checked) mapView->setEditMode("Robot");
    });
    connect(btnAddObstacle, &QRadioButton::toggled, [this](bool checked){
        if (checked) mapView->setEditMode("Obstacle");
    });
    connect(modeBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [=](int index) {
        QString mode = modeBox->itemText(index);
        printf("Selected mode: %s\n", mode.toStdString().c_str());
        mapView->setMode(mode);
    });
    connect(mapView, &EditorMapView::robotAdded, this, &EditorDialog::handleAddRobot);
    connect(mapView, &EditorMapView::obstacleAdded, this, &EditorDialog::handleAddObstacle);
    connect(mapView, &EditorMapView::robotPositionChanged, this, &EditorDialog::handleRobotPositionChanged);
    connect(mapView, &EditorMapView::obstaclePositionChanged, this, &EditorDialog::handleObstaclePositionChanged);
    connect(btnUpdateRobotParams, &QPushButton::clicked, [this](){
        updateRobotParams();
    });
}

RobotParams EditorDialog::getRobotParams() {
    Vector2D direction = directionVectorFromDegrees(robotDirectionInput->text().toDouble());
    double detectionRange = detectionRangeInput->text().toDouble();
    double turningAngle = turningAngleInput->text().toDouble();
    bool turningDirection = (turningDirectionInput->currentText() == "Right"); // Assuming "Left" represents true

    return RobotParams(direction, detectionRange, turningAngle, turningDirection);
}


Vector2D EditorDialog::directionVectorFromDegrees(double degrees) {
    // Convert degrees to radians
    double radians = qDegreesToRadians(degrees);

    // Calculate the x and y components of the direction vector using trigonometry
    double x = qCos(radians);
    double y = qSin(radians);

    return {x, y};
}

void EditorDialog::handleAddRobot(const QPointF &position) {
    RobotParams params = getRobotParams();
    QString turningDirection = params.turningDirection ? "right" : "left";
    double direction = directionToDegrees(params.direction);
    qDebug() << "Adding robot at position:" << position;
    qDebug() << "Robot Params: Direction: " << direction << ", Detection Range: " << params.detectionRange
             << ", Turning Angle: " << params.rotationAngle << ", Turning Direction: " << turningDirection;
    mapView->map->addRobot(Robot(params, Vector2D(position.x(), position.y())));
}

void EditorDialog::handleAddObstacle(const QPointF &position) {
    qDebug() << "Adding obstacle at position:" << position;
    mapView->map->addObstacle(Obstacle(Vector2D(position.x(), position.y())));
}

void EditorDialog::handleRobotPositionChanged(const Vector2D &newPos, const Vector2D &oldPos) {
    qDebug() << "Handling robot position change: (" << oldPos.x << ", " << oldPos.y << ") -> (" << newPos.x << ", " << newPos.y << ")";
    mapView->map->moveRobot(oldPos, newPos);
}

void EditorDialog::handleObstaclePositionChanged(const Vector2D &newPos, const Vector2D &oldPos) {
    qDebug() << "Handling obstacle position: (" << oldPos.x << ", " << oldPos.y << ") -> (" << newPos.x << ", " << newPos.y << ")";
    mapView->map->moveObstacle(oldPos, newPos);
}

void EditorDialog::updateRobotParams() {
    Robot *selectedRobot = mapView->getSelectedRobot();
    if (selectedRobot != nullptr) {
        qDebug() << "Selected robot old params: " << selectedRobot->getRotationAngle();
        qDebug() << "New params: " << getRobotParams().rotationAngle;
        selectedRobot->updateParameters(getRobotParams());

        QGraphicsEllipseItem* robotGraphics = mapView->findRobotItemByPosition(QPointF(selectedRobot->getPos().x, selectedRobot->getPos().y));

        if(robotGraphics){
            mapView->updateRobotDirection(selectedRobot, robotGraphics);
            robotGraphics->update();
        }
    }
}

void EditorDialog::exportMapToFile(const QString& fileName) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save Map", "Are you sure you want to save the map?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        // If the user clicked "No", do nothing
        return;
    }

    QDir appDir(QCoreApplication::applicationDirPath());

    appDir.cdUp();

    QString resourcesDirPath = appDir.filePath("resources");

    QString filePath = QDir(resourcesDirPath).filePath(fileName + ".txt");

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }

    // Open a QTextStream to write to the file
    QTextStream out(&file);

    // Write map size header
    out << "500x500\n\n";

    // Write robots
    out << "robots:\n";
    for (auto& robot : *(mapView->map->getRobots())) {
        const Vector2D& pos = robot.getPos();
        const double direction = directionToDegrees(robot.getDir());
        const double angle = robot.getRotationAngle();
        const double range = robot.getDetectionRange();
        const QString turningDirection = robot.getTurningDirection() ? "right" : "left";

        out << pos.x << ";" << pos.y << ";" << direction<< ";"
            << angle << ";" << range << ";" << turningDirection << "\n";
    }

    // Write obstacles
    out << "\nobstacles:\n";
    for (auto& obstacle : *(mapView->map->getObstacles())) {
        const Vector2D& pos = obstacle.getPos();
        out << pos.x << ";" << pos.y << "\n";
    }

    // Close the file
    file.close();
    this->close();
}

double EditorDialog::directionToDegrees(const Vector2D& direction) {
    double radians = std::atan2(direction.y, direction.x);
    double degrees = std::fmod(radians * 180.0 / M_PI + 360.0, 360.0); // Ensure the result is in the range [0, 360)
    return degrees;
}