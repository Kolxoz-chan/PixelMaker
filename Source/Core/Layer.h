#ifndef LAYER_H
#define LAYER_H

#include <QPixmap>

class Layer : public QPixmap
{
public:
    Layer() = default;
    Layer(QSize size);
};

#endif // LAYER_H
