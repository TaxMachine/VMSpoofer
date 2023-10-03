//
// Created by TaxMachine on 2023-09-28.
//

#include "Proxmox.hpp"

#include <vector>
#include <filesystem>
#include <map>
#include <thread>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/registry/RegistryException.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"

static std::vector<std::string> FILENAME = {};

static std::map<std::string, std::string> REGKEYS = {
        {"HKLM", R"(\SYSTEM\Setup\Upgrade\PnP\CurrentControlSet\Control\DeviceMigration\Devices\ACPI\QEMUVGID)"}
};

static std::vector<std::string> PROCESSES = {
        "qm.exe", "pveproxy.exe", "pvedaemon.exe",
        "pvestatd.exe", "pvefw.exe", "pve-ha-crm.exe",
        "pve-ha-lrm.exe", "pve-ha-lrm-mon.exe",
        "pve-ha-crm-fence.exe", "pve-ha-crm-pengine.exe",
        "pve-ha-crm-stonith.exe", "pve-ha-crm-stonith-ng.exe",
        "pve-ha-crm-stonith-ng-listener.exe"
};

static std::vector<std::string> SERVICES = {};

static std::vector<std::string> NAMED_PIPES = {};

static Logger LOGGER = Logger(typeid(Proxmox).name());

void Proxmox::CreateFakeFiles() {
    for (const auto& file : FILENAME) {
        try {
            WinUtils::WriteFile(file, "PROXMOX SPOOFING");
            LOGGER.Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
            LOGGER.Success(("Created process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::CreateFakeRegistryKeys() {
    for (const auto& [regnamespace, regkey] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::CreateRegistryKey((const wchar_t *) regkey.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) regkey.c_str(), L"PROXMOX SPOOFING", L"PROXMOX SPOOFING", hkey);
            LOGGER.Success(("Created registry key: " + regkey).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe, "proxmox.exe");
            LOGGER.Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::CreateFakeServices() {
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

void Proxmox::DeleteFakeFiles() {
    for (const auto& file : FILENAME) {
        try {
            std::filesystem::remove(file);
            LOGGER.Success(("Deleted file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::DeleteFakeRegistryKeys() {
    for (const auto& [regnamespace, regkey] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::DeleteRegistryKey((const wchar_t *) regkey.c_str(), hkey);
            LOGGER.Success(("Deleted registry key: " + regkey).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::KillFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::KillProcess(process);
            LOGGER.Success(("Killed process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::DeleteFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::KillNamedPipe(pipe);
            LOGGER.Success(("Deleted named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Proxmox::DeleteFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::KillFakeService(service);
            LOGGER.Success(("Deleted service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}
