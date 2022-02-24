#ifndef TOOL_H
#define TOOL_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

// ---------------- Base tool ----------------------- //
class Tool
{
protected:
    QString name;
    QString description;
    QPixmap* layer;

public:
    Tool(QString name, QString description);

    virtual void onMouseMove(QMouseEvent* event) = 0;
    virtual void onMousePress(QMouseEvent* event) = 0;
    virtual void onMouseRelease(QMouseEvent* event) = 0;

    void setLayer(QPixmap* layer);
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

#endif // TOOL_H
