TEMPLATE = app
TARGET = Assignment1.pro

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    Queue.cpp \
    Stack.cpp \
    main.cpp

HEADERS += \
    Queue.h \
    Stack.h
