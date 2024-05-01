#ifndef ICP_EDITORMAPVIEW_H
#define ICP_EDITORMAPVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QtMath>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem> // For robot representation
#include <QGraphicsRectItem>   // For obstacle representation
#include "src/model/Map.h"

class EditorDialog;

class EditorMapView : public QGraphicsView {
    Q_OBJECT
public:
    Map *map;

    explicit EditorMapView(QWidget *parent = nullptr);

    void setMode(const QString& mode);

    Robot *getSelectedRobot();

    void setEditMode(const QString &mode);

    QGraphicsEllipseItem* findRobotItemByPosition(const QPointF& position);

    void updateRobotDirection(Robot* robot, QGraphicsEllipseItem* robotGraphics);

    QString getMapDataAsString() const;
signals:
    void robotAdded(const QPointF& position);
    void obstacleAdded(const QPointF& position);
    void robotPositionChanged(const Vector2D& newPos, const Vector2D& oldPos);
    void obstaclePositionChanged(const Vector2D& newPos, const Vector2D& oldPos);
protected:
    // Override to handle mouse press events for placing items
    void mousePressEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;  // The scene where all items are displayed
    QString placementMode;       // Current editing mode
    QString mode;
    QPointF initialPos; // Initial position when dragging an item
    QPointF initialMousePos; // Initial mouse position when dragging an item
    QGraphicsItem *selectedItem = nullptr; // The currently selected item
    Robot *selectedRobot = nullptr; // The currently selected obstacle

    // Methods to handle adding robots/obstacles
    void addRobotAtPosition(const QPointF &pos);

    bool checkOverlap(const QGraphicsItem *ignoreItem, const QPointF& pos, const QSizeF& size) const;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void addObstacleAtPosition(const QPointF &pos);

    static void setItemColor(QGraphicsItem *item, const QColor &color);

    static void setBackItemColor(QGraphicsItem *item);

    void positionChanged(QGraphicsItem *item, const QPointF &newPos);

    void selectItem(QGraphicsItem *item);
};


#endif //ICP_EDITORMAPVIEW_H
