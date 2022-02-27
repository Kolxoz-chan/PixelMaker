QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    README.md

HEADERS += \
    Source/Core/Application.h \
    Source/Core/Canvas.h \
    Source/Core/Layer.h \
    Source/Core/Tool.h \
    Source/Core/Tools.h \
    Source/Editor/Editor.h \
    Source/Editor/Menu.h \
    Source/Editor/Toolbar.h

SOURCES += \
    Source/Core/Application.cpp \
    Source/Core/Canvas.cpp \
    Source/Core/Layer.cpp \
    Source/Core/Tool.cpp \
    Source/Core/Tools.cpp \
    Source/Editor/Editor.cpp \
    Source/Editor/Menu.cpp \
    Source/Editor/Toolbar.cpp \
    main.cpp
