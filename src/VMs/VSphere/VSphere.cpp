//
// Created by TaxMachine on 2023-09-28.
//

#include "VSphere.hpp"

#include <filesystem>
#include <map>
#include <thread>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/registry/RegistryException.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"
#include "../../utils/common/parser.hpp"

static std::map<std::string, std::string> REGKEYS = {
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools)"},
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools\Install)"},
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools\Install\Version)"},
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools\Running)"},
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools\Version)"}
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

static std::vector<std::string> NAMED_PIPES = {};

static std::vector<std::string> SERVICES = {
        "VMTools", "VMware Physical Disk Helper Service",
        "VMware Snapshot Provider", "VMware Tools",
        "VMware User Process", "VMware VGAuth",
        "VMwareHostd", "VMwareHostdUser", "VMwareNatService",
        "VMwarePhysicalDisk", "VMwareVMAFD", "VMwareVCMSDS",
        "VMwareVpxdVmdir", "VMwareVsanHealthSvc", "VMwareVsanVmkctlHost",
        "VMwareVsanVmkctlVsanet", "VMwareVsanvp"
};

static Logger LOGGER = Logger(typeid(VSphere).name());

void VSphere::CreateFakeFiles() {
    for (const auto& file : FILES) {
        try {
            WinUtils::WriteFile(file, "VSPHERE FAKE FILE");
            LOGGER.Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::CreateFakeRegistryKeys() {
    for (const auto& [regnamespace, key] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"VSPHERE FAKE REGISTRY KEY", L"VSPHERE FAKE REGISTRY VALUE", hkey);
            LOGGER.Success(("Created registry key: " + key).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
            LOGGER.Success(("Created process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::CreateFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            std::thread service_t(WinUtils::CreateFakeService, service);
            service_t.join();
            LOGGER.Success(("Created service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe, Parser::SplitString(pipe, '\\').back());
            LOGGER.Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::DeleteFakeFiles() {
    for (const auto& file : FILES) {
        try {
            std::filesystem::remove(file);
            LOGGER.Success(("Deleted file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::DeleteFakeRegistryKeys() {
    for (const auto& [regnamespace, key] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::DeleteRegistryKey((const wchar_t *) key.c_str(), hkey);
            LOGGER.Success(("Deleted registry key: " + key).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::KillFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::KillProcess(process);
            LOGGER.Success(("Killed process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::DeleteFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::KillNamedPipe(pipe);
            LOGGER.Success(("Deleted named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VSphere::DeleteFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::KillFakeService(service);
            LOGGER.Success(("Deleted service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}