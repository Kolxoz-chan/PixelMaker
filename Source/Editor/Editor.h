#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

#include "../Core/Canvas.h"
#include "../Core/Tool.h"

class Editor : public QMainWindow
{
    Q_OBJECT

private:
    QMap<QString,Tool*> tools;
    Canvas* canvas;


public:
    Editor(QWidget *parent = nullptr);

    void initTools();
    void keyPressEvent(QKeyEvent *event) override;

    void addTool(QString name, Tool* tool);

    ~Editor() = default;
};
#endif // EDITOR_H
