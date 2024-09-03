#pragma once
#include <raylib.h>
#include <string>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <math.h>

#include "token.hpp"


class Calculator
{
public:
    Calculator();
    void render();

    void addCharToEquation(int char_);
    void removeCharBeforeCursor();

    const char* getEquation() const;
    void calculate();

    void moveCursor(int offset);
    size_t getCursorIndex();

    double result = 0.0;

private:
    Font m_font;

    bool m_isValidChar(int char_);

    std::string m_Equation{};
    size_t m_CursorIndex = 0;

    const std::unordered_map<char, int> m_Precedence = {
        { '+', 0 },
        { '-', 0 },
        { '*', 1 },
        { '/', 1 },
        { '^', 3 },
        { '!', 3 },
        { '(', 4 },
        { ')', 4 },
    };

    // False: Left associative
    // True: Right associative
    const std::unordered_map<char, bool> m_Operators = {
        { '+', false },
        { '-', false },
        { '*', false },
        { '/', false },
        { '^',  true },
        { '!', false }
    };

    std::deque<Token> m_ParseStrEquation(const std::string& equation);
    std::deque<Token> m_InfixToPostfix(std::deque<Token> infixStack);
    double m_EvaluatePostfix(std::deque<Token> postfixStack);
};
