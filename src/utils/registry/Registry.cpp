//
// Created by taxis on 2023-09-26.
//

#include "Registry.hpp"

#include <Windows.h>
#include "RegistryException.hpp"

// Write a string value
void Registry::WriteRegistryString(const wchar_t* subkey,
                         const wchar_t* valueName,
                         const wchar_t* value) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(
            HKEY_CURRENT_USER,
            reinterpret_cast<LPCSTR>(subkey),
            0,
            KEY_SET_VALUE,
            &hKey);
    if (result != ERROR_SUCCESS)
        throw RegistryException("Could not open registry key", result);
    result = RegSetValueEx(
            hKey,
            reinterpret_cast<LPCSTR>(valueName),
            0,
            REG_SZ,
            (BYTE*)value,
            (lstrlen(reinterpret_cast<LPCSTR>(value)) + 1) * sizeof(TCHAR));
    RegCloseKey(hKey);
}

// Read a string value
void Registry::ReadRegistryString(const wchar_t* subkey,
                        const wchar_t* valueName,
                        wchar_t*value, DWORD size) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(
            HKEY_CURRENT_USER,
            reinterpret_cast<LPCSTR>(subkey),
            0,
            KEY_QUERY_VALUE,
            &hKey);
    if (result != ERROR_SUCCESS)
        throw RegistryException("Could not open registry key", result);
    DWORD dataType;
    DWORD dataSize = size;
    result = RegQueryValueEx(
            hKey,
            reinterpret_cast<LPCSTR>(valueName),
            nullptr,
            &dataType,
            (LPBYTE)value,
            &dataSize);
    RegCloseKey(hKey);
}

// Write a DWORD value
void Registry::WriteRegistryDWORD(const wchar_t* subkey,
                        const wchar_t* valueName,
                        DWORD value) {
    HKEY hKey;
    LONG result = RegOpenKeyEx(
            HKEY_CURRENT_USER,
            reinterpret_cast<LPCSTR>(subkey),
            0,
            KEY_SET_VALUE,
            &hKey);
    if (result != ERROR_SUCCESS)
        throw RegistryException("Could not open registry key", result);
    result = RegSetValueEx(
            hKey,
            reinterpret_cast<LPCSTR>(valueName),
            0,
            REG_DWORD,
            (const BYTE*)&value,
            sizeof(DWORD));
    RegCloseKey(hKey);
}

// Read a DWORD value
DWORD Registry::ReadRegistryDWORD(const wchar_t* subkey,
                        const wchar_t* valueName) {
    HKEY hKey;
    DWORD result;
    LONG openResult = RegOpenKeyEx(
            HKEY_CURRENT_USER,
            reinterpret_cast<LPCSTR>(subkey),
            0,
            KEY_QUERY_VALUE,
            &hKey);
    if (openResult != ERROR_SUCCESS)
        throw RegistryException("Could not open registry key", openResult);

    DWORD dwType = REG_DWORD;
    DWORD cbData = sizeof(DWORD);
    LONG queryResult = RegQueryValueEx(
            hKey,
            reinterpret_cast<LPCSTR>(valueName),
            nullptr,
            &dwType,
            (LPBYTE)&result,
            &cbData);
    if (queryResult != ERROR_SUCCESS)
        throw RegistryException("Could not read registry value", queryResult);
    RegCloseKey(hKey);
    return result;
}