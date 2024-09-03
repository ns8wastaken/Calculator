#include "menu.hpp"


Menu::Menu()
    : m_rect(Rectangle{ 0, 0, 0, 0 }),
      m_color(Color{ 0, 0, 0, 255 }),
      m_colorDark(Color{ 0, 0, 0, 255 }),
      p_font(nullptr)
{}


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


const Label& Menu::getLabel(size_t index)
{
    return m_labels[index];
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
        Button(
            Rectangle{
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
        Label(
            Rectangle{
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

    DrawRectangleRounded(m_rect, 0.05, 4, m_color);
    DrawRectangleRoundedLines(m_rect, 0.05, 4, 4, m_colorDark);

    for (Button& button : m_buttons) {
        button.render();
    }

    for (Label& label : m_labels) {
        label.render();
    }
}
