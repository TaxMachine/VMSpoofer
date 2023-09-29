//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VIRTUALBOX_HPP
#define HOSTVMSPOOFER_VIRTUALBOX_HPP

namespace VirtualBox {
    /**
     * Creates fake files from the virtualbox guest additions
     * @note The files are empty, they are just there to fool the malwares that check for them
     */
    void CreateFakeFiles();

    /**
     * Creates fake registry keys from virtualbox virtual machines
     * @note The registry keys are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeRegistryKeys();

    /**
     * Creates fake processes from virtualbox virtual machines
     * @note The processes are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeProcesses();

    /**
     * Creates fake services from virtualbox virtual machines
     * @note The services are not doing anything, they are just there to fool the malwares that check for them
     */
    void CreateFakeServices();
}

#endif //HOSTVMSPOOFER_VIRTUALBOX_HPP
