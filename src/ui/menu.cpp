#include "menu.hpp"


Menu::Menu(Rectangle menuRect, Color color, Font* font)
    : m_rect(menuRect),
      m_color(color),
      m_colorDark(Color{ (unsigned char)(m_color.r - 15), (unsigned char)(m_color.g - 15), (unsigned char)(m_color.b - 15), m_color.a }),
      p_font(font)
{}


const Rectangle& Menu::getRect()
{
    return m_rect;
}


void Menu::toggle()
{
    m_open = !m_open;
}


bool Menu::isOpen()
{
    return m_open;
}


void Menu::addButton(Rectangle buttonRect, Color color, Menu* menuChild, const char* text)
{
    m_buttons.push_back(
        Button(Rectangle{
                   m_rect.x + buttonRect.x,
                   m_rect.y + buttonRect.y,
                   buttonRect.width,
                   buttonRect.height },
               color,
               menuChild,
               p_font,
               text));
}


void Menu::addLabel(Rectangle labelRect, Color color, const char* text)
{
    m_labels.push_back(
        Label(Rectangle{
                  m_rect.x + labelRect.x,
                  m_rect.y + labelRect.y,
                  labelRect.width,
                  labelRect.height },
              color,
              text,
              p_font));
}


void Menu::update(Vector2 mousePos)
{
    if (!m_open) return;

    for (Button& button : m_buttons) {
        button.update(mousePos);
    }
}


void Menu::render()
{
    if (!m_open) return;

    DrawRectangleRec(m_rect, m_color);
    DrawRectangleLinesEx(m_rect, 4, m_colorDark);

    for (Button& button : m_buttons) {
        button.render();
    }
}
