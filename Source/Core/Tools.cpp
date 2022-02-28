#include "Tools.h"

void Tools::addTool(Tool *tool)
{
    // TODO: Добавить проверку "Существует ли инструмент"
    // для того, чтобы случайно не добавить 2 инструмента
    _tools.push_back(tool);
}

Tool *Tools::getTool(const QString &key) const
{
    for (const auto& tool : _tools)
    {
        if (tool->getName() == key)
        {
            return tool;
        }
    }

    return nullptr;
}

QVector<QString> Tools::getToolNames() const
{
    QVector<QString> toolNames;

    for (const auto& tool : _tools)
    {
        toolNames.push_back(tool->getName());
    }

    return toolNames;
}
