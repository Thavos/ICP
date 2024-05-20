#include "SimulationView.h"

// xsnope04
// some functions - xrhuzs00

SimulationView::SimulationView(QWidget *parent) : QWidget(parent) {
    setFixedSize(200, 200);
    setupUI();
    loadFile();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &SimulationView::updateSimulation);

    connect(startButton, &QPushButton::clicked, this, &SimulationView::startTimer);
    connect(stopButton, &QPushButton::clicked, this, &SimulationView::stopTimer);
    connect(this, &SimulationView::keyPressEvent, this, &SimulationView::keyPressEvent);
}

void SimulationView::setupUI() {
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    graphicsView = new QGraphicsView();
    graphicsView->setFixedSize(200, 200);
    scene = new QGraphicsScene();
    graphicsView->setScene(scene);
    mainLayout->addWidget(graphicsView, 4);

    startButton = new QPushButton("Start");
    stopButton = new QPushButton("Stop");

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(stopButton);

    mainLayout->addLayout(buttonLayout, 1);
    setLayout(mainLayout);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    move(screenGeometry.center() - rect().center());
}

void SimulationView::updateSimulation() {
    controller.update();
    redrawScene();
}

void SimulationView::setMapSize(Vector2D size) {
    int padding = 20;
    int buttonPadding = 50;

    graphicsView->setFixedSize(size.x + padding / 2, size.y + padding / 2);
    scene->setSceneRect(0, 0, size.x, size.y);
    setFixedSize(size.x + padding, size.y + padding + buttonPadding);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    move(screenGeometry.center() - rect().center());
}

void SimulationView::loadFile() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Map Files (*.txt)"));
    if (!filePath.isEmpty()) {

        // read map size to set graphics view and window size
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
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

            setMapSize(size);
        }

        // pass file to controller for further processing
        controller.ProcessFile(filePath);
    } else {
        qDebug() << "No file selected. Closing view...";
        close();
    }
}

void SimulationView::startTimer() { //xhruzs00
    timer->start(33);
}

void SimulationView::stopTimer() { //xhruzs00
    timer->stop();
}

void SimulationView::redrawScene() {
    graphicsView->scene()->clear();

    const std::vector<Obstacle>& obstacles = controller.GetObstacles();
    const std::vector<Robot>& robots = controller.GetRobots();

    drawObstacles(obstacles);
    drawRobots(robots);
}

void SimulationView::drawObstacles(const std::vector<Obstacle>& obstacles) {
    for (const Obstacle& obstacle : obstacles) {
        Vector2D pos = obstacle.GetPos();
        graphicsView->scene()->addRect(pos.x - 15, pos.y - 15, 30, 30, QPen(), QBrush(Qt::red));
    }
}

void SimulationView::drawRobots(const std::vector<Robot>& robots) {
    for (const Robot& robot : robots) {
        Vector2D pos = robot.GetPos();
        Vector2D range = robot.GetEndOfRange();
        graphicsView->scene()->addEllipse(pos.x - 10, pos.y - 10, 20, 20, QPen(), QBrush(Qt::blue));
        graphicsView->scene()->addLine(pos.x, pos.y, range.x, range.y, QPen(Qt::red));
    }
}

void SimulationView::mousePressEvent(QMouseEvent* event) { //xhruzs00
    // Call the base class implementation of mousePressEvent to handle default behavior
    QWidget::mousePressEvent(event);

    // Convert the mouse position to scene coordinates
    QPointF scenePos = graphicsView->mapToScene(event->pos());

    // Flag only the first robot found
    bool robotFlagged = false;
    std::vector<Robot>& robots = controller.GetRobots();
    for (Robot& robot : robots) {
        Vector2D pos = robot.GetPos();
        QRectF boundingRect(pos.x - 10, pos.y - 10, 50, 50); // Assuming robot ellipses have a bounding rectangle of size 20x20


        // Check if the mouse click falls within the bounding rectangle of the current robot
        if (boundingRect.contains(scenePos)) {
            // Flag the clicked robot
            if (flaggedRobot) {
                flaggedRobot->SetFlag(false); // Clear flag status of the previously flagged robot
            }
            flaggedRobot = &robot; // Set the currently flagged robot
            flaggedRobot->SetFlag(true); // Set flag status of the clicked robot
            robotFlagged = true;
            break; // Exit the loop after flagging the first robot
        }
    }

    // Clear flag status if no robot was flagged
    if (!robotFlagged && flaggedRobot) {
        flaggedRobot->SetFlag(false);
        flaggedRobot = nullptr;
    }
}

void SimulationView::keyPressEvent(QKeyEvent* event) { //xhruzs00
    // Call the base class implementation to handle default behavior
    QWidget::keyPressEvent(event);

    // Check if a robot is currently flagged
    if (flaggedRobot) {
        Vector2D size = controller.GetMapSize();
        std::vector<Obstacle>& obstacles = controller.GetObstacles();

        // Update the position based on the pressed key
        switch (event->key()) {
            case Qt::Key_W:
                flaggedRobot->Forward(size, obstacles);
                break;
            case Qt::Key_A:
                flaggedRobot->Left();
                break;
            case Qt::Key_S:
                flaggedRobot->Backward(size, obstacles);
                break;
            case Qt::Key_D:
                flaggedRobot->Right();
                break;
            default:
                return;
        }

        // Redraw the scene to reflect the updated position
        redrawScene();
    }
}

void SimulationView::closeEvent(QCloseEvent *event) { //xhruzs00
    QWidget::closeEvent(event);
    emit closed();
}