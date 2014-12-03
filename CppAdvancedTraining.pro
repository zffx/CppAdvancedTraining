TEMPLATE = app
CONFIG += console
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    Lab02/MyVector.cpp \
    test.cpp \
    Lab03/Dice.cpp \
    Lab04/Shape.cpp \
    Lab04/Rectangle.cpp

HEADERS += \
    Lab01/Lab_1.h \
    Lab02/MyVector.h \
    test.h \
    Lab03/Dice.h \
    Lab04/IShape.h \
    Lab04/Shape.h \
    Lab04/Rectangle.h \
    Lab04/ShapeNames.h \
    Lab04/Point.h

