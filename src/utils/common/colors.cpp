//
// Created by TaxMachine on 2023-10-01.
//

#include "colors.hpp"

#include <string>

Colors::Colors(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

std::string Colors::GetTerminal() const {
    return (std::string("\033[38;2;") +
            std::to_string(this->r) + ";" +
            std::to_string(this->g) + ";" +
            std::to_string(this->b) + "m");
}