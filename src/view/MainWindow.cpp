#include "MainWindow.h"

// xsnope04

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(600, 600);

    QHBoxLayout *layout = new QHBoxLayout(this);
    QPushButton *simulationButton = new QPushButton("Simulation", this);
    QPushButton *newMapButton = new QPushButton("New Map", this);
    QPushButton *editorButton = new QPushButton("Edit Map", this);
    QPushButton *quitButton = new QPushButton("Quit", this);

    layout->addWidget(simulationButton);
    layout->addWidget(newMapButton);
    layout->addWidget(editorButton);
    layout->addWidget(quitButton);

    layout->setAlignment(Qt::AlignCenter);

    connect(simulationButton, &QPushButton::clicked, this, &MainWindow::showSimulationView);
    connect(newMapButton, &QPushButton::clicked, this, [this]() { showEditorView(false); });
    connect(editorButton, &QPushButton::clicked, this, [this]() { showEditorView(true); });
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);

    setLayout(layout);

    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    move(screenGeometry.center() - rect().center());
}

void MainWindow::showSimulationView() {
    SimulationView *simulationView = new SimulationView();
    simulationView->setAttribute(Qt::WA_DeleteOnClose);
    simulationView->show();
    connect(simulationView, &SimulationView::closed, this, &MainWindow::show);
    hide();
}

void MainWindow::showEditorView(bool fromExisting) {
    EditorView *editorView = new EditorView(nullptr, fromExisting); // Pass the flag to the constructor
    editorView->setAttribute(Qt::WA_DeleteOnClose);
    editorView->show();
    connect(editorView, &EditorView::closed, this, &MainWindow::show);
    hide();
}