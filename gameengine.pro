QT += core gui widgets 3dextras

TARGET = gameengine
TEMPLATE = app

SOURCES += main.cpp

SOURCES += \
    mainwidget.cpp \
    geometryengine.cpp

HEADERS += \
    gameObject.h \
    mainwidget.h \
    geometryengine.h \
    basicIO.h \
    transform.h

RESOURCES += \
    shaders.qrc \
    textures.qrc

# install
target.path = $$[YOUR_PATH]
INSTALLS += target

DISTFILES +=
