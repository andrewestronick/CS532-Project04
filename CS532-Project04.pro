TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    edge.cpp \
    graph.cpp \
    maze.cpp \
    tree.cpp

HEADERS += \
    edge.h \
    graph.h \
    maze.h \
    tree.h
