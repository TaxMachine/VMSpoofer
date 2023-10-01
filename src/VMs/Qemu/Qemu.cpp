//
// Created by taxis on 2023-09-28.
//

#include "Qemu.hpp"

#include <string>
#include <vector>
#include <windows.h>

#include "../../utils/registry/Registry.hpp"
#include "../../utils/windows/winutils.hpp"

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


void Qemu::CreateFakeFiles() {
    for (const auto& file : FILES) {
        WinUtils::WriteFile(file, "QEMU FAKE FILE");
    }
}

void Qemu::CreateFakeRegistryKeys() {
    for (const auto& key : REGISTRY) {
        HKEY hkey = key.starts_with("HKLM") ? HKEY_LOCAL_MACHINE : HKEY_CURRENT_USER;
        Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
        Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"QEMU FAKE REGISTRY KEY", L"QEMU FAKE REGISTRY VALUE", hkey);
    }
}

void Qemu::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        WinUtils::SpawnFakeProcess(process);
    }
}

void Qemu::CreateFakeServices() {
    for (const auto& service : SERVICES) {
        WinUtils::CreateFakeService(service);
    }
}

void Qemu::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPE) {

    }
}
