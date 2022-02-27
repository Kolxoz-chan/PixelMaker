#include "Menu.h"

#include "../Core/Application.h"
#include "../Core/Tools.h"
#include "../Core/Canvas.h"
#include "Editor.h"

#include <QMenuBar>
#include <QAction>
#include <QVariant>

void Menu::init(const QString& currentToolName)
{
    initMenuBar();

    setCurrentToolName(currentToolName);
}

void Menu::onSelectTool()
{
    auto&& toolName = qobject_cast<QAction*>(sender())->text();
    Application::getInstance().getEditor()->getCanvas()->setCurrentTool(
        Application::getInstance().getTools()->getTool(toolName)
    );

    setCurrentToolName(toolName);
}

void Menu::initMenuBar()
{
    auto menuBar = Application::getInstance().getEditor()->menuBar();

    auto toolsMenu = menuBar->addMenu("Tools");

    _selectToolsMenu = toolsMenu->addMenu("Select");
    auto&& toolNames = Application::getInstance().getTools()->getToolNames();
    for (const auto& toolName : toolNames)
    {
        auto selectToolAction = _selectToolsMenu->addAction(toolName);
        selectToolAction->setCheckable(true);
        connect(selectToolAction, &QAction::triggered, this, &Menu::onSelectTool);
    }
}

void Menu::setCurrentToolName(const QString &currentToolName)
{
    _currentToolName = currentToolName;
    onRedrawSelectToolsMenu();
}

void Menu::onRedrawSelectToolsMenu()
{
    for (const auto& action : _selectToolsMenu->actions())
    {
        const bool isChecked = action->text() == _currentToolName;
        action->setChecked(isChecked);
    }
}
