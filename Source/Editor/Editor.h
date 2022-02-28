#ifndef EDITOR_H
#define EDITOR_H

#include <QMainWindow>

class Canvas;
class Menu;
class Toolbar;

class Editor : public QMainWindow
{
    Q_OBJECT

public:
    Editor(QWidget *parent = nullptr);
    ~Editor() = default;

public:
    Canvas* getCanvas() const;
    Toolbar* getToolbar() const;

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    void initCanvas();
    void initTools();
    void initMenu();
    void initToolbar();

    void setCurrentTool(const QString& toolName);

private:
    Canvas* _canvas = nullptr;
    Menu* _menu = nullptr;
    Toolbar* _toolbar = nullptr;

private:
    static inline const QString PENCIL_TOOL_NAME = "Pencil";
    static inline const QString FILL_TOOL_NAME = "F";
    static inline const QString ERASER_TOOL_NAME = "Eraser";
    static inline const QString DEFAULT_TOOL_NAME = PENCIL_TOOL_NAME;
};

#endif // EDITOR_H
