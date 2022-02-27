#include "Application.h"

#include "../Editor/Editor.h"
#include "Tools.h"

Application::Application()
    : _tools(new Tools())
{
}

Application &Application::getInstance()
{
    static Application application;
    return application;
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
