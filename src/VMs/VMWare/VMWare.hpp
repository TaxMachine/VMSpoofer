//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VMWARE_HPP
#define HOSTVMSPOOFER_VMWARE_HPP

#include <string>
#include <vector>


static std::vector<std::string> REGKEYS = {
        R"(HKEY_LOCAL_MACHINE\SOFTWARE\VMware, Inc.\VMware Tools)"
};

static std::vector<std::string> FILES = {
        R"(C:\Windows\system32\drivers\vmmouse.sys)",
        R"(C:\Windows\system32\drivers\vmhgfs.sys)",
        R"(C:\Windows\system32\drivers\vmusbmouse.sys)",
        R"(C:\Windows\system32\drivers\vmkdb.sys)",
        R"(C:\Windows\system32\drivers\vmrawdsk.sys)",
        R"(C:\Windows\system32\drivers\vmmemctl.sys)",
        R"(C:\Windows\system32\drivers\vm3dmp.sys)"
};

static std::vector<std::string> PROCESSES = {
        "vmtoolsd.exe",
        "xenservice.exe",
        "VMSrvc.exe",
        "VMUSrvc.exe"
};

static std::vector<std::string> NAMED_PIPES = {
        R"(\\.\pipe\VBoxMiniRdDN)",
        R"(\\.\pipe\VBoxTrayIPC)"
};

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

