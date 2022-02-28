#include "Canvas.h"

Canvas::Canvas(QSize size)
{
    this->setMouseTracking(true);
    this->aux_layer = new Layer(size);
    this->_size = size;
    QSize vec = (this->size() - size) / 2;

    transform = new QTransform();
    transform->translate(vec.width(), vec.height());
    transform->rotate(0);
    transform->scale(1.0, 1.0);
}

Layer* Canvas::getCurrentLayer()
{
    return layers[current_layer];
}

Tool* Canvas::getCurrentTool()
{
    return current_tool;
}

const QSize& Canvas::getSize()
{
    return _size;
}

void Canvas::setCurrentTool(Tool* tool)
{
    Layer* layer = this->getCurrentLayer();

    // Reset prew tool
    if(current_tool) current_tool->reset();

    current_tool = tool;
    current_tool->setLayer(layer);
    current_tool->setTransform(transform);
    current_tool->setAuxLayer(aux_layer);
    current_tool->reset();
}

void Canvas::addLayer(Layer* layer)
{
    layers.append(layer);
}

void Canvas::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setTransform(*transform);

    // Background
    painter.fillRect(0, 0, _size.width(), _size.height(), Qt::white);

    // Draw layers
    Layer* current_layer = getCurrentLayer();
    for(Layer* layer : layers)
    {
        painter.drawPixmap(0, 0, *layer);
        if(layer == current_layer)
        {
            painter.drawPixmap(0, 0, *aux_layer);
        }
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
    Tool* tool = getCurrentTool();
    if(tool) tool->onKeyRelease(event);
    repaint();
}

void Canvas::keyReleaseEvent(QKeyEvent *event)
{
    Tool* tool = getCurrentTool();
    if(tool) tool->onKeyRelease(event);
    repaint();
}
