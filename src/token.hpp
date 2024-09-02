#pragma once


struct Token
{
    char Char = 0;
    double Number = 0.0;

    Token(char char_) : Char(char_), Number(0.0) {}
    Token(double number) : Char(0), Number(number) {}
};
