QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets

CONFIG += c++17

# LIBS += -lwiringPi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    sources/battery.cpp \
    sources/distance.cpp \
    sources/horn.cpp \
    sources/indicators.cpp \
    sources/lights.cpp \
    sources/speed.cpp \
    sources/tirepressure.cpp \
    sources/motor.cpp \
    sources/background.cpp \
    sources/gears.cpp \

HEADERS += \
    mainwindow.h \
    global_variables/global_variables.h \
    headers/battery.h \
    headers/distance.h \
    headers/horn.h \
    headers/indicators.h \
    headers/lights.h \
    headers/speed.h \
    headers/tirepressure.h \
    headers/motor.h \
    headers/background.h \
    headers/gears.h \

FORMS += \
    forms/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/icons.qrc

