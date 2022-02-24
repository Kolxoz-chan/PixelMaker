#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

#include "Canvas.h"

class Editor : public QMainWindow
{
    Q_OBJECT

private:
    Canvas* canvas;
    QToolBar* toolbar;


public:
    Editor(QWidget *parent = nullptr);
    ~Editor() = default;
};
#endif // EDITOR_H
