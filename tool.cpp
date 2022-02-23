#include "tool.h"

Tool::Tool(QString name, QString description)
{
    this->name = name;
    this->description = description;
}

void Tool::setLayer(QPixmap* layer)
{
    this->layer = layer;
}

// ------------------ Pencil tool ----------------------- //
PencilTool::PencilTool() : Tool("Pencil", "Simple pencil")
{

}

void PencilTool::onMouseMove(QMouseEvent* event)
{
    if(is_draw)
    {
        QPoint pos = event->pos();

        QBrush brush = QBrush(QColor(0, 0, 0));
        QPen pen = QPen(brush, 2);

        QPainter painter(layer);
        painter.setPen(pen);
        painter.drawLine(last_point, pos);

        last_point = pos;
    }
}

void PencilTool::onMousePress(QMouseEvent* event)
{
    is_draw = true;
    last_point = event->pos();
}

void PencilTool::onMouseRelease(QMouseEvent* event)
{
    is_draw = false;
    QPoint pos = event->pos();

    QBrush brush = QBrush(QColor(0, 0, 0));
    QPen pen = QPen(brush, 2);

    QPainter painter(layer);
    painter.setPen(pen);
    painter.drawLine(last_point, pos);
}
