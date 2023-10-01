#include <iostream>

//#define USING_GUI

#include "utils/windows/admin.hpp"

#ifdef USING_GUI
    #include "gui/GUI.hpp"
#else
    #include <iostream>
    #include "VMs/VMManager.hpp"
    #include "GUI/CLI.hpp"
    #include "utils/common/logging.hpp"
#endif

int main() {
    if (!Admin::isAdmin()) {
        Logs::Error("You need to run this program as administrator!");
        return 1;
    }
#ifdef USING_GUI
    GUI::CreateGUI();
#else
    CLI::CreateCLI();
    CLI::Choices();
#endif
    return 0;
}
