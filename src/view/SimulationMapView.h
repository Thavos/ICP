#ifndef MAPVIEW_H
#define MAPVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QDebug>
#include <memory>
#include "src/model/Map.h"

// xhruzs00

/**
 * @brief The SimulationMapView class provides a graphical view of the simulation map.
 *
 * This class is responsible for rendering the map and its elements, such as 
 * robots and obstacles, to the screen.
 */
class SimulationMapView : public QGraphicsView  {
    Q_OBJECT

public:
    /**
     * @brief Constructor for SimulationMapView.
     * @param parent The parent widget, default is nullptr.
     */
    explicit SimulationMapView(QWidget *parent = nullptr);
    explicit SimulationMapView(Map *mapPtr, QWidget *parent = nullptr);

    /**
     * @brief Destructor for SimulationMapView.
     */
    ~SimulationMapView() override;

    void setSimulationMap(Map *mapPtr);

    void populateScene();

//protected:
//    /**
//     * @brief Paint event handler for drawing the map.
//     * @param event The paint event.
//     */
//    void paintEvent(QPaintEvent *event) override;

private:
    QGraphicsScene* scene;
    Map *map;  // Pointer to the simulation map

public slots:
    void updateRobotPositions();
};

#endif
