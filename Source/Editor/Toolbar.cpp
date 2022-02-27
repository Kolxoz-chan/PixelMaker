#include "Toolbar.h"

#include "../Core/Application.h"
#include "../Core/Tools.h"
#include "../Core/Canvas.h"

#include "Editor.h"

Toolbar::Toolbar(const QString &title, QWidget *parent)
    : QToolBar(title, parent)
{

}

void Toolbar::init(const QString& currentToolName)
{
    initActions();

    setCurrentToolName(currentToolName);
}

void Toolbar::onSelectTool()
{
    auto&& toolName = qobject_cast<QAction*>(sender())->text();
    Application::getInstance().getEditor()->getCanvas()->setCurrentTool(
        Application::getInstance().getTools()->getTool(toolName)
    );

    setCurrentToolName(toolName);
}

void Toolbar::initActions()
{
    auto&& toolNames = Application::getInstance().getTools()->getToolNames();
    for (const auto& toolName : toolNames)
    {
        auto selectToolAction = addAction(toolName);
        selectToolAction->setCheckable(true);
        connect(selectToolAction, &QAction::triggered, this, &Toolbar::onSelectTool);
    }
}

void Toolbar::setCurrentToolName(const QString &currentToolName)
{
    _currentToolName = currentToolName;
    onRedrawSelectToolsMenu();
}

void Toolbar::onRedrawSelectToolsMenu()
{
    for (const auto& action : actions())
    {
        const bool isChecked = action->text() == _currentToolName;
        action->setChecked(isChecked);
    }
}
