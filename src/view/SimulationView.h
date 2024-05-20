#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QDialog>
#include <QScreen>
#include <QMouseEvent>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGuiApplication>

#include "./src/controller/SimulationController.h"

// xsnope04

/**
 * @brief The SimulationView class represents the simulation view of the application.
 * 
 * This view provides a graphical representation of the simulation.
 * Screen is split into two columns on left scene with graphical representation of the map, on right various tools to edit map.
 * Users can interact with the simulation using various tools and mouse.
 */
class SimulationView : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Constructs a SimulationView object.
     * @param parent The parent widget.
     */
    explicit SimulationView(QWidget *parent = nullptr);

private slots:
    /**
     * @brief Updates the simulation.
     * 
     * This slot is used as a update loop and is called periodically by the timer to redraw the simulation state every 33ms.
     */
    void updateSimulation();

private:
    QGraphicsView *graphicsView; /**< The QGraphicsView for displaying the simulation scene. */
    QGraphicsScene *scene; /**< The QGraphicsScene containing the simulation elements. */
    QPushButton *startButton;  /**< The button to start the simulation. */
    QPushButton *stopButton;  /**< The button to stop the simulation. */
    QTimer *timer; /**< The timer for updating the simulation. */

    SimulationController controller; /**< The simulation controller. */
    Robot* flaggedRobot = (nullptr); /**< The flagged robot for user interaction. */

    /**
     * @brief Sets up the user interface elements.
     */
    void setupUI();

     /**
     * @brief Sets the size of the scene mased on map.
     * @param size The size of the map.
     */
    void setMapSize(Vector2D size);

    /**
     * @brief Shows Dialog to load map and sends filepath to controller.
     */
    void loadFile();

    /**
     * @brief Starts the simulation timer.
     */
    void startTimer();

    /**
     * @brief Stops the simulation timer.
     */
    void stopTimer();
    
    /**
     * @brief Redraws the scene.
     */
    void redrawScene();

    /**
     * @brief Draws obstacles on the scene.
     * @param obstacles The obstacles to draw.
     * 
     * Obstacles are drawn as a red boxes with 30x30 size, this size is static and cannot be changed.
     */
    void drawObstacles(const std::vector<Obstacle>& obstacles);

    /**
     * @brief Draws robots on the scene.
     * @param robots The robots to draw.
     * 
     * Robots are drawn as a blue circle with radius 10 that cannot be changd and with red sight in direction they are mooving.
     * Length of sight is based on detection range.
     */
    void drawRobots(const std::vector<Robot>& robots);

    /**
     * @brief Handles mouse press events.
     * @param event The mouse event.
     * 
     * Clicking on robot will flag it and robot can be then controlled using keyboard.
     * To deflag current robot, user can click on another robot or on empty space in map.
     */
    void mousePressEvent(QMouseEvent* event);

    /**
     * @brief Handles key press events.
     * @param event The key event.
     * 
     * - W  - forward
     * - S  - backward
     * - A  - turn left
     * - D  - turn right
     */
    void keyPressEvent(QKeyEvent* event);

    /**
     * @brief Handles close events.
     * @param event The close event.
     * 
     * This is a helping function to close view.
     */
    void closeEvent(QCloseEvent *event);

signals:
    /**
     * @brief Signal emitted when the simulation view is closed.
     */
    void closed();
};

#endif