#ifndef TOOL_H
#define TOOL_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#include "Layer.h"

enum class SettingKeyboardActions;

// ---------------- Base tool ----------------------- //
class Tool
{
protected:
    QString name;
    QString description;
    Layer* layer, *aux_layer;
    QMap<QString, QVariant> properties;
    SettingKeyboardActions keyboardAction;

public:
    Tool(QString name, QString description, SettingKeyboardActions keyboardAction);

    virtual void onMouseMove(QMouseEvent* event) {};
    virtual void onMousePress(QMouseEvent* event) {};
    virtual void onMouseRelease(QMouseEvent* event) {};
    virtual void reset() {};

    QMap<QString, QVariant> getProperties();
    QVariant getProperty(QString name);
    QString getName();
    SettingKeyboardActions getKeyboardAction() const;

    void setLayer(Layer* layer);
    void setAuxLayer(Layer* layer);
    void setProperty(QString name, QVariant value);
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

    void onMousePress(QMouseEvent* event) override;
    void onMouseRelease(QMouseEvent* event) override;
};

// ---------------- Fill tool -------------------- //
class EraserTool : public Tool
{
private:
    bool is_pressed = false;
    QPoint last_point;


public:
    EraserTool();

    void onMouseMove(QMouseEvent* event) override;
    void onMousePress(QMouseEvent* event) override;
    void onMouseRelease(QMouseEvent* event) override;


};

// ---------------- Fill tool -------------------- //
class PolygonTool : public Tool
{
private:
    bool is_pressed = false;
    QPoint last_point;


public:
    PolygonTool();

    void onMousePress(QMouseEvent* event) override;
    void onMouseRelease(QMouseEvent* event) override;
    void onMouseMove(QMouseEvent* event) override;
    void reset() override;

};

#endif // TOOL_H
