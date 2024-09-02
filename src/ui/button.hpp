#pragma once
#include <raylib.h>


class Menu;

class Button
{
public:
    Button(Rectangle buttonRect, Color color, Menu* menuChild, Font* font, const char* str);
    bool update(Vector2 mousePos); // Return true if button was pressed
    void render();

private:
    Rectangle m_rect;
    Color m_color;
    Color m_colorDark;

    Menu* p_menuChild;
    Font* p_font;

    const char* m_text;

    template <typename Func, typename... Args>
    void callFunction(Func func, Args&&... args);
};
