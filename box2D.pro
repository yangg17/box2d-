TEMPLATE = app
TARGET = Box2D
CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += .
LIBS += -lSDL2 -lglut -lGLU -lGL

SOURCES += main.cpp \
    physicsworld.cpp \
    rigidbody.cpp \
    obstacles.cpp \
    GLFunctionsLib/src/GLFunctions.cpp \
    GLFunctionsLib/src/Mat4.cpp \
    GLFunctionsLib/src/Vec4.cpp \
    colours.cpp

INCLUDEPATH+=$$PWD/include
INCLUDEPATH+=$$PWD/GLFunctionsLib/include
LIBS+= -L $$PWD/GLFunctionsLib/lib -lGLFunctionsLib


#include(deployment.pri)
#qtcAddDeployment()

HEADERS += \
    physicsworld.h \
    rigidbody.h \
    obstacles.h \
    GLFunctionsLib/include/GLFunctions.h \
    GLFunctionsLib/include/Mat4.h \
    GLFunctionsLib/include/Vec4.h \
    colours.h
avi
DISTFILES += \
    README.txt \
    box2D

