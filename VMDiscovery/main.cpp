//
// Created by TaxMachine on 2023-10-03.
//
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>
#include <Windows.h>

void GetWindowsFiles() {
    std::vector<std::string> files;
    std::string root = "C:\\Windows\\System32";
    for (const auto& entry : std::filesystem::directory_iterator(root)) {
        if (!entry.is_regular_file()) continue;
        std::string filename = entry.path().filename().string();
        if (!filename.ends_with(".exe") ||
            !filename.ends_with(".dll") ||
            !filename.ends_with(".sys") ||
            !filename.ends_with(".drv") ||
            !filename.ends_with(".vxd") ||
            !filename.ends_with(".ocx") ||
            !filename.ends_with(".cpl") ||
            !filename.ends_with(".scr")) continue;
        std::string file = entry.path().string();
        DWORD file_description_size = GetFileVersionInfoSize(file.c_str(), nullptr);
        if (file_description_size == 0) continue;
        std::vector<char> file_description_buffer(file_description_size);
        if (GetFileVersionInfo(file.c_str(), 0, file_description_size, file_description_buffer.data())) {
            UINT translation_size;
            if (VerQueryValue(file_description_buffer.data(), "\\VarFileInfo\\Translation", nullptr, &translation_size)) {
                std::vector<BYTE> translation_buffer(translation_size);
                if (VerQueryValue(file_description_buffer.data(), "\\VarFileInfo\\Translation", reinterpret_cast<LPVOID *>(translation_buffer.data()), &translation_size)) {
                    std::string file_description;
                    for (int i = 0; i < translation_size / sizeof(DWORD); i++) {
                        std::string query = "\\StringFileInfo\\" + std::to_string(LOWORD(*(DWORD*)translation_buffer.data())) + std::to_string(HIWORD(*(DWORD*)translation_buffer.data())) + "\\FileDescription";
                        LPVOID file_description_ptr;
                        UINT file_description_size1;
                        if (VerQueryValue(file_description_buffer.data(), query.c_str(), &file_description_ptr, &file_description_size1)) {
                            file_description = std::string((char*)file_description_ptr, file_description_size1 - 1);
                            break;
                        }
                    }
                    if (file_description.find("vmware") == std::string::npos ||
                        file_description.find("virtualbox") == std::string::npos ||
                        file_description.find("virtual") == std::string::npos ||
                        file_description.find("qemu") == std::string::npos ||
                        file_description.find("vbox") == std::string::npos ||
                        file_description.find("kvm") == std::string::npos) continue;
                    std::cout << "Found " << file_description << " in " << filename << std::endl;
                    std::string destination = ".\\" + filename;
                    std::filesystem::copy_file(file, destination);
                } else {
                    std::cout << "Failed to query file description" << std::endl;
                }
            } else {
                std::cout << "Failed to query translation" << std::endl;
            }
        } else {
            std::cout << "Failed to get file version info" << std::endl;
        }
    }
}

void GetWindowsRegistry(const std::string& regex) {
    std::vector<std::string> files;
    HKEY reg;
    LONG result;
    result = RegConnectRegistry(nullptr, HKEY_LOCAL_MACHINE, &reg);
    if (result != ERROR_SUCCESS) {
        std::cout << "Failed to connect to registry" << std::endl;
        return;
    }
    HKEY key;
    result = RegOpenKeyEx(reg, nullptr, 0, KEY_READ, &key);
    if (result != ERROR_SUCCESS) {
        std::cout << "Failed to open registry key" << std::endl;
        return;
    }
    DWORD subkey_count;
    result = RegQueryInfoKey(key, nullptr, nullptr, nullptr, &subkey_count, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr);
    if (result != ERROR_SUCCESS) {
        std::cout << "Failed to query registry key info" << std::endl;
        return;
    }
    for (DWORD i = 0; i < subkey_count; i++) {
        char subkey_name[MAX_PATH];
        DWORD subkey_name_size = MAX_PATH;
        LONG res = RegEnumKeyEx(key, i, subkey_name, &subkey_name_size, nullptr, nullptr, nullptr, nullptr);
        if (res != ERROR_SUCCESS) {
            std::cout << "Failed to enumerate registry key" << std::endl;
            continue;
        }
        std::string subkey_name_str(subkey_name);
        if (std::regex_search(subkey_name_str, std::regex(regex))) {
            files.push_back(subkey_name_str);
        }
    }
    RegCloseKey(key);
    RegCloseKey(reg);
    std::cout << "Found " << files.size() << " Virtual Machine registry keys" << std::endl;
}

int main() {
    GetWindowsFiles();
    GetWindowsRegistry("(vmware|virtualbox|virtual|qemu|vbox|kvm)");
    return 0;
}