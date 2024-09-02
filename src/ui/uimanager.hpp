#include <unordered_map>
#include <deque>

#include "menu.hpp"
#include "button.hpp"
#include "label.hpp"


class UIManager
{
public:
    UIManager(Font* font);
    void render();
    void update(Vector2 mousePos);

    void addMenu(const char* name, Rectangle menuRect, Color color);
    Menu& getMenu(const char* name);

private:
    Font* p_font;
    std::deque<Menu*> m_zBuffer{};

    std::unordered_map<const char*, Menu> m_menus{};
};
