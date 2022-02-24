#ifndef CANVAS_H
#define CANVAS_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include "Tool.h"
#include "Layer.h"

class Canvas : public QWidget
{
    Q_OBJECT

private:
    QVector<Layer*> layers;

    Tool* current_tool = nullptr;
    int current_layer = 0;

    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

public:
    explicit Canvas(QWidget *parent = nullptr);

    Layer* getCurrentLayer();
    Tool* getCurrentTool();

    void setCurrentTool(Tool* tool);

    void addLayer(Layer* layer);

signals:

};

#endif // CANVAS_H
