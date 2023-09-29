#include <iostream>

#include "utils/windows/admin.hpp"
#include "gui/GUI.hpp"


int main() {
    if (!Admin::isAdmin()) {
        std::cout << "Please run this program as administrator" << std::endl;
        return 1;
    }
    GUI::CreateGUI();
    return 0;
}
