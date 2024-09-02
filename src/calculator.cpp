#include "calculator.hpp"
#include "converter.cpp"


Calculator::Calculator()
{
    m_font = LoadFontEx("src/CourierPrime.ttf", 50, nullptr, 0);
    SetTextureFilter(m_font.texture, TEXTURE_FILTER_BILINEAR);
}


void Calculator::render()
{
    DrawTextEx(m_font, getEquation(), Vector2{ 20, 20 }, 50, 0, BLACK);
    DrawRectangle(20 + getCursorIndex() * 26, 20, 4, 40, BLACK);

    DrawTextEx(m_font, TextFormat("%.9f", result), Vector2{ 20, 200 }, 50, 0, BLACK);
}


bool Calculator::m_isValidChar(int char_)
{
    if (std::isdigit(char_))
        return true;

    switch (char_) {
        case '.':
        case '!':
        case '(':
        case ')':
        case '*':
        case '+':
        case '-':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}


void Calculator::addCharToEquation(int charUnicode)
{
    if (!m_isValidChar(charUnicode))
        return;

    char newChar = static_cast<char>(charUnicode);
    m_Equation.insert(m_CursorIndex, 1, newChar);
    m_CursorIndex++;
}


void Calculator::removeCharBeforeCursor()
{
    if (m_CursorIndex && m_Equation.length()) {
        m_Equation.replace(--m_CursorIndex, 1, "");
    }
}


const char* Calculator::getEquation() const
{
    return m_Equation.c_str();
}


size_t Calculator::getCursorIndex()
{
    return m_CursorIndex;
}


void Calculator::moveCursor(int offset)
{
    m_CursorIndex += offset;

    if (m_CursorIndex > m_Equation.size()) {
        if (offset > 0)
            m_CursorIndex = m_Equation.size();
        else
            m_CursorIndex = 0;
    }
}


// Returns a stack of operations in infix order
std::deque<Token> Calculator::m_ParseStrEquation(std::string equation)
{
    std::deque<Token> output{};
    std::string tempDigit{};

    for (char& _char : equation) {
        if (std::isdigit(_char) || _char == '.')
            tempDigit += _char;

        else if (m_Operators.count(_char) || _char == ')') {
            if (!tempDigit.empty()) {
                output.push_back(Token(std::stod(tempDigit)));
                tempDigit.clear();
            }
            output.push_back(Token(_char));
        }

        else if (_char == '(')
            output.push_back(Token(_char));
    }

    if (!tempDigit.empty())
        output.push_back(Token(std::stod(tempDigit)));

    return output;
}


// Returns a stack of operations in postfix order
std::deque<Token> Calculator::m_InfixToPostfix(std::deque<Token> infixStack)
{
    std::deque<Token> output{};
    std::deque<Token> operatorStack{};

    while (!infixStack.empty()) {
        Token token = infixStack.front();
        infixStack.pop_front();

        if (token.Char == '\0')
            output.push_back(token);

        else if (m_Operators.count(token.Char)) {
            while (!operatorStack.empty() && operatorStack.back().Char != '(') {
                int p1 = m_Precedence.at(operatorStack.back().Char);
                int p2 = m_Precedence.at(token.Char);
                if ((p1 > p2) || (p1 == p2 && m_Operators.at(token.Char) == false)) {
                    output.push_back(operatorStack.back());
                    operatorStack.pop_back();
                }
                else break;
            }
            operatorStack.push_back(token);
        }

        else if (token.Char == '(')
            operatorStack.push_back(token);

        else if (token.Char == ')') {
            while (operatorStack.back().Char != '(') {
                output.push_back(operatorStack.back());
                operatorStack.pop_back();
            }
            operatorStack.pop_back();
        }
    }

    while (!operatorStack.empty()) {
        output.push_back(operatorStack.back());
        operatorStack.pop_back();
    }

    return output;
}


// Gives a result to a stack of postfix operations
double Calculator::m_EvaluatePostfix(std::deque<Token> postfixStack)
{
    std::deque<double> outputStack{};

    for (Token& token : postfixStack) {
        if (token.Char == '\0')
            outputStack.push_back(token.Number);

        else {
            double b = outputStack.back();
            outputStack.pop_back();

            if (!outputStack.empty()) {
                double a = outputStack.back();
                outputStack.pop_back();

                switch (token.Char) {
                    case '-': outputStack.push_back(a - b); break;
                    case '+': outputStack.push_back(a + b); break;
                    case '*': outputStack.push_back(a * b); break;
                    case '/': outputStack.push_back(a / b); break;
                    case '^': outputStack.push_back(powl(a, b)); break;
                }
            }
            else {
                switch (token.Char) {
                    case '-': outputStack.push_back(-b); break;
                }
            }
        }
    }

    return outputStack.front();
}


void Calculator::calculate()
{
    result = m_EvaluatePostfix(m_InfixToPostfix(m_ParseStrEquation(m_Equation)));
}
