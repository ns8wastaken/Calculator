#include <raylib.h>

#include "src/ui/uimanager.cpp"
#include "src/calculator.cpp"


#define CALC_WIDTH  800
#define CALC_HEIGHT 800

#define CONVERSION_MENU_WIDTH  500
#define CONVERSION_MENU_HEIGHT 700


void setupUI(UIManager& uim)
{
    uim.addMenu("Base", Rectangle{ 20, 280, CALC_WIDTH - 40, CALC_HEIGHT - 300 }, Color{ 175, 175, 175, 255 });
    uim.getMenu("Base").toggle();
    uim.getMenu("Base").addButton(Rectangle{ 20, 20, 210, 50 }, Color{ 150, 150, 150, 255 }, &uim.getMenu("Conversions Base"), "Conversions");


    Rectangle conversionMenuRect = Rectangle{
        (CALC_WIDTH - CONVERSION_MENU_WIDTH) / 2,
        (CALC_HEIGHT - CONVERSION_MENU_HEIGHT) / 2,
        CONVERSION_MENU_WIDTH,
        CONVERSION_MENU_HEIGHT
    };
    Color conversionMenuColor = Color{ 175, 175, 175, 255 };

    Rectangle conversionMenuButtonRect = Rectangle{ CONVERSION_MENU_WIDTH - 110, 10, 100, 40 };
    Color conversionMenuButtonColor = Color{ 150, 150, 150, 255 };

    uim.addMenu("Conversions Base", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Base").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Base"), "Close");

    uim.addMenu("Conversions Length", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Length").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Length"), "Close");

    uim.addMenu("Conversions Mass", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Mass").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Mass"), "Close");

    uim.addMenu("Conversions Temperature", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Temperature").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Temperature"), "Close");

    uim.addMenu("Conversions Angle", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Angle").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Angle"), "Close");

    uim.addMenu("Conversions Digital Storage", conversionMenuRect, conversionMenuColor);
    uim.getMenu("Conversions Digital Storage").addButton(conversionMenuButtonRect, conversionMenuButtonColor, &uim.getMenu("Conversions Digital Storage"), "Close");



    uim.getMenu("Conversions Base")
        .addButton(
            Rectangle{ (CONVERSION_MENU_WIDTH - 260) / 2, (CONVERSION_MENU_HEIGHT - 60) / 6 + 30, 260, 60 },
            conversionMenuButtonColor,
            &uim.getMenu("Conversions Length"),
            "Length");

    uim.getMenu("Conversions Base")
        .addButton(
            Rectangle{ (CONVERSION_MENU_WIDTH - 260) / 2, (CONVERSION_MENU_HEIGHT - 60) * 2 / 6 + 30, 260, 60 },
            conversionMenuButtonColor,
            &uim.getMenu("Conversions Mass"),
            "Mass");

    uim.getMenu("Conversions Base")
        .addButton(
            Rectangle{ (CONVERSION_MENU_WIDTH - 260) / 2, (CONVERSION_MENU_HEIGHT - 60) * 3 / 6 + 30, 260, 60 },
            conversionMenuButtonColor,
            &uim.getMenu("Conversions Temperature"),
            "Temperature");

    uim.getMenu("Conversions Base")
        .addButton(
            Rectangle{ (CONVERSION_MENU_WIDTH - 260) / 2, (CONVERSION_MENU_HEIGHT - 60) * 4 / 6 + 30, 260, 60 },
            conversionMenuButtonColor,
            &uim.getMenu("Conversions Angle"),
            "Angle");

    uim.getMenu("Conversions Base")
        .addButton(
            Rectangle{ (CONVERSION_MENU_WIDTH - 260) / 2, (CONVERSION_MENU_HEIGHT - 60) * 5 / 6 + 30, 260, 60 },
            conversionMenuButtonColor,
            &uim.getMenu("Conversions Digital Storage"),
            "Digital Storage");
}


int main()
{
    InitWindow(CALC_WIDTH, CALC_HEIGHT, "Calculator");

    Calculator calculator;

    Font uiFont = LoadFontEx("src/CourierPrime.ttf", 30, nullptr, 0);
    SetTextureFilter(uiFont.texture, TEXTURE_FILTER_BILINEAR);

    UIManager uimanager(&uiFont);

    setupUI(uimanager);

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
