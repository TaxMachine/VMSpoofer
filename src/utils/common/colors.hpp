//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_COLORS_HPP
#define HOSTVMSPOOFER_COLORS_HPP

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define CLEAR "\033[2J\033[1;1H"

#include <string>

class Colors {
    public:
        Colors(int r, int g, int b);
        std::string GetTerminal() const;
        void Clear();
    private:
        int r;
        int g;
        int b;
};

#endif //HOSTVMSPOOFER_COLORS_HPP
