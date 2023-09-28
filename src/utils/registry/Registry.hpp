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
     * Create a registry key
     * @param subkey subkey to create
     */
    void CreateRegistryKey(const wchar_t* subkey);

    /**
     * Write a string value to the registry
     * @param subkey subkey to write to
     * @param valueName key to write to
     * @param value string value to write
     */
    void WriteRegistryString(const wchar_t* subkey,
                             const wchar_t* valueName,
                             const wchar_t* value);

    /**
     * Read a string value from the registry
     * @param subkey subkey to read from
     * @param valueName key to read from
     * @param value buffer to store value in
     * @param size size of value
     */
    void ReadRegistryString(const wchar_t* subkey,
                            const wchar_t* valueName,
                            wchar_t*value, DWORD size);

    /**
     * Write a DWORD value to the registry
     * @param subkey subkey to write to
     * @param valueName key to write to
     * @param value DWORD value to write
     */
    void WriteRegistryDWORD(const wchar_t* subkey,
                            const wchar_t* valueName,
                            DWORD value);

    /**
     * Read a DWORD value from the registry
     * @param subkey key to read from
     * @param valueName value to read
     * @return DWORD value
     */
    DWORD ReadRegistryDWORD(const wchar_t* subkey,
                            const wchar_t* valueName);

    /**
     * Delete a registry key
     * @param subkey key to delete
     */
    void DeleteRegistryKey(const wchar_t* subkey);

    /**
     * Delete a registry value
     * @param subkey key to delete value from
     * @param valueName value to delete
     */
    void DeleteRegistryValue(const wchar_t* subkey,
                             const wchar_t* valueName);
}

#endif //HOSTVMSPOOFER_REGISTRY_HPP
