//
// Created by taxis on 2023-09-27.
//

#include "admin.hpp"

#include <windows.h>
#include <stdexcept>
#include <filesystem>

#include "winutils.hpp"

bool Admin::isAdmin() {
    BOOL fIsRunAsAdmin = FALSE;
    DWORD dwError = ERROR_SUCCESS;
    PSID pAdministratorsGroup = nullptr;

    SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
    if (!AllocateAndInitializeSid(
            &NtAuthority,
            2,
            SECURITY_BUILTIN_DOMAIN_RID,
            DOMAIN_ALIAS_RID_ADMINS,
            0,
            0,
            0,
            0,
            0,
            0,
            &pAdministratorsGroup)) {
        dwError = GetLastError();
        goto Cleanup;
    }

    if (!CheckTokenMembership(
            nullptr,
            pAdministratorsGroup,
            &fIsRunAsAdmin)) {
        dwError = GetLastError();
        goto Cleanup;
    }

    Cleanup:
    if (pAdministratorsGroup) {
        FreeSid(pAdministratorsGroup);
        pAdministratorsGroup = nullptr;
    }

    if (ERROR_SUCCESS != dwError) {
        throw std::runtime_error("Could not determine if user is admin");
    }

    return fIsRunAsAdmin;
}

void Admin::createConfigFolder() {
    std::string directory = getenv("USERPROFILE") + std::string("\\.hostvm");
    std::filesystem::create_directories(directory);
    std::filesystem::create_directory(directory + "\\processes");
    std::filesystem::create_directory(directory + "\\services");
    std::filesystem::create_directory(directory + "\\namedpipes");
    if (!std::filesystem::exists(directory + "\\config.ini"))
        WinUtils::WriteFile(directory + "\\config.ini", "VMWare=false\nVirtualBox=false\nVSphere=false\nProxmox=false\nQemu=false\n");
}