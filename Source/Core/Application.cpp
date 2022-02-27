#include "Application.h"

#include "../Editor/Editor.h"
#include "Tools.h"

Application &Application::getInstance()
{
    static Application application;
    return application;
}

void Application::init()
{
    _tools = new Tools();
}

void Application::setEditor(Editor *editor)
{
    _editor = editor;
}

Editor *Application::getEditor() const
{
    return _editor;
}

Tools *Application::getTools() const
{
    return _tools;
}
