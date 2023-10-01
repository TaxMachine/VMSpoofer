//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_REGISTRY_HPP
#define HOSTVMSPOOFER_REGISTRY_HPP

#include <minwindef.h>

/**
 * Registry namespace including functions to easily read and write to the Windows registry
 */
namespace Registry {
    /**
     * Get a HKEY from a string
     * @param hkey
     * @return HKEY from string
     */
    HKEY GetHKeyFromString(const char* hkey);

    /**
     * Create a registry key
     * @param subkey subkey to create
     * @param hkey namespace to create key in
     */
    void CreateRegistryKey(const wchar_t* subkey,
                           HKEY hkey);

    /**
     * Write a string value to the registry
     * @param subkey subkey to write to
     * @param valueName key to write to
     * @param value string value to write
     * @param hkey namespace to write to
     */
    void WriteRegistryString(const wchar_t* subkey,
                             const wchar_t* valueName,
                             const wchar_t* value,
                             HKEY hkey);

    /**
     * Read a string value from the registry
     * @param subkey subkey to read from
     * @param valueName key to read from
     * @param value buffer to store value in
     * @param size size of value
     * @param hkey namespace to read from
     */
    void ReadRegistryString(const wchar_t* subkey,
                            const wchar_t* valueName,
                            wchar_t*value,
                            DWORD size,
                            HKEY hkey);

    /**
     * Write a DWORD value to the registry
     * @param subkey subkey to write to
     * @param valueName key to write to
     * @param value DWORD value to write
     * @param hkey namespace to write to
     */
    void WriteRegistryDWORD(const wchar_t* subkey,
                            const wchar_t* valueName,
                            DWORD value,
                            HKEY hkey);

    /**
     * Read a DWORD value from the registry
     * @param subkey key to read from
     * @param valueName value to read
     * @return DWORD value
     * @param hkey namespace to read from
     */
    DWORD ReadRegistryDWORD(const wchar_t* subkey,
                            const wchar_t* valueName,
                            HKEY hkey);

    /**
     * Delete a registry key
     * @param subkey key to delete
     * @param hkey namespace to delete from
     */
    void DeleteRegistryKey(const wchar_t* subkey,
                           HKEY hkey);

    /**
     * Delete a registry value
     * @param subkey key to delete value from
     * @param valueName value to delete
     * @param hkey namespace to delete from
     */
    void DeleteRegistryValue(const wchar_t* subkey,
                             const wchar_t* valueName,
                             HKEY hkey);
}

#endif //HOSTVMSPOOFER_REGISTRY_HPP
