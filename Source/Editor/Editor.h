#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

#include "../Core/Tool.h"

class Canvas;
class Menu;
class Toolbar;

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor() = default;

public:
    Canvas* getCanvas() const;
    Toolbar* getToolbar() const;

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    void initCanvas();
    void initTools();
    void initMenu();
    void initToolbar();

    void setCurrentTool(Tool* tool);

private:
    Canvas* _canvas = nullptr;
    Menu* _menu = nullptr;
    Toolbar* _toolbar = nullptr;
};

#endif // EDITOR_H
