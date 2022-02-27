#include "Editor.h"

#include "../Core/Canvas.h"
#include "../Core/Application.h"
#include "../Core/Tools.h"

#include "Menu.h"
#include "Toolbar.h"

Editor::Editor(QWidget *parent) : QMainWindow(parent)
{
    // Init application sigleton
    Application::getInstance().setEditor(this);

    // Init widget settings
    this->setFixedSize(640, 480);

    // Init data
    this->initTools();
    this->initCanvas();
    this->initMenu();
    this->initToolbar();
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

void Editor::initToolbar()
{
    _toolbar = new Toolbar("Toolbar", this);
    _toolbar->init(DEFAULT_TOOL_NAME);

    addToolBar(Qt::ToolBarArea::TopToolBarArea, _toolbar);
}

Canvas *Editor::getCanvas() const
{
    return _canvas;
}

Toolbar *Editor::getToolbar() const
{
    return _toolbar;
}
