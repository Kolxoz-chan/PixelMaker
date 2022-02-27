#include "Tool.h"

Tool::Tool(QString name, QString description)
{
    this->name = name;
    this->description = description;
}

void Tool::setLayer(Layer* layer)
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

// ---------------- Fill tool -------------------- //
FillTool::FillTool() : Tool("F", "Simple pencil")
{
    settings["color"] = QColor(0,0,0);
}

bool canFill(const QImage& img, const QPoint& pos, const QColor& color, const QColor& new_color)
{
    QRect rect = img.rect();
    if(rect.contains(pos))
        return img.pixelColor(pos) == color && img.pixelColor(pos) != new_color;
    return false;
}

void FillTool::onMousePress(QMouseEvent* event)
{
    if(!is_pressed)
    {
        is_pressed = true;

        QImage img = layer->toImage();
        QPoint pos = event->pos();
        QColor new_color = settings["color"].value<QColor>();
        QList<QPoint> list = {pos};
        QColor color = img.pixelColor(pos);

        while(true)
        {
            if(canFill(img, pos + QPoint(-1, 0), color, new_color))
            {
                pos += QPoint(-1, 0);
            }
            else if(canFill(img, pos + QPoint(0, 1), color, new_color))
            {
                pos += QPoint(0, 1);
            }
            else if(canFill(img, pos + QPoint(1, 0), color, new_color))
            {
                pos += QPoint(1, 0);
            }
            else if(canFill(img, pos + QPoint(0, -1), color, new_color))
            {
                pos += QPoint(0, -1);
            }
            else
            {
                if(list.isEmpty()) break;
                pos = list.last();
                list.pop_back();
                continue;
            }
            img.setPixelColor(pos, new_color);
            list.push_back(pos);
         }
        QPixmap new_layer = QPixmap::fromImage(img);
        layer->swap(new_layer);
    }
}

void FillTool::onMouseRelease(QMouseEvent* event)
{
    is_pressed = false;
}
