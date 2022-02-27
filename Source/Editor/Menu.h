#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QMenu>
#include <QString>
#include <QMap>

class Menu : public QObject
{
    Q_OBJECT

public:
    Menu() = default;
    ~Menu() = default;

public:
    void init(const QString& currentToolName);

public slots:
    void onSelectTool();

private:
    void initMenuBar();

    void setCurrentToolName(const QString& currentToolName);

    void onRedrawSelectToolsMenu();

private:
    QString _currentToolName;

    QMenu* _selectToolsMenu = nullptr;
};

#endif // MENU_H
