#include "Layer.h"

Layer::Layer(QSize size) : QPixmap(size)
{
    this->fill(Qt::transparent);
}
