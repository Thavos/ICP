#ifndef EDITORVIEW_H
#define EDITORVIEW_H

#include <QDir>
#include <QFile>
#include <QLabel>
#include <QScreen>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFormLayout>
#include <QMouseEvent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGraphicsView>
#include <QDoubleSpinBox>
#include <QGraphicsScene>
#include <QGuiApplication>
#include <QCoreApplication>

#include "./src/controller/EditorController.h"

// xsnope04

/**
 * @brief The EditorView class represents the editor view of the application.
 * 
 * This class provides a graphical interface for editing maps.
 */
class EditorView : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Constructs an EditorView object.
     * @param parent The parent widget.
     * @param fromExisting Flag indicating whether the editor is opened from an existing map.
     */
    explicit EditorView(QWidget *parent = nullptr, bool fromExisting = false);

private:
    QGraphicsView *graphicsView; /**< The QGraphicsView for displaying the editor scene. */
    QDoubleSpinBox *widthSpinBox; /**< The spin box for setting the width of map objects. */
    QDoubleSpinBox *heightSpinBox; /**< The spin box for setting the height of map objects. */
    EditorController controller; /**< The editor controller. */

    int mapWidth; /**< The width of the map. */
    int mapHeight; /**< The height of the map. */
    bool objectRobot = true; /**< Flag indicating whether the selected object is a robot. */
    double angle; /**< The angle of rotation for objects. */
    double range; /**< The range of vision for robots. */
    double rotation; /**< The rotation angle which robots can rotate per tick. */
    bool rotateRight = true; /**< Flag indicating the direction of rotation for robots is clockwise or counterclockwise. */
    bool addMode; /**< Flag indicating the mode we interact with map, either we add new object or we delete existing once. */

    /**
     * @brief Sets up the user interface elements.
     * 
     * Creates a two column view.
     * Left column is for graphical view of scene.
     * Right colum is for tools. 
     */
    void setupUI();

    /**
     * @brief Handles close events.
     * @param event The close event.
     * 
     * This is a helping function to close view.
     */
    void closeEvent(QCloseEvent *event);

    /**
     * @brief Adjusts the view size.
     * 
     * Redraws the size of scene based on input fields in tool panel.
     */
    void adjustViewSize();

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

private slots:
    /**
     * @brief Sets the width of the map based on input in the tool panel.
     * @param width The width of the object.
     */
    void setWidth(double width);

    /**
     * @brief Sets the height of the map based on input in the tool panel.
     * @param height The height of the object.
     */
    void setHeight(double height);

    /**
     * @brief Sets the object that will be placed or deleted to Robots (objectRobot).
     * 
     * @details
     * - true: Robot object
     */
    void setRobotObject();

    /**
     * @brief Sets the object that will be placed or deleted to Obstacles (objectRobot).
     * 
     * @details
     * - false: Obstacle object
     */
    void setObstacleObject();

    /**
     * @brief Updates the value of the initial angle for next robots that will be placed.
     * @param value The new value of the angle.
     */
    void updateAngle(double value);

    /**
     * @brief Updates the value of the detection range for next robots that will be placed.
     * @param value The new value of the range.
     */
    void updateRange(double value);

    /**
     * @brief Updates the rotation angle.
     * @param value The new value of the rotation speed.
     */
    void updateRotation(double value);

    /**
     * @brief Updates the direction of rotation (rotateRight).
     * @param index The index representing the direction.
     * 
     * @details
     * - 0: Index for clockwise turning (right)
     * - 1: Index for counterclockwise turning (left)
     */
    void updateRotationDirection(int index);

    /**
     * @brief Sets the mode for adding objects (addMode).
     * @param index The index representing the mode.
     * 
     * @details
     * - 0: Index for true, meaning we want to add objects to the map
     * - 1: Index for false, meaning we want to delete objects on the map
     */
    void setMode(int index);

    /**
     * @brief Saves the map configuration to a file.
     * 
     * Opens up a dialog to save the file. After selecting or creating a new file path,
     * this file path is sent to the controller, where writing to the file logic is implemented.
     */
    void saveFile();

    /**
     * @brief Loads a map configuration from a file.
     * 
     * Opens up a dialog to load the file. After selecting a file path,
     * this file path is sent to the controller, where reading from the file logic is implemented.
     */
    void loadFile();

signals:
    /**
     * @brief Signal emitted when the editor view is closed.
     */
    void closed();

protected:
    /**
     * @brief Handles mouse press events.
     * @param event The mouse event.
     * 
     * We filter out positions to be within scene.
     * Based on objectRobot and addMode we add/delete Robots/Obstacles from map.
     */
    void mousePressEvent(QMouseEvent *event) override;
};

#endif