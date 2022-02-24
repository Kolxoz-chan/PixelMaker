#include "Editor.h"

Editor::Editor(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(640, 480);

    // Canvas settings
    canvas = new Canvas(this);
    this->setCentralWidget(canvas);
}

