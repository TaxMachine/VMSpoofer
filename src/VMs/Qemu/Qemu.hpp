//
// Created by taxis on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_QEMU_HPP
#define HOSTVMSPOOFER_QEMU_HPP

namespace Qemu {
    /*
     * Patching Functions
     */

    void CreateFakeFiles();

    /**
     * Create fake registry keys to spoof as Qemu
     * @note The registry keys are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeRegistryKeys();

    /**
     * Create fake processes to spoof as Qemu
     * @note The processes are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeProcesses();

    /**
     * Create fake services to spoof as Qemu
     * @note The services are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeServices();
}

#endif //HOSTVMSPOOFER_QEMU_HPP
