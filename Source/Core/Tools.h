#ifndef TOOLS_H
#define TOOLS_H

#include "../Core/Tool.h"

#include <QString>
#include <QMap>
#include <QVector>

class Tools
{
public:
    Tools() = default;
    ~Tools() = default;

public:
    void addTool(const QString& key, Tool* tool);
    Tool* getTool(const QString& key) const;

    QVector<QString> getToolNames() const;

private:
    QMap<QString,Tool*> _tools;
};

#endif // TOOLS_H
