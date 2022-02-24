#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

#include "Canvas.h"
#include "Tool.h"

class Editor : public QMainWindow
{
    Q_OBJECT

private:
    QMap<QString,Tool*> tools;
    Canvas* canvas;


public:
    Editor(QWidget *parent = nullptr);

    void initTools();

    void addTool(QString name, Tool* tool);

    ~Editor() = default;
};
#endif // EDITOR_H
