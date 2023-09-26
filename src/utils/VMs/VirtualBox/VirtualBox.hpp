//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VIRTUALBOX_HPP
#define HOSTVMSPOOFER_VIRTUALBOX_HPP

#include <string>
#include <vector>

static std::vector<std::string> REGKEYS = {
        R"(SOFTWARE\Oracle\VirtualBox Guest Additions)",
        R"(HARDWARE\ACPI\DSDT\VBOX__)",
        R"(HARDWARE\ACPI\FADT\VBOX__)",
        R"(HARDWARE\ACPI\RSDT\VBOX__)",
        R"(SYSTEM\ControlSet001\Services\VBoxGuest)",
        R"(SYSTEM\ControlSet001\Services\VBoxMouse)",
        R"(SYSTEM\ControlSet001\Services\VBoxService)",
        R"(SYSTEM\ControlSet001\Services\VBoxSF)",
        R"(SYSTEM\ControlSet001\Services\VBoxVideo)"
};

static std::vector<std::string> FILENAMES = {
        R"(C:\WINDOWS\system32\drivers\VBoxMouse.sys)",
        R"(C:\WINDOWS\system32\drivers\VBoxGuest.sys)",
        R"(C:\WINDOWS\system32\drivers\VBoxSF.sys)",
        R"(C:\WINDOWS\system32\drivers\VBoxVideo.sys)",
        R"(C:\WINDOWS\system32\vboxdisp.dll)",
        R"(C:\WINDOWS\system32\vboxhook.dll)",
        R"(C:\WINDOWS\system32\vboxmrxnp.dll)",
        R"(C:\WINDOWS\system32\vboxogl.dll)",
        R"(C:\WINDOWS\system32\vboxoglarrayspu.dll)",
        R"(C:\WINDOWS\system32\vboxoglcrutil.dll)",
        R"(C:\WINDOWS\system32\vboxoglerrorspu.dll)",
        R"(C:\WINDOWS\system32\vboxoglfeedbackspu.dll)",
        R"(C:\WINDOWS\system32\vboxoglpackspu.dll)",
        R"(C:\WINDOWS\system32\vboxoglpassthroughspu.dll)",
        R"(C:\WINDOWS\system32\vboxservice.exe)",
        R"(C:\WINDOWS\system32\vboxtray.exe)",
        R"(C:\WINDOWS\system32\VBoxControl.exe)",
        R"(C:\WINDOWS\system32\VBoxCredProv.dll)",
        R"(C:\WINDOWS\system32\VBoxDD.dll)",
        R"(C:\WINDOWS\system32\VBoxDD2.dll)",
        R"(C:\WINDOWS\system32\VBoxDDR0.r0)",
        R"(C:\WINDOWS\system32\VBoxDDR3.r0)",
        R"(C:\WINDOWS\system32\VBoxDGA.dll)",
        R"(C:\WINDOWS\system32\VBoxDisp.dll)",
        R"(C:\WINDOWS\system32\VBoxDispD3D.dll)",
        R"(C:\WINDOWS\system32\VBoxDtrace.dll)",
        R"(C:\WINDOWS\system32\VBoxGA.dll)",
        R"(C:\WINDOWS\system32\VBoxHook.dll)",
        R"(C:\WINDOWS\system32\VBoxMRXNP.dll)",
        R"(C:\WINDOWS\system32\VBoxOGL.dll)",
        R"(C:\WINDOWS\system32\VBoxOGLarrayspu.dll)",
        R"(C:\WINDOWS\system32\VBoxOGLcrutil.dll)",
};

static std::vector<std::string> PROCESSES = {
        "vboxservices.exe",
        "vboxservice.exe",
        "vboxtray.exe",
        "vboxcontrol.exe"
};

#endif //HOSTVMSPOOFER_VIRTUALBOX_HPP
