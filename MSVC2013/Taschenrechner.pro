

TEMPLATE = app
TARGET = Taschenrechner
QT += core widgets gui printsupport
CONFIG += debug
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/Debug
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/debug
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
include(Taschenrechner.pri)
