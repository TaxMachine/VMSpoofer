//
// Created by taxis on 2023-09-28.
//

#include "Qemu.hpp"

#include <string>
#include <vector>
#include <windows.h>
#include <filesystem>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/common/logging.hpp"
#include "../../utils/registry/RegistryException.hpp"

static std::vector<std::string> PROCESSES = {
        "qemu-ga.exe",
        "prl_cc.exe",
        "prl_tools.exe",
        "prl_tools_service.exe",
        "prl_hookhelper.exe",
        "prl_client_app.exe"
};

static std::vector<std::string> REGISTRY = {
        R"(HKLM\HARDWARE\ACPI\DSDT\QEMU0001)",
        R"(HKLM\HARDWARE\ACPI\FADT\QEMU0001)",
        R"(HKLM\HARDWARE\ACPI\RSDT\QEMU0001)",
        R"(HKCU\SOFTWARE\QEMU-GA)",
        R"(HKCU\SOFTWARE\QEMU-GA)",
        R"(HKCU\SOFTWARE\Red Hat\qemu-ga)"
};

static std::vector<std::string> FILES = {
        R"(C:\Windows\system32\drivers\qemu-ga.sys)",
        R"(C:\Windows\system32\drivers\prl_fs.sys)",
        R"(C:\Windows\system32\drivers\prl_mouf.sys)",
        R"(C:\Windows\system32\drivers\prl_paravirt.sys)",
        R"(C:\Windows\system32\drivers\prl_tg.sys)",
        R"(C:\Windows\system32\drivers\prl_time.sys)",
        R"(C:\Windows\system32\drivers\prl_vnic.sys)",
        R"(C:\Windows\system32\drivers\prl_vtdhook.sys)",
        R"(C:\Windows\system32\drivers\prl_hid_hook.sys)",
        R"(C:\Windows\system32\drivers\prl_hypervisor.sys)",
        R"(C:\Windows\system32\drivers\prl_kbd.sys)",
        R"(C:\Windows\system32\drivers\prl_usb_connect.sys)",
        R"(C:\Windows\system32\drivers\prl_ethdrvx.sys)",
        R"(C:\Windows\system32\drivers\prl_mou.sys)",
        R"(C:\Windows\system32\drivers\prl_pv32.sys)",
        R"(C:\Windows\system32\drivers\prl_tg_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_vnicx.sys)",
        R"(C:\Windows\system32\drivers\prl_vtdhook_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_hypervisor_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_kbd_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_usb_connect_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_ethdrv_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_mou_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_pv32_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_tg_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_vnicx_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_vtdhook_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_hypervisor_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_kbd_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_usb_connect_nopae.sys)",
        R"(C:\Windows\system32\drivers\prl_ethdrv_nopae.sys)"
};

static std::vector<std::string> NAMED_PIPE = {};

static std::vector<std::string> SERVICES = {

};

static Logger LOGGER = Logger(typeid(Qemu).name());

void Qemu::CreateFakeFiles() {
    for (const auto& file : FILES) {
        try {
            WinUtils::WriteFile(file, "QEMU FAKE FILE");
            LOGGER.Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::CreateFakeRegistryKeys() {
    for (const auto& key : REGISTRY) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(key.c_str());
            Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"QEMU FAKE REGISTRY KEY",
                                          L"QEMU FAKE REGISTRY VALUE", hkey);
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::CreateFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::CreateFakeService(service);
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPE) {
        try {
            WinUtils::SpawnNamedPipe(pipe);
            LOGGER.Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::DeleteFakeFiles() {
    for (const auto& file : FILES) {
        try {
            std::filesystem::remove(file);
            LOGGER.Success(("Deleted file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::DeleteFakeRegistryKeys() {
    for (const auto& key : REGISTRY) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(key.c_str());
            Registry::DeleteRegistryKey((const wchar_t *) key.c_str(), hkey);
            LOGGER.Success(("Deleted registry key: " + key).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::KillFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::KillProcess(process);
            LOGGER.Success(("Killed process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::DeleteFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPE) {
        try {
            WinUtils::KillNamedPipe(pipe);
            LOGGER.Success(("Deleted named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void Qemu::DeleteFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::KillFakeService(service);
            LOGGER.Success(("Deleted service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}
