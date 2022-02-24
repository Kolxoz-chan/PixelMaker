QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Editor.cpp \
    Source/Canvas.cpp \
    Source/Editor.cpp \
    Source/Layer.cpp \
    Source/Tool.cpp \
    canvas.cpp \
    layer.cpp \
    main.cpp \
    tool.cpp

HEADERS += \
    Editor.h \
    Source/Canvas.h \
    Source/Editor.h \
    Source/Layer.h \
    Source/Tool.h \
    canvas.h \
    layer.h \
    tool.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
