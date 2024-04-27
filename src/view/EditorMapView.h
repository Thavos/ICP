#ifndef ICP_EDITORMAPVIEW_H
#define ICP_EDITORMAPVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QtMath>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem> // For robot representation
#include <QGraphicsRectItem>   // For obstacle representation
#include "src/model/Map.h"

class EditorMapView : public QGraphicsView {
    Q_OBJECT
public:
    explicit EditorMapView(QWidget *parent = nullptr);

    void setMode(const QString& mode);

    void setEditMode(const QString &mode);

    Vector2D directionVectorFromDegrees(double degrees);

    QString getMapDataAsString() const;

protected:
    // Override to handle mouse press events for placing items
    void mousePressEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;  // The scene where all items are displayed
    QString placementMode;       // Current editing mode
    QString mode;
    Map *map;               // The map being edited
    QPointF initialPos; // Initial position when dragging an item
    QPointF initialMousePos; // Initial mouse position when dragging an item
    QGraphicsItem *selectedItem = nullptr; // The currently selected item
    Robot *selectedRobot; // The currently selected item
    Obstacle *selectedObstacle; // The currently selected obstacle

    // Methods to handle adding robots/obstacles
    void addRobotAtPosition(const QPointF &pos, const double &direction, double detectionRange, double turningAngle, bool turningDirection);

    bool checkOverlap(const QGraphicsItem *ignoreItem, const QPointF& pos, const QSizeF& size) const;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void addObstacleAtPosition(const QPointF &pos);

    static void setItemColor(QGraphicsItem *item, const QColor &color);

    static void setBackItemColor(QGraphicsItem *item);
};


#endif //ICP_EDITORMAPVIEW_H
