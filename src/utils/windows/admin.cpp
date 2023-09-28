//
// Created by taxis on 2023-09-27.
//

#include "admin.hpp"

#include <windows.h>
#include <stdexcept>

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