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
    bool collision = false;
    for (std::vector<Menu>::reverse_iterator menu_it = m_menus.rbegin(); menu_it != m_menus.rend(); ++menu_it) {
        if (!collision) menu_it->update(mousePos);

        if (CheckCollisionPointRec(mousePos, menu_it->getRect()) && menu_it->isOpen())
            collision = true;
    }
}
