#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QObject>
#include <QToolBar>

class Toolbar : public QToolBar
{
    Q_OBJECT

public:
    explicit Toolbar(const QString &title, QWidget *parent = nullptr);
    ~Toolbar() = default;

public:
    void init(const QString& currentToolName);

public slots:
    void onSelectTool();

private:
    void initActions();

    void setCurrentToolName(const QString& currentToolName);

    void onRedrawSelectToolsMenu();

private:
    QString _currentToolName;
};

#endif // TOOLBAR_H
