//
// Created by TaxMachine on 2023-09-28.
//

#include "Proxmox.hpp"

#include <vector>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/registry/RegistryException.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"

static std::vector<std::string> FILENAME = {};

static std::vector<std::string> REGKEYS = {
        R"(HKLM\SYSTEM\Setup\Upgrade\PnP\CurrentControlSet\Control\DeviceMigration\Devices\ACPI\QEMUVGID)",
};

static std::vector<std::string> PROCESSES = {
        "qm.exe",
        "pveproxy.exe",
        "pvedaemon.exe",
        "pvestatd.exe",
        "pvefw.exe",
        "pve-ha-crm.exe",
        "pve-ha-lrm.exe",
        "pve-ha-lrm-mon.exe",
        "pve-ha-crm-fence.exe",
        "pve-ha-crm-pengine.exe",
        "pve-ha-crm-stonith.exe",
        "pve-ha-crm-stonith-ng.exe",
        "pve-ha-crm-stonith-ng-listener.exe"
};

static std::vector<std::string> SERVICES = {};

static std::vector<std::string> NAMED_PIPES = {};

void Proxmox::CreateFakeFiles() {
    for (const auto& file : FILENAME) {
        try {
            WinUtils::WriteFile(file, "PROXMOX SPOOFING");
            Logs::Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void Proxmox::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
            Logs::Success(("Created process: " + process).c_str());
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void Proxmox::CreateFakeRegistryKeys() {
    for (const auto& regkey : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regkey.c_str());
            Registry::CreateRegistryKey((const wchar_t *) regkey.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) regkey.c_str(), L"PROXMOX SPOOFING", L"PROXMOX SPOOFING",
                                          hkey);
            Logs::Success(("Created registry key: " + regkey).c_str());
        } catch (RegistryException& e) {
            Logs::Error(e.what());
        }
    }
}

void Proxmox::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe);
            Logs::Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}

void Proxmox::CreateFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::CreateFakeService(service);
            Logs::Success(("Created service: " + service).c_str());
        } catch (std::exception& e) {
            Logs::Error(e.what());
        }
    }
}
