#include "EditorView.h"

// xsnope04

EditorView::EditorView(QWidget *parent, bool fromExisting) : QWidget(parent) {
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    move(screenGeometry.center() - rect().center());

    setupUI();
    if(fromExisting == true){
        loadFile();
        redrawScene();
    }
}

void EditorView::setupUI() {
    graphicsView = new QGraphicsView(this);
    QGraphicsScene *graphicsScene = new QGraphicsScene(this);
    graphicsScene->setSceneRect(10, 10, 600, 600);
    graphicsView->setScene(graphicsScene);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(graphicsView);

    QWidget *toolPanel = new QWidget(this);
    QVBoxLayout *toolLayout = new QVBoxLayout(toolPanel);

    QLabel *widthLabel = new QLabel("Map Width:", toolPanel);
    widthSpinBox = new QDoubleSpinBox(toolPanel);
    widthSpinBox->setDecimals(0);
    widthSpinBox->setMinimum(100);
    widthSpinBox->setMaximum(1000);
    toolLayout->addWidget(widthLabel);
    toolLayout->addWidget(widthSpinBox);
    connect(widthSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &EditorView::setWidth);
    widthSpinBox->setValue(600);

    QLabel *heightLabel = new QLabel("Map Height:", toolPanel);
    heightSpinBox = new QDoubleSpinBox(toolPanel);
    heightSpinBox->setDecimals(0);
    heightSpinBox->setMinimum(100);
    heightSpinBox->setMaximum(1000);
    toolLayout->addWidget(heightLabel);
    toolLayout->addWidget(heightSpinBox);
    connect(heightSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &EditorView::setHeight);
    heightSpinBox->setValue(600);

    QLabel *modeLabel = new QLabel("Mode:", toolPanel);
    QComboBox *modeComboBox = new QComboBox(toolPanel);
    modeComboBox->addItem("Add");
    modeComboBox->addItem("Delete");
    toolLayout->addWidget(modeLabel);
    toolLayout->addWidget(modeComboBox);
    connect(modeComboBox, QOverload<int>::of(&QComboBox::activated), this, &EditorView::setMode);
    setMode(0);
    modeComboBox->setCurrentIndex(0);

    QButtonGroup *buttonGroup = new QButtonGroup(this);

    QRadioButton *robotButton = new QRadioButton("Robot", toolPanel);
    robotButton->setChecked(true);
    toolLayout->addWidget(robotButton);
    buttonGroup->addButton(robotButton);
    connect(robotButton, &QRadioButton::toggled, this, &EditorView::setRobotObject);

    QRadioButton *obstacleButton = new QRadioButton("Obstacle", toolPanel);
    toolLayout->addWidget(obstacleButton);
    buttonGroup->addButton(obstacleButton);
    connect(obstacleButton, &QRadioButton::toggled, this, &EditorView::setObstacleObject);

    // Robot Params
    QLabel *robotParamsLabel = new QLabel("Robot Parameters:", toolPanel);
    toolLayout->addWidget(robotParamsLabel);

    QLabel *angleLabel = new QLabel("Angle:", toolPanel);
    QDoubleSpinBox *angleSpinBox = new QDoubleSpinBox(toolPanel);
    angleSpinBox->setDecimals(2);
    angleSpinBox->setMinimum(0.0);
    angleSpinBox->setMaximum(360.0);
    toolLayout->addWidget(angleLabel);
    toolLayout->addWidget(angleSpinBox);
    connect(angleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &EditorView::updateAngle);
    angleSpinBox->setValue(0);

    QLabel *rangeLabel = new QLabel("Range:", toolPanel);
    QDoubleSpinBox *rangeSpinBox = new QDoubleSpinBox(toolPanel);
    rangeSpinBox->setDecimals(2);
    rangeSpinBox->setMinimum(0.0);
    rangeSpinBox->setMaximum(1000.0);
    toolLayout->addWidget(rangeLabel);
    toolLayout->addWidget(rangeSpinBox);
    connect(rangeSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &EditorView::updateRange);
    rangeSpinBox->setValue(10);

    QLabel *rotationAngleLabel = new QLabel("Rotation Angle:", toolPanel);
    QDoubleSpinBox *rotationAngleSpinBox = new QDoubleSpinBox(toolPanel);
    rotationAngleSpinBox->setDecimals(2);
    rotationAngleSpinBox->setMinimum(0.0);
    rotationAngleSpinBox->setMaximum(360.0);
    toolLayout->addWidget(rotationAngleLabel);
    toolLayout->addWidget(rotationAngleSpinBox);
    connect(rotationAngleSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged), this, &EditorView::updateRotation);
    rotationAngleSpinBox->setValue(10);

    QLabel *rotationDirectionLabel = new QLabel("Rotation Direction:", toolPanel);
    QComboBox *rotationDirectionComboBox = new QComboBox(toolPanel);
    rotationDirectionComboBox->addItem("Right");
    rotationDirectionComboBox->addItem("Left");
    toolLayout->addWidget(rotationDirectionLabel);
    toolLayout->addWidget(rotationDirectionComboBox);
    connect(rotationDirectionComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &EditorView::updateRotationDirection);
    rotationDirectionComboBox->setCurrentIndex(0);

    QPushButton *saveButton = new QPushButton("Save", toolPanel);
    toolLayout->addWidget(saveButton);
    connect(saveButton, &QPushButton::clicked, this, &EditorView::saveFile);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addLayout(mainLayout);
    layout->addWidget(toolPanel);
    setLayout(layout);
}

void EditorView::closeEvent(QCloseEvent *event) {
    QWidget::closeEvent(event);
    emit closed();
}

void EditorView::adjustViewSize() {
    Vector2D size(mapWidth, mapHeight);
    controller.SetMapSize(size);
    graphicsView->setFixedSize(mapWidth + 20, mapHeight + 20);
    graphicsView->scene()->setSceneRect(0, 0, mapWidth, mapHeight);
    redrawScene();
}

void EditorView::redrawScene() {
    graphicsView->scene()->clear();

    const std::vector<Obstacle>& obstacles = controller.GetObstacles();
    const std::vector<Robot>& robots = controller.GetRobots();

    drawObstacles(obstacles);
    drawRobots(robots);
}

void EditorView::drawObstacles(const std::vector<Obstacle>& obstacles) {
    for (const Obstacle& obstacle : obstacles) {
        Vector2D pos = obstacle.GetPos();
        graphicsView->scene()->addRect(pos.x - 15, pos.y - 15, 30, 30, QPen(), QBrush(Qt::red));
    }
}

void EditorView::drawRobots(const std::vector<Robot>& robots) {
    for (const Robot& robot : robots) {
        Vector2D pos = robot.GetPos();
        Vector2D endPos = robot.GetEndOfRange();
        graphicsView->scene()->addEllipse(pos.x - 10, pos.y - 10, 20, 20, QPen(), QBrush(Qt::blue));
        graphicsView->scene()->addLine(pos.x, pos.y, endPos.x, endPos.y, QPen(Qt::red));
    }
}

void EditorView::setWidth(double width) {
    mapWidth = width;
    adjustViewSize();
}

void EditorView::setHeight(double height) {
    mapHeight = height;
    adjustViewSize();
}

void EditorView::setRobotObject() {
    objectRobot = true;
}

void EditorView::setObstacleObject() {
    objectRobot = false;
}

void EditorView::updateAngle(double value) {
    angle = value;
}

void EditorView::updateRange(double value) {
    range = value;
}

void EditorView::updateRotation(double value) {
    rotation = value;
}

void EditorView::updateRotationDirection(int index) {
    rotateRight = (index == 0); // 0 is for "Right", 1 is for "Left"
}

void EditorView::setMode(int index) {
    addMode = (index == 0);
}

void EditorView::saveFile() {
    QString initialDir = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../examples");
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Map"), initialDir, tr("Text Files (*.txt)"));

    if (!filePath.isEmpty()) {
        controller.SaveFile(filePath);
    } else {
        qDebug() << "No file selected. Closing view...";
        close();
    }

    close();
}

void EditorView::loadFile() {
    QString initialDir = QDir::cleanPath(QCoreApplication::applicationDirPath() + "/../examples");
    QString filePath = QFileDialog::getOpenFileName(this, tr("Save Map"), initialDir, tr("Text Files (*.txt)"));

    if (!filePath.isEmpty()) {
        controller.LoadFile(filePath);
        Vector2D size = controller.GetMapSize();
        widthSpinBox->setValue(size.x);
        heightSpinBox->setValue(size.y);
        adjustViewSize();
    } else {
        qDebug() << "No file selected. Closing view...";
        close();
    }

    close();
}

void EditorView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPointF viewPos = event->pos();
        QPointF scenePos = graphicsView->mapToScene(viewPos.toPoint());
        if(scenePos.x() < 0 || scenePos.x() > mapWidth ||
           scenePos.y() < 0 || scenePos.y() > mapHeight)
           return;

        Vector2D pos(scenePos.x() - 10, scenePos.y() - 10);
        
        if(objectRobot == true) {
            if(addMode == true)
                controller.CreateRobot(pos, angle, range, rotation, rotateRight);
            else
                controller.DeleteRobot(pos);
        } else {
            if(addMode == true)
                controller.CreateObstacle(pos);
            else
                controller.DeleteObstacle(pos);
        }

        redrawScene();
    }

    QWidget::mousePressEvent(event);
}