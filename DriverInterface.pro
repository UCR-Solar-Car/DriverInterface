QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4):
QT += widgets

CONFIG += c++17

#LIBS += -lwiringPi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    battery.cpp \
    distance.cpp \
    horn.cpp \
    indicators.cpp \
    lights.cpp \
    main.cpp \
    mainwindow.cpp \
    speed.cpp \
    tirepressure.cpp \
    motor.cpp \
    background.cpp \
    gears.cpp \

HEADERS += \
    battery.h \
    distance.h \
    global_variables.h \
    horn.h \
    indicators.h \
    lights.h \
    mainwindow.h \
    speed.h \
    tirepressure.h \
    motor.h \
    background.h \
    gears.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

