//
// Created by TaxMachine on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_PROXMOX_HPP
#define HOSTVMSPOOFER_PROXMOX_HPP

#include <map>
#include <vector>

namespace Proxmox {
    void CreateFakeFiles();
    void CreateFakeProcesses();
    void CreateFakeRegistryKeys();
    void CreateFakeServices();
}

#endif //HOSTVMSPOOFER_PROXMOX_HPP
