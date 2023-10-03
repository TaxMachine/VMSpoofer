//
// Created by taxis on 2023-09-26.
//

#include "VirtualBox.hpp"

#include <string>
#include <vector>
#include <filesystem>
#include <map>
#include <thread>

#include "../../utils/common/parser.hpp"
#include "../../utils/windows/winutils.hpp"
#include "../../utils/registry/Registry.hpp"
#include "../../utils/registry/RegistryException.hpp"
#include "../../utils/common/logging.hpp"


static std::map<std::string, std::string> REGKEYS = {
        {"HKLM", R"(SOFTWARE\Oracle\VirtualBox Guest Additions)"},
        {"HKLM", R"(HARDWARE\ACPI\DSDT\VBOX__)"},
        {"HKLM", R"(HARDWARE\ACPI\FADT\VBOX__)"},
        {"HKLM", R"(HARDWARE\ACPI\RSDT\VBOX__)"},
        {"HKLM", R"(SYSTEM\ControlSet001\Services\VBoxGuest)"},
        {"HKLM", R"(SYSTEM\ControlSet001\Services\VBoxMouse)"},
        {"HKLM", R"(SYSTEM\ControlSet001\Services\VBoxService)"},
        {"HKLM", R"(SYSTEM\ControlSet001\Services\VBoxSF)"},
        {"HKLM", R"(SYSTEM\ControlSet001\Services\VBoxVideo)"}
};

static std::vector<std::string> FILENAMES = {
        R"(C:\Windows\system32\drivers\VBoxMouse.sys)", R"(C:\Windows\system32\drivers\VBoxGuest.sys)",
        R"(C:\Windows\system32\drivers\VBoxSF.sys)",R"(C:\Windows\system32\drivers\VBoxVideo.sys)",
        R"(C:\Windows\system32\vboxdisp.dll)", R"(C:\Windows\system32\vboxhook.dll)", R"(C:\Windows\system32\vboxmrxnp.dll)",
        R"(C:\Windows\system32\vboxogl.dll)", R"(C:\Windows\system32\vboxoglarrayspu.dll)", R"(C:\Windows\system32\vboxoglcrutil.dll)",
        R"(C:\Windows\system32\vboxoglerrorspu.dll)", R"(C:\Windows\system32\vboxoglfeedbackspu.dll)", R"(C:\Windows\system32\vboxoglpackspu.dll)",
        R"(C:\Windows\system32\vboxoglpassthroughspu.dll)", R"(C:\Windows\system32\vboxservice.exe)", R"(C:\Windows\system32\vboxtray.exe)",
        R"(C:\Windows\system32\VBoxControl.exe)", R"(C:\Windows\system32\VBoxCredProv.dll)", R"(C:\Windows\system32\VBoxDD.dll)",
        R"(C:\Windows\system32\VBoxDD2.dll)", R"(C:\Windows\system32\VBoxDDR0.r0)", R"(C:\Windows\system32\VBoxDDR3.r0)",
        R"(C:\Windows\system32\VBoxDGA.dll)", R"(C:\Windows\system32\VBoxDisp.dll)", R"(C:\Windows\system32\VBoxDispD3D.dll)",
        R"(C:\Windows\system32\VBoxDtrace.dll)", R"(C:\Windows\system32\VBoxGA.dll)", R"(C:\Windows\system32\VBoxHook.dll)",
        R"(C:\Windows\system32\VBoxMRXNP.dll)", R"(C:\Windows\system32\VBoxOGL.dll)", R"(C:\Windows\system32\VBoxOGLarrayspu.dll)",
        R"(C:\Windows\system32\VBoxOGLcrutil.dll)"
};

static std::vector<std::string> DIRECTORIES = {
        R"(C:\program files\oracle\virtualbox guest additions\)"
};

static std::vector<std::string> PROCESSES = {
        "vboxservices.exe",
        "vboxservice.exe",
        "vboxtray.exe",
        "vboxcontrol.exe"
};

static std::vector<std::string> NAMED_PIPES = {
        R"(\\.\pipe\VBoxMiniRdDN)",
        R"(\\.\pipe\VBoxTrayIPC)"
};

static std::vector<std::string> SERVICES = {
        "VBoxGuest",
        "VBoxMouse",
        "VBoxService",
        "VBoxSF",
        "VBoxVideo"
};

static Logger LOGGER = Logger(typeid(VirtualBox).name());

void VirtualBox::CreateFakeFiles() {
    for (const auto& file : FILENAMES) {
        try {
            WinUtils::WriteFile(file, "VIRTUALBOX FAKE FILE");
            LOGGER.Success(("Created file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::CreateFakeRegistryKeys() {
    for (const auto& [regnamespace, key] : REGKEYS) {
        try {
            HKEY hkey = Registry::GetHKeyFromString(regnamespace.c_str());
            Registry::CreateRegistryKey((const wchar_t *) key.c_str(), hkey);
            Registry::WriteRegistryString((const wchar_t *) key.c_str(), L"VIRTUALBOX FAKE REGISTRY KEY", L"VIRTUALBOX FAKE REGISTRY VALUE", hkey);
            LOGGER.Success(("Created registry key: " + key).c_str());
        } catch (RegistryException& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::CreateFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::SpawnFakeProcess(process);
            LOGGER.Success(("Created process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::CreateFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::SpawnNamedPipe(pipe, Parser::SplitString(pipe, '\\').back());
            LOGGER.Success(("Created named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::CreateFakeServices() {
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

void VirtualBox::DeleteFakeFiles() {
    for (const auto& file : FILENAMES) {
        try {
            std::filesystem::remove(file);
            LOGGER.Success(("Deleted file: " + file).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::DeleteFakeRegistryKeys() {
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

void VirtualBox::KillFakeProcesses() {
    for (const auto& process : PROCESSES) {
        try {
            WinUtils::KillProcess(process);
            LOGGER.Success(("Killed process: " + process).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::DeleteFakeNamedPipes() {
    for (const auto& pipe : NAMED_PIPES) {
        try {
            WinUtils::KillNamedPipe(pipe);
            LOGGER.Success(("Deleted named pipe: " + pipe).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

void VirtualBox::DeleteFakeServices() {
    for (const auto& service : SERVICES) {
        try {
            WinUtils::KillFakeService(service);
            LOGGER.Success(("Deleted service: " + service).c_str());
        } catch (std::exception& e) {
            LOGGER.Error(e.what());
        }
    }
}

