#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QMap>
#include <QKeyEvent>

enum struct SettingKeyboardActions
{
    NoAction,
    SetPencilTool,
    SetFillTool,
    SetEraserTool
};

class Settings
{
public:
    Settings();
    ~Settings() = default;

public:
    void SetKeyboardAction(Qt::Key key, SettingKeyboardActions keyboardAction);
    SettingKeyboardActions GetKeyboardAction(Qt::Key key) const;

private:
    QMap<Qt::Key, SettingKeyboardActions> _keyboardActions;
};

#endif // SETTINGS_H
