#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(640, 480);

    canvas = new Canvas(this);
    this->setCentralWidget(canvas);
}

MainWindow::~MainWindow()
{

}

