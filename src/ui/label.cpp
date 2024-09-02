#include "label.hpp"


Label::Label(Rectangle rect, Color color, const char* text, Font* font)
    : m_rect(rect), m_color(color), m_text(text), p_font(font)
{}


void Label::render()
{
    DrawRectangleRec(m_rect, { 200, 200, 200, 255 });
    DrawRectangleLinesEx(m_rect,
                         4,
                         Color{ (unsigned char)(m_color.r - 15), (unsigned char)(m_color.g - 15), (unsigned char)(m_color.b - 15), m_color.a });

    Vector2 textSize = MeasureTextEx(*p_font, m_text, 30, 0);
    DrawTextEx(*p_font, m_text, Vector2{ m_rect.x + (m_rect.width - textSize.x) / 2, m_rect.y + (m_rect.height - textSize.y) / 2 + 3 }, 30, 0, Color{ 20, 20, 20, 255 });
}
