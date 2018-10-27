QT += core
QT += mqtt
QT -= gui

CONFIG += c++11

TARGET = WarpMqttSensor1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    CMqttClient.cpp \
    CSensors.cpp

HEADERS += \
    CMqttClient.h \
    CSensors.h

target.path = /usr/bin

INSTALLS += target
