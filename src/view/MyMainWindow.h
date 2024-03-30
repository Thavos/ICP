#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QStackedWidget>
#include "MyMapView.h"

class MyMainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MyMainWindow(QWidget *parent = nullptr);

private slots:
  void onStartButtonClicked();
  void onQuitButtonClicked();

private:
  QPushButton* startButton;
  QPushButton* quitButton;
  QVBoxLayout* layout;
  QStackedWidget* stackedWidget;
  MyMapView* mapView;
};

#endif // MYMAINWINDOW_H