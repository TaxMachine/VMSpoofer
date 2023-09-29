//
// Created by TaxMachine on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_VSPHERE_HPP
#define HOSTVMSPOOFER_VSPHERE_HPP

namespace VSphere {
    /*
     * Patching Functions
     */

    /**
     * Patch the registry to spoof as VSphere
     */
    void CreateFakeRegistryKeys();

    /**
     * Patch the files to spoof as VSphere
     */
    void CreateFakeFiles();

    /**
     * Create fake processes to spoof as VSphere
     */
    void CreateFakeProcesses();

    /**
     * Create fake named pipes to spoof as VSphere
     */
    void CreateFakeNamedPipes();

    /**
     * Create fake services to spoof as VSphere
     */
    void CreateFakeServices();
}

#endif //HOSTVMSPOOFER_VSPHERE_HPP
