//
// Created by taxis on 2023-09-26.
//

#include "VMWare.hpp"

#include "../../utils/registry/Registry.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"
#include "../../utils/registry/RegistryException.hpp"

#include <Windows.h>
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

static std::vector<std::string> SERVICES = {
        "VMTools",
        "VMware Physical Disk Helper Service",
        "VMware Snapshot Provider",
        "VMware Tools",
        "VMware User Process",
        "VMware VGAuth",
        "VMwareHostd",
        "VMwareHostdUser",
        "VMwareNatService",
        "VMwarePhysicalDisk",
        "VMwareVMAFD",
        "VMwareVCMSDS",
        "VMwareVpxdVmdir",
        "VMwareVsanHealthSvc",
        "VMwareVsanVmkctlHost",
        "VMwareVsanVmkctlVsanet",
        "VMwareVsanvp"
};

void VMWare::CreateFakeFiles() {
    for (const auto& file : FILES) {
        try {
            WinUtils::WriteFile(file, "VMWARE SPOOFING");
            Logs::Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void VMWare::CreateFakeRegistryKeys() {
    for (const auto& key : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(key.c_str());
            Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"VMWARE SPOOFING", L"VMWARE SPOOFING", hkey);
        } catch (RegistryException& e) {
            Logs::Error(e.what());
        }
    }
}

void VMWare::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void VMWare::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe);
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void VMWare::CreateFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::CreateFakeService(service);
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}
