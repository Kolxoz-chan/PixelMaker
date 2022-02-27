#include "Tools.h"

void Tools::addTool(const QString &key, Tool *tool)
{
    if (auto it = _tools.find(key); it == _tools.end())
    {
        _tools[key] = tool;
    }
}

Tool *Tools::getTool(const QString &key) const
{
    if (auto it = _tools.find(key); it != _tools.end())
    {
        return it.value();
    }

    return nullptr;
}

QVector<QString> Tools::getToolNames() const
{
    QVector<QString> toolNames;

    for (auto it = _tools.begin(); it != _tools.end(); ++it)
    {
        toolNames.push_back(it.key());
    }

    return toolNames;
}
