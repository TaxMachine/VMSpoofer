//
// Created by taxis on 2023-09-26.
//

#include "VirtualBox.hpp"

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
        R"(C:\Windows\system32\drivers\VBoxMouse.sys)",
        R"(C:\Windows\system32\drivers\VBoxGuest.sys)",
        R"(C:\Windows\system32\drivers\VBoxSF.sys)",
        R"(C:\Windows\system32\drivers\VBoxVideo.sys)",
        R"(C:\Windows\system32\vboxdisp.dll)",
        R"(C:\Windows\system32\vboxhook.dll)",
        R"(C:\Windows\system32\vboxmrxnp.dll)",
        R"(C:\Windows\system32\vboxogl.dll)",
        R"(C:\Windows\system32\vboxoglarrayspu.dll)",
        R"(C:\Windows\system32\vboxoglcrutil.dll)",
        R"(C:\Windows\system32\vboxoglerrorspu.dll)",
        R"(C:\Windows\system32\vboxoglfeedbackspu.dll)",
        R"(C:\Windows\system32\vboxoglpackspu.dll)",
        R"(C:\Windows\system32\vboxoglpassthroughspu.dll)",
        R"(C:\Windows\system32\vboxservice.exe)",
        R"(C:\Windows\system32\vboxtray.exe)",
        R"(C:\Windows\system32\VBoxControl.exe)",
        R"(C:\Windows\system32\VBoxCredProv.dll)",
        R"(C:\Windows\system32\VBoxDD.dll)",
        R"(C:\Windows\system32\VBoxDD2.dll)",
        R"(C:\Windows\system32\VBoxDDR0.r0)",
        R"(C:\Windows\system32\VBoxDDR3.r0)",
        R"(C:\Windows\system32\VBoxDGA.dll)",
        R"(C:\Windows\system32\VBoxDisp.dll)",
        R"(C:\Windows\system32\VBoxDispD3D.dll)",
        R"(C:\Windows\system32\VBoxDtrace.dll)",
        R"(C:\Windows\system32\VBoxGA.dll)",
        R"(C:\Windows\system32\VBoxHook.dll)",
        R"(C:\Windows\system32\VBoxMRXNP.dll)",
        R"(C:\Windows\system32\VBoxOGL.dll)",
        R"(C:\Windows\system32\VBoxOGLarrayspu.dll)",
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