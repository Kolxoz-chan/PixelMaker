#include "Tool.h"

#include "Settings.h"

Tool::Tool(QString name, QString description, SettingKeyboardActions keyboardAction)
{
    this->name = name;
    this->description = description;
    this->keyboardAction = keyboardAction;
}

void Tool::setLayer(Layer* layer)
{
    this->layer = layer;
}

void Tool::setAuxLayer(Layer* layer)
{
    aux_layer = layer;
}

QMap<QString, QVariant> Tool::getProperties()
{
    return properties;
}

QVariant Tool::getProperty(QString name)
{
    return properties[name];
}


QString Tool::getName()
{
    return name;
}

SettingKeyboardActions Tool::getKeyboardAction() const
{
    return keyboardAction;
}

void Tool::setProperty(QString name, QVariant value)
{

    properties[name] = value;
}

// ------------------ Pencil tool ----------------------- //
PencilTool::PencilTool() : Tool("Pencil", "Simple pencil", SettingKeyboardActions::SetPencilTool)
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
FillTool::FillTool() : Tool("Fill", "Simple pencil", SettingKeyboardActions::SetFillTool)
{
    properties["color"] = QColor(0,0,0);
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
        QColor new_color = properties["color"].value<QColor>();
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

// ---------------- Eraser tool -------------------- //
EraserTool::EraserTool() : Tool("Eraser", "Simple eraser", SettingKeyboardActions::SetEraserTool)
{
    properties["size"] = 10;
}

void EraserTool::onMouseMove(QMouseEvent* event)
{
    if(is_pressed)
    {
        QPoint pos = event->pos();
        uint size = properties["size"].toUInt();

        QBrush brush = QBrush(Qt::transparent);
        QPen pen = QPen(brush, size);

        QPainter painter(layer);
        painter.setCompositionMode(QPainter::CompositionMode_Clear);
        painter.setPen(pen);
        painter.drawLine(last_point, pos);

        last_point = pos;
    }
}

void EraserTool::onMousePress(QMouseEvent* event)
{
    is_pressed = true;
    last_point = event->pos();
}

void EraserTool::onMouseRelease(QMouseEvent* event)
{
    is_pressed = false;
    QPoint pos = event->pos();
    uint size = properties["size"].toUInt();

    QBrush brush = QBrush(Qt::transparent);
    QPen pen = QPen(brush, size);

    QPainter painter(layer);
    painter.setCompositionMode(QPainter::CompositionMode_Clear);
    painter.setPen(pen);
    painter.drawLine(last_point, pos);
}

// ---------------- Polygon tool -------------------- //
PolygonTool::PolygonTool() : Tool("Polygon", "Simple polygon", SettingKeyboardActions::SetPolygonTool)
{
    properties["size"] = 2;
    properties["color"] = QColor(0, 0, 0);
}

void PolygonTool::onMousePress(QMouseEvent* event)
{
    if(!is_pressed)
    {
        is_pressed = true;
        QPoint pos = event->pos();

        if(!last_point.isNull())
        {
            uint size = properties["size"].toUInt();
            QColor color = properties["color"].value<QColor>();

            QBrush brush = QBrush(color);
            QPen pen = QPen(brush, size);

            QPainter painter(layer);
            painter.setPen(pen);
            painter.drawLine(last_point, pos);
        }
        last_point = pos;
    }
}

void PolygonTool::onMouseRelease(QMouseEvent* event)
{
    is_pressed = false;
}

void PolygonTool::onMouseMove(QMouseEvent* event)
{
    if(!last_point.isNull())
    {
        uint size = properties["size"].toUInt();
        QColor color = properties["color"].value<QColor>();
        QPoint pos = event->pos();

        aux_layer->fill(Qt::transparent);

        QBrush brush = QBrush(color);
        QPen pen = QPen(brush, size);

        QPainter painter(aux_layer);
        painter.setPen(pen);
        painter.drawLine(last_point, pos);
    }
}

void PolygonTool::reset()
{
    last_point = QPoint();
    aux_layer->fill(Qt::transparent);
}

