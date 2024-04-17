#ifndef ICP_EDITORMAPVIEW_H
#define ICP_EDITORMAPVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem> // For robot representation
#include <QGraphicsRectItem>   // For obstacle representation
#include "src/model/Map.h"

class EditorMapView : public QGraphicsView {
    Q_OBJECT
public:
    explicit EditorMapView(QWidget *parent = nullptr);


    void setEditMode(const QString &mode);


    QString getMapDataAsString() const;

protected:
    // Override to handle mouse press events for placing items
    void mousePressEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;  // The scene where all items are displayed
    QString editMode;       // Current editing mode
    Map *map;               // The map being edited

    // Methods to handle adding robots/obstacles
    void addRobotAtPosition(const QPointF &pos);

    void addObstacleAtPosition(const QPointF &pos);
};


#endif //ICP_EDITORMAPVIEW_H
