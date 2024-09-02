#include "uimanager.hpp"

#include "menu.cpp"
#include "button.cpp"
#include "label.cpp"


UIManager::UIManager(Font* font)
    : p_font(font)
{}


void UIManager::addMenu(const char* name, Rectangle menuRect, Color color)
{
    m_menus[name] = Menu(menuRect, color, p_font);
    m_zBuffer.push_back(&m_menus[name]);
}


Menu& UIManager::getMenu(const char* name)
{
    return m_menus[name];
}


void UIManager::render()
{
    for (std::deque<Menu*>::iterator menu_it = m_zBuffer.begin(); menu_it != m_zBuffer.end(); ++menu_it) {
        (*menu_it)->render();
    }
}


void UIManager::update(Vector2 mousePos)
{
    bool collision = false;
    for (std::deque<Menu*>::reverse_iterator menu_it = m_zBuffer.rbegin(); menu_it != m_zBuffer.rend(); ++menu_it) {
        if (!collision) (*menu_it)->update(mousePos);

        if (CheckCollisionPointRec(mousePos, (*menu_it)->getRect()) && (*menu_it)->isOpen())
            collision = true;
    }
}
