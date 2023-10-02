#include <iostream>

//#define USING_GUI

#include "utils/windows/admin.hpp"

#ifdef USING_GUI
    #include "gui/GUI.hpp"
#else
    #include "GUI/CLI.hpp"
    #include "utils/common/logging.hpp"
#endif

static Logger LOGGER("main");

int main() {
    if (!Admin::isAdmin()) {
        LOGGER.Error("You need to run this program as administrator!");
        return 1;
    }
    Admin::createConfigFolder();
#ifdef USING_GUI
    GUI::CreateGUI();
#else
    CLI::CreateCLI();
    CLI::Choices();
#endif
    return 0;
}
