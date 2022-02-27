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

QImage FillTool::fillPixel(QImage img, QPoint pos)
{
    QColor color = img.pixelColor(pos);
    QColor new_color = settings["color"].value<QColor>();
    img.setPixelColor(pos, new_color);

    QRect rect = img.rect();

    int left = pos.x() - 1;
    int right = pos.x() + 1;
    int top = pos.y() - 1;
    int bottom = pos.y() + 1;

    QPoint left_pix = pos + QPoint(-1, 0);
    QPoint right_pix = pos + QPoint(1, 0);
    QPoint top_pix = pos + QPoint(0, -1);
    QPoint bottom_pix = pos + QPoint(0, 1);

    if(rand() % 10 == 0) return img;

    //qDebug() << img.pixelColor(left) << color;
    if(left >= rect.left() && img.pixelColor(left_pix) == color)
    {
        img = fillPixel(img, left_pix);
    }
    if(right <= rect.right() && img.pixelColor(right_pix) == color)
    {
        img = fillPixel(img, right_pix);
    }
    if(top >= rect.top()  && img.pixelColor(top_pix) == color)
    {
        img = fillPixel(img, top_pix);
    }
    if(bottom <= rect.bottom() && img.pixelColor(bottom_pix) == color)
    {
        img = fillPixel(img, bottom_pix);
    }

    return img;
}

void FillTool::onMousePress(QMouseEvent* event)
{
    if(!is_pressed)
    {
        is_pressed = true;

        QImage img = layer->toImage();
        img = this->fillPixel(img, event->pos());
        QPixmap new_layer = QPixmap::fromImage(img);
        layer->swap(new_layer);
    }
}

void FillTool::onMouseRelease(QMouseEvent* event)
{
    is_pressed = false;
}
