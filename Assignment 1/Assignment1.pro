TEMPLATE = app
TARGET = Assignment1.pro

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    List.cpp \
    Stack.cpp \
    main.cpp

HEADERS += \
    List.h \
    Queue.h \
    Stack.h
