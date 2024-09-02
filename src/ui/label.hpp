#pragma once
#include <raylib.h>


class Label
{
public:
    Label(Rectangle rect, Color color, const char* text, Font* font);
    void render();
    void changeText(const char* newText);

private:
    Rectangle m_rect;
    Color m_color;

    const char* m_text;

    Font* p_font;
};
