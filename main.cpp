#include <raylib.h>

#include "src/ui/uimanager.cpp"
#include "src/calculator.cpp"


#define CALC_WIDTH  800
#define CALC_HEIGHT 800

#define CONVERSION_MENU_WIDTH  500
#define CONVERSION_MENU_HEIGHT 700


int main()
{
    InitWindow(CALC_WIDTH, CALC_HEIGHT, "Calculator");

    Calculator calculator;

    Font uiFont = LoadFontEx("src/CourierPrime.ttf", 30, nullptr, 0);
    SetTextureFilter(uiFont.texture, TEXTURE_FILTER_BILINEAR);

    UIManager uimanager(&uiFont);

    uimanager.addMenu(Rectangle{ 20, 280, CALC_WIDTH - 40, CALC_HEIGHT - 300 }, Color{ 175, 175, 175, 255 });
    uimanager.getMenu(0).toggle();

    uimanager.addMenu(
        Rectangle{ (CALC_WIDTH - CONVERSION_MENU_WIDTH) / 2,
                   (CALC_HEIGHT - CONVERSION_MENU_HEIGHT) / 2,
                   CONVERSION_MENU_WIDTH,
                   CONVERSION_MENU_HEIGHT },
        Color{ 175, 175, 175, 255 });

    uimanager.getMenu(0).addButton(Rectangle{ 20, 20, 210, 50 }, Color{ 150, 150, 150, 255 }, &uimanager.getMenu(1), "Conversions");
    uimanager.getMenu(1).addButton(Rectangle{ CONVERSION_MENU_WIDTH - 110, 10, 100, 40 }, Color{ 150, 150, 150, 255 }, &uimanager.getMenu(1), "Close");

    while (!WindowShouldClose()) {
        int charPressed = GetCharPressed();

        if (IsKeyPressed(KEY_BACKSPACE) || IsKeyPressedRepeat(KEY_BACKSPACE)) {
            calculator.removeCharBeforeCursor();
        }
        else if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
            calculator.moveCursor(-1);
        }
        else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
            calculator.moveCursor(1);
        }
        else if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) {
            calculator.calculate();
        }
        else if (charPressed) {
            calculator.addCharToEquation(charPressed);
        }

        Vector2 mousePos = GetMousePosition();

        uimanager.update(mousePos);


        BeginDrawing();
        ClearBackground(RAYWHITE);

        calculator.render();

        uimanager.render();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
