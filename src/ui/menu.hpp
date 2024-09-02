#pragma once
#include <vector>

#include "button.hpp"
#include "label.hpp"


class Menu
{
public:
    Menu();
    Menu(Rectangle menuRect, Color color, Font* font);
    void update(Vector2 mousePos);
    void render();

    void addButton(Rectangle buttonRect, Color color, Menu* menuChild, const char* text);
    void addLabel(Rectangle labelRect, Color color, const char* text);

    const Label& getLabel(size_t index);

    const Rectangle& getRect();
    void toggle();
    bool isOpen();

private:
    Rectangle m_rect;
    Color m_color;
    Color m_colorDark;
    Font* p_font;

    bool m_open = false;

    std::vector<Button> m_buttons{};
    std::vector<Label> m_labels{};
};
