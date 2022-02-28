#include "Editor.h"

#include "../Core/Canvas.h"
#include "../Core/Application.h"
#include "../Core/Tools.h"
#include "../Core/Settings.h"

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
    _canvas = new Canvas(QSize(200, 200));
    _canvas->addLayer(new Layer(_canvas->getSize()));
    _canvas->setCurrentTool(Application::getInstance().getTools()->getFirstTool());

    this->setCentralWidget(_canvas);
}

void Editor::initTools()
{
    Application::getInstance().getTools()->addTool(new PencilTool());
    Application::getInstance().getTools()->addTool(new FillTool());
    Application::getInstance().getTools()->addTool(new PolygonTool());
    Application::getInstance().getTools()->addTool(new EraserTool());
}

void Editor::initMenu()
{
    _menu = new Menu();
    _menu->init(_canvas->getCurrentTool()->getName());
}

void Editor::initToolbar()
{
    _toolbar = new Toolbar("Toolbar", this);
    _toolbar->init(_canvas->getCurrentTool()->getName());

    addToolBar(Qt::ToolBarArea::LeftToolBarArea, _toolbar);
}

Canvas *Editor::getCanvas() const
{
    return _canvas;
}

Toolbar *Editor::getToolbar() const
{
    return _toolbar;
}

void Editor::keyPressEvent(QKeyEvent *event)
{
    Qt::Key key = static_cast<Qt::Key>(event->key());
    auto keyboardAction = Application::getInstance().getSettings()->GetKeyboardAction(key);

    if (keyboardAction == SettingKeyboardActions::NoAction)
    {
        return;
    }

    if (auto tool = Application::getInstance().getTools()->getToolFromKeyboardAction(keyboardAction))
    {
        setCurrentTool(tool);
    }
}

void Editor::setCurrentTool(Tool* tool)
{
    _canvas->setCurrentTool(tool);
    _menu->setCurrentToolName(tool->getName());
    _toolbar->setCurrentToolName(tool->getName());
}
