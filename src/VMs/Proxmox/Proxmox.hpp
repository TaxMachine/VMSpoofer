//
// Created by TaxMachine on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_PROXMOX_HPP
#define HOSTVMSPOOFER_PROXMOX_HPP

#include <map>
#include <vector>

namespace Proxmox {
    /*
     * Patching Functions
     */

    /**
     * Create fake files to spoof as Proxmox
     */
    void CreateFakeFiles();

    /**
     * Create fake processes to spoof as Proxmox
     */
    void CreateFakeProcesses();

    /**
     * Create fake registry keys to spoof as Proxmox
     */
    void CreateFakeRegistryKeys();

    /**
     * Create fake services to spoof as Proxmox
     */
    void CreateFakeServices();
}

#endif //HOSTVMSPOOFER_PROXMOX_HPP
