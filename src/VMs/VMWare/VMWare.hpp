//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VMWARE_HPP
#define HOSTVMSPOOFER_VMWARE_HPP

namespace VMWare {
    /*
     * Patching Functions
     */

    /**
     * Patch the registry to spoof as VMWare
     */
    void CreateFakeRegistryKeys();

    /**
     * Patch the files to spoof as VMWare
     */
    void CreateFakeFiles();

    /**
     * Create fake processes to spoof as VMWare
     */
    void CreateFakeProcesses();

    /**
     * Create fake named pipes to spoof as VMWare
     */
    void CreateFakeNamedPipes();

    /**
     * Create fake services to spoof as VMWare
     */
    void CreateFakeServices();



    /**
     * Remove fake registry keys
     */
    void RemoveFakeRegistryKeys();

    /**
     * Remove fake files
     */
    void RemoveFakeFiles();

    /**
     * Remove fake processes
     */
    void RemoveFakeProcesses();

    /**
     * Remove fake named pipes
     */
    void RemoveFakeNamedPipes();

    /**
     * Remove fake services
     */
    void RemoveFakeServices();
}

#endif //HOSTVMSPOOFER_VMWARE_HPP

