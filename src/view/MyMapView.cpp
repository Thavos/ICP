// #include "MyMapView.h"

// MyMapView::MyMapView(SimulationController* controller, Map* map, QWidget *parent)
//     : QWidget(parent), controller(controller), map(map) {}

// // void MyMapView::paintEvent(QPaintEvent* event) {
// //   QPainter painter(this);
// //   painter.setBrush(Qt::black);
// //   painter.drawRect(10, 10, 50, 50);
// // }

// // void MyMapView::drawMap(QPainter* painter) {
// //   painter->setBrush(Qt::gray);
// //   painter->drawRect(0, 0, 200, 200);
// // }

// void MyMapView::paintEvent(QPaintEvent* event) {
//   QWidget::paintEvent(event); // Call base class paintEvent

//   QPainter painter(this);

//   // Draw the map
//   drawMap(&painter);

//   // Draw the robots
//   drawRobot(&painter);

//   // Draw obstacles
//   drawObstacles(&painter);
// }

// void MyMapView::drawMap(QPainter* painter) {
//   // Set brush and pen for the map background
//   painter->setBrush(Qt::lightGray);
//   painter->setPen(Qt::black);

//   // Draw a rectangle representing the map area based on width and height
//   painter->drawRect(0, 0, map->getSize().x, map->getSize().y);
// }

// void MyMapView::drawRobot(QPainter* painter) {
//   std::vector<Robot> robots = map->getRobots();
//   for(Robot robot : robots) {
//     // Get robot position (x, y) and orientation (angle in radians)
//     Vector2D pos = robot.getPos();
//     double angle = robot.getDir().getRotation();

//     // Set pen for robot circle
//     painter->setPen(Qt::blue);

//     // Default robot size
//     double robotRadius = 5;

//     // Translate and rotate the coordinate system based on robot position and angle
//     painter->translate(pos.x, pos.y);
//     painter->rotate(angle * 180 / M_PI); // Convert radians to degrees for Qt painter

//     // Draw the robot as a circle
//     painter->drawEllipse(-robotRadius, -robotRadius, 2 * robotRadius, 2 * robotRadius);   
//   }
// }

// void MyMapView::drawObstacles(QPainter* painter) {
//   std::vector<Obstacle> obstacles = map->getObstacles();
//   for(Obstacle obstacle : obstacles) {
//     // Get obstacle position
//     Vector2D pos = obstacle.getPos();

//     double size = 20; // 20 being default

//     // Set pen for obstacle rectangle
//     painter->setPen(Qt::red);

//     // Translate and rotate the coordinate system based on obstacle position and angle
//     painter->save();
//     painter->translate(pos.x, pos.y);

//     // Draw the obstacle as a rotated rectangle
//     painter->drawRect(-size / 2, -size / 2, size, size);

//     // Restore previous painter state
//     painter->restore();
//   }
// }