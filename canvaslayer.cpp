#include "canvaslayer.h"
#include <iostream>

Canvas::Canvas(QWidget *parent)
{
    // Loading tools
    this->addTool("pencil", new PencilTool());

    // Create new layer
    QPixmap* layer = new QPixmap(this->size());
    layers.append(layer);
    this->repaint();

    // Canvas settings
    this->setMouseTracking(true);
    this->setCurrentTool("pencil");
}

QPixmap* Canvas::getCurrentLayer()
{
    return layers[current_layer];
}

Tool* Canvas::getCurrentTool()
{
    return tools[current_tool];
}

void Canvas::setCurrentTool(QString name)
{
    current_tool = name;
    tools[name]->setLayer(this->getCurrentLayer());
}

void Canvas::addTool(QString name, Tool* tool)
{
    tools[name] = tool;
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    for(QPixmap* layer : layers)
    {
        painter.drawPixmap(0, 0, *layer);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    tool->onMouseMove(event);
    repaint();
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    tool->onMousePress(event);
    repaint();
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    Tool* tool = getCurrentTool();
    tool->onMouseRelease(event);
    repaint();
}
