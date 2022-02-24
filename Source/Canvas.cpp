#include "Canvas.h"

Canvas::Canvas(QWidget *parent)
{
    this->setMouseTracking(true);
}

Layer* Canvas::getCurrentLayer()
{
    return layers[current_layer];
}

Tool* Canvas::getCurrentTool()
{
    return current_tool;
}

void Canvas::setCurrentTool(Tool* tool)
{
    Layer* layer = this->getCurrentLayer();
    current_tool = tool;
    current_tool->setLayer(layer);
}

void Canvas::addLayer(Layer* layer)
{
    layers.append(layer);
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    for(Layer* layer : layers)
    {
        painter.drawPixmap(0, 0, *layer);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    if(tool) tool->onMouseMove(event);
    repaint();
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    if(tool) tool->onMousePress(event);
    repaint();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    if(tool) tool->onMouseRelease(event);
    repaint();
}

void Canvas::keyPressEvent(QKeyEvent *event)
{

}

void Canvas::keyReleaseEvent(QKeyEvent *event)
{

}
