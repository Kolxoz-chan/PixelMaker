#ifndef TOOL_H
#define TOOL_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include "Layer.h"

// ---------------- Base tool ----------------------- //
class Tool
{
protected:
    QString name;
    QString description;
    Layer* layer;
    QMap<QString, QVariant> settings;

public:
    Tool(QString name, QString description);

    virtual void onMouseMove(QMouseEvent* event) {};
    virtual void onMousePress(QMouseEvent* event) {};
    virtual void onMouseRelease(QMouseEvent* event) {};

    void setLayer(Layer* layer);
};

// ---------------- Pencil tool -------------------- //
class PencilTool : public Tool
{
private:
    bool is_draw = false;
    QPoint last_point;

public:
    PencilTool();

    void onMouseMove(QMouseEvent* event) override;
    void onMousePress(QMouseEvent* event) override;
    void onMouseRelease(QMouseEvent* event) override;
};

// ---------------- Fill tool -------------------- //
class FillTool : public Tool
{
private:
    bool is_pressed = false;

public:
    FillTool();

    QImage fillPixel(QImage img, QPoint pos);
    void onMousePress(QMouseEvent* event) override;
    void onMouseRelease(QMouseEvent* event) override;
};

#endif // TOOL_H
