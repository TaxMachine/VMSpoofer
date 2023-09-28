#include <iostream>
#include <map>

#include "VMs/VMWare/VMWare.hpp"

#include "utils/windows/admin.hpp"
//#include "gui/GUI.hpp"

int main() {
    if (!Admin::isAdmin()) {
        std::cout << "Please run this program as administrator" << std::endl;
        return 1;
    }
    std::map<const char*, bool> buttons = {
            {"vmware", false},
            {"vbox", false},
            {"qemu", false},
            {"proxmox", false},
            {"vsphere", false}
    };
    /*GUI::CreateGUI();
    while (true) {
        GUI::UpdateGUI(buttons);
        if (buttons["vmware"]) {
            VMWare::CreateFakeFiles();
            VMWare::CreateFakeRegistryKeys();
        } else {
            VMWare::RemoveFakeFiles();
            VMWare::RemoveFakeRegistryKeys();
        }
    }*/
    return 0;
}
