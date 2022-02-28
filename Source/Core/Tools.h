#ifndef TOOLS_H
#define TOOLS_H

#include "../Core/Tool.h"

#include <QString>
#include <QVector>

enum class SettingKeyboardActions;

class Tools
{
public:
    Tools() = default;
    ~Tools() = default;

public:
    void addTool(Tool* tool);
    Tool* getTool(const QString& key) const;
    Tool* getFirstTool() const;
    Tool* getToolFromKeyboardAction(SettingKeyboardActions keyboardAction) const;

    QVector<QString> getToolNames() const;

private:
    QVector<Tool*> _tools;
};

#endif // TOOLS_H
