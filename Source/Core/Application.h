#ifndef APPLICATION_H
#define APPLICATION_H

class Editor;
class Tools;
class Settings;

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

    Settings* getSettings() const;

private:
    Editor* _editor = nullptr;
    Tools* _tools = nullptr;
    Settings* _settings = nullptr;
};

#endif // APPLICATION_H
