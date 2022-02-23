#ifndef CANVASLAYER_H
#define CANVASLAYER_H

#include <QtCore/QtCore>
#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>
#include "tool.h"

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

private:

    QVector<QPixmap*> layers;
    QMap<QString,Tool*> tools;

    QString current_tool;
    int current_layer = 0;

    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QPixmap* getCurrentLayer();
    Tool* getCurrentTool();

    void setCurrentTool(QString name);

    void addTool(QString name, Tool* tool);


signals:

};

#endif // CANVASLAYER_H
