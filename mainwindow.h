#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "canvaslayer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Canvas* canvas;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
