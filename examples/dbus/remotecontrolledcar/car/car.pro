######################################################################
# Automatically generated by qmake (2.01a) Mon Aug 28 19:50:14 2006
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .
CONFIG += qdbus

# Input
# DBUS_ADAPTORS += car.xml
HEADERS += car.h car_adaptor.h
SOURCES += car.cpp main.cpp car_adaptor.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/dbus/remotecontrolledcar/car
sources.files = $$SOURCES $$HEADERS $$RESOURCES *.pro *.xml
sources.path = $$[QT_INSTALL_EXAMPLES]/dbus/remotecontrolledcar/car
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)
