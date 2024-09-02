#include "menu.hpp"
#include "button.hpp"
#include "label.hpp"


class UIManager
{
public:
    UIManager(Font* font);
    void render();
    void update(Vector2 mousePos);

    void addMenu(Rectangle menuRect, Color color);
    Menu& getMenu(size_t index);

private:
    Font* p_font;

    std::vector<Menu> m_menus;
};
