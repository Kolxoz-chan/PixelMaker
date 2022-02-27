#include "Editor.h"

#include "../Core/Canvas.h"
#include "../Core/Application.h"
#include "../Core/Tools.h"

#include "Menu.h"

Editor::Editor(QWidget *parent) : QMainWindow(parent)
{
    Application::getInstance().init();
    Application::getInstance().setEditor(this);

    // Init widget settings
    this->setFixedSize(640, 480);

    // Init data
    this->initTools();
    this->initCanvas();
    this->initMenu();
}

void Editor::initCanvas()
{
    _canvas = new Canvas(this);
    _canvas->addLayer(new Layer(_canvas->size()));
    _canvas->setCurrentTool(Application::getInstance().getTools()->getTool(DEFAULT_TOOL_NAME));

    this->setCentralWidget(_canvas);
}

void Editor::initTools()
{
    Application::getInstance().getTools()->addTool(PENCIL_TOOL_NAME, new PencilTool());
    Application::getInstance().getTools()->addTool(FILL_TOOL_NAME, new FillTool());
}

void Editor::initMenu()
{
    _menu = new Menu();
    _menu->init(DEFAULT_TOOL_NAME);
}

void Editor::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key::Key_P: _canvas->setCurrentTool(Application::getInstance().getTools()->getTool(PENCIL_TOOL_NAME)); break;
        case Qt::Key::Key_F: _canvas->setCurrentTool(Application::getInstance().getTools()->getTool(FILL_TOOL_NAME)); break;

    }
}

Canvas *Editor::getCanvas() const
{
    return _canvas;
}
