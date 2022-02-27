#include "Menu.h"

#include "../Core/Application.h"
#include "../Core/Tools.h"
#include "../Core/Canvas.h"
#include "Editor.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVariant>

void Menu::init()
{
    auto menuBar = Application::getInstance().getEditor()->menuBar();

    auto toolsMenu = menuBar->addMenu("Tools");

    auto selectToolsMenu = toolsMenu->addMenu("Select");
    auto&& toolNames = Application::getInstance().getTools()->getToolNames();
    for (const auto& toolName : toolNames)
    {
        auto selectToolAction = selectToolsMenu->addAction(toolName);
        connect(selectToolAction, &QAction::triggered, this, &Menu::onSelectTool);
    }
}

void Menu::onSelectTool()
{
    auto&& toolName = qobject_cast<QAction*>(sender())->text();
    Application::getInstance().getEditor()->getCanvas()->setCurrentTool(
        Application::getInstance().getTools()->getTool(toolName)
    );
}
