#include "Editor.h"

Editor::Editor(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(640, 480);

    // Init data
    this->initTools();

    // Canvas settings
    canvas = new Canvas(this);
    this->setCentralWidget(canvas);

    canvas->addLayer(new Layer(canvas->size()));
    canvas->setCurrentTool(tools["pencil"]);
}

void Editor::initTools()
{
    this->addTool("pencil", new PencilTool());
}

void Editor::addTool(QString name, Tool* tool)
{
    tools[name] = tool;
}

