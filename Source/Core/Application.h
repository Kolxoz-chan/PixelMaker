#ifndef APPLICATION_H
#define APPLICATION_H

class Editor;
class Tools;

class Application
{
public:
    Application();
    ~Application() = default;

public:
    static Application& getInstance();

public:
    void setEditor(Editor* editor);
    Editor* getEditor() const;

    Tools* getTools() const;

private:
    Editor* _editor = nullptr;
    Tools* _tools = nullptr;
};

#endif // APPLICATION_H
