#include "Settings.h"

Settings::Settings()
{
    SetKeyboardAction(Qt::Key::Key_P, SettingKeyboardActions::SetPencilTool);
    SetKeyboardAction(Qt::Key::Key_F, SettingKeyboardActions::SetFillTool);
    SetKeyboardAction(Qt::Key::Key_E, SettingKeyboardActions::SetEraserTool);
}

void Settings::SetKeyboardAction(Qt::Key key, SettingKeyboardActions keyboardAction)
{
    _keyboardActions[key] = keyboardAction;
}

SettingKeyboardActions Settings::GetKeyboardAction(Qt::Key key) const
{
    if (auto it = _keyboardActions.find(key); it != _keyboardActions.end())
    {
        return it.value();
    }

    return SettingKeyboardActions::NoAction;
}
