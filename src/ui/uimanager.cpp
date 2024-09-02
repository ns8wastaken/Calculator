#include "uimanager.hpp"

#include "menu.cpp"
#include "button.cpp"
#include "label.cpp"


UIManager::UIManager(Font* font)
    : p_font(font)
{}


void UIManager::addMenu(Rectangle menuRect, Color color)
{
    m_menus.push_back(Menu(menuRect, color, p_font));
}


Menu& UIManager::getMenu(size_t index)
{
    return m_menus[index];
}


void UIManager::render()
{
    for (Menu& menu : m_menus) {
        menu.render();
    }
}


void UIManager::update(Vector2 mousePos)
{
    for (Menu& menu : m_menus) {
        menu.update(mousePos);
    }
}
