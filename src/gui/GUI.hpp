//
// Created by taxis on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_GUI_HPP
//#define HOSTVMSPOOFER_GUI_HPP

#include <map>

namespace GUI {
    void CreateGUI();
    void UpdateGUI(std::map<const char*, bool> spoofingOptions);
}

#endif //HOSTVMSPOOFER_GUI_HPP
