#include "button.hpp"
#include "menu.hpp"


Button::Button(Rectangle buttonRect, Color color, Menu* menuChild, Font* font, const char* text)
    : m_rect(buttonRect),
      m_color(color),
      m_colorDark(Color{ (unsigned char)(m_color.r - 15), (unsigned char)(m_color.g - 15), (unsigned char)(m_color.b - 15), m_color.a }),
      p_menuChild(menuChild),
      p_font(font),
      m_text(text)
{}


template <typename Func, typename... Args>
void Button::callFunction(Func func, Args&&... args)
{
    func(std::forward<Args>(args)...);
}


bool Button::update(Vector2 mousePos)
{
    if (CheckCollisionPointRec(mousePos, m_rect)) {
        if (IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT) && p_menuChild != nullptr) {
            p_menuChild->toggle();
            return true;
        }
    }
    return false;
}


void Button::render()
{
    DrawRectangleRec(m_rect, { 200, 200, 200, 255 });
    DrawRectangleLinesEx(m_rect,
                         4,
                         m_colorDark);

    Vector2 textSize = MeasureTextEx(*p_font, m_text, 30, 0);
    DrawTextEx(*p_font, m_text, Vector2{ m_rect.x + (m_rect.width - textSize.x) / 2, m_rect.y + (m_rect.height - textSize.y) / 2 + 3 }, 30, 0, Color{ 20, 20, 20, 255 });
}
