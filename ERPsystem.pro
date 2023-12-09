QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accounting.cpp \
    cashflow.cpp \
    databaseconnector.cpp \
    inventorybalances.cpp \
    main.cpp \
    erpsystem.cpp \
    productionorder.cpp \
    salesorder.cpp \
    technologicalcard.cpp

HEADERS += \
    accounting.h \
    cashflow.h \
    databaseconnector.h \
    erpsystem.h \
    inventorybalances.h \
    productionorder.h \
    salesorder.h \
    technologicalcard.h

FORMS += \
    accounting.ui \
    cashflow.ui \
    erpsystem.ui \
    inventorybalances.ui \
    productionorder.ui \
    salesorder.ui \
    technologicalcard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
