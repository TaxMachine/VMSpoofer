//
// Created by taxis on 2023-09-26.
//

#include "VMWare.hpp"

#include <filesystem>
#include <string>
#include <vector>
#include <map>
#include <thread>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"
#include "../../utils/registry/RegistryException.hpp"
#include "../../utils/common/parser.hpp"

static std::map<std::string, std::string> REGKEYS = {
        {"HKLM", R"(SOFTWARE\VMware, Inc.\VMware Tools)"}
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
        "vm3dservice.exe"
};

static std::vector<std::string> NAMED_PIPES = {};

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

static Logger LOGGER = Logger(typeid(VMWare).name());

void VMWare::CreateFakeFiles() {
    for (const auto& file : FILES) {
        try {
            WinUtils::WriteFile(file, "VMWARE SPOOFING");
            LOGGER.Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::CreateFakeRegistryKeys() {
    for (const auto& [regnamespace, key] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"VMWARE SPOOFING", L"VMWARE SPOOFING", hkey);
            LOGGER.Success(("Created registry key: " + key).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
            LOGGER.Success(("Created process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe, Parser::SplitString(pipe, '\\').back());
            LOGGER.Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::CreateFakeServices() {
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

void VMWare::DeleteFakeFiles() {
    for (const auto& file : FILES) {
        try {
            std::filesystem::remove(file);
            LOGGER.Success(("Deleted file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::DeleteFakeRegistryKeys() {
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

void VMWare::KillFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::KillProcess(process);
            LOGGER.Success(("Killed process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::DeleteFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::KillNamedPipe(pipe);
            LOGGER.Success(("Deleted named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VMWare::DeleteFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::KillFakeService(service);
            LOGGER.Success(("Deleted service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}
