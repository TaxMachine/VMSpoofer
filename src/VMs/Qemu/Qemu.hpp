//
// Created by taxis on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_QEMU_HPP
#define HOSTVMSPOOFER_QEMU_HPP

#include <string>
#include <vector>

static std::vector<std::string> PROCESSES = {
        "qemu-ga.exe",
        "prl_cc.exe",
        "prl_tools.exe",
        "prl_tools_service.exe",
        "prl_hookhelper.exe",
        "prl_client_app.exe"
};

static std::vector<std::string> REGISTRY = {};

namespace Qemu {
    /*
     * Patching Functions
     */

    /**
     * Create fake processes to spoof as Qemu
     */
    void CreateFakeProcesses();
}

#endif //HOSTVMSPOOFER_QEMU_HPP
