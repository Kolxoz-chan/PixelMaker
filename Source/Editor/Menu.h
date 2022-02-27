#ifndef MENU_H
#define MENU_H

#include <QObject>

class Menu : public QObject
{
    Q_OBJECT

public:
    Menu() = default;
    ~Menu() = default;

public:
    void init();

public slots:
    void onSelectTool();
};

#endif // MENU_H
