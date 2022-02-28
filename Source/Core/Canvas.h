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
    QSize _size;
    Layer* aux_layer = nullptr;
    QTransform* transform;
    QVector<Layer*> layers;

    Tool* current_tool = nullptr;
    int current_layer = 0;

public:
    explicit Canvas(QSize size);

    Layer* getCurrentLayer();
    Tool* getCurrentTool();
    const QSize& getSize();

    void setCurrentTool(Tool* tool);
    void addLayer(Layer* layer);

    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

signals:

};

#endif // CANVAS_H
