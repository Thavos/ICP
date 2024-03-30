# Makefile for ICP robot simulation
# xhruzs00

TEMPLATE = app
TARGET = icp
INCLUDEPATH += .
CONFIG += c++17
QT += gui widgets
DEFINES += QT_DEPRECATED_WARNINGS

# Input
HEADERS += src/controller/SimulationController.h \
            src/model/Map.h \
            src/model/Obstacle.h \
            src/model/Robot.h \
            src/observer/Observable.h \
            src/observer/Observer.h \
            src/util/Vector2D.h \
            src/view/MapView.h \
            src/view/MainWindow.h \
            src/view/SimulationDialog.h \
            src/view/EditorDialog.h \
            src/view/MyMainWindow.h \
            src/view/MyMapView.h

SOURCES += src/controller/SimulationController.cpp \
            src/model/Map.cpp \
            src/model/Obstacle.cpp \
            src/model/Robot.cpp \
            src/util/Vector2D.cpp \
            src/view/MapView.cpp \
            src/main.cpp \
            src/view/MainWindow.cpp \
            src/view/SimulationDialog.cpp \
            src/view/EditorDialog.cpp \
            src/view/MyMainWindow.cpp \
            src/view/MyMapView.cpp

# Custom commands
QMAKE_CLEAN += -rf ./latex & rm -rf ./html

run.target = run
run.commands = build/$${TARGET}
QMAKE_EXTRA_TARGETS += run

doxygen.target = doxygen
doxygen.commands = doxygen doc/Doxyfile
QMAKE_EXTRA_TARGETS += doxygen

pack.target = pack
pack.commands = zip -r xhruzs00-xhruzs00.zip doc/ resources/ src/ Makefile README.txt
QMAKE_EXTRA_TARGETS += pack

# Custom buildpath
DESTDIR = build/
OBJECTS_DIR = build/obj
MOC_DIR = build/moc
RCC_DIR = build/rcc
UI_DIR = build/ui