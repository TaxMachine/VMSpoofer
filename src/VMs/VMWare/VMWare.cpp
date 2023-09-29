//
// Created by taxis on 2023-09-26.
//

#include "VMWare.hpp"

#include "../../utils/registry/Registry.hpp"

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


static std::vector<std::string> REGKEYS = {
        R"(HKEY_LOCAL_MACHINE\SOFTWARE\VMware, Inc.\VMware Tools)"
};

static std::vector<std::string> FILES = {
        R"(C:\Windows\system32\drivers\vmmouse.sys)",
        R"(C:\Windows\system32\drivers\vmhgfs.sys)",
        R"(C:\Windows\system32\drivers\vmusbmouse.sys)",
        R"(C:\Windows\system32\drivers\vmkdb.sys)",
        R"(C:\Windows\system32\drivers\vmrawdsk.sys)",
        R"(C:\Windows\system32\drivers\vmmemctl.sys)",
        R"(C:\Windows\system32\drivers\vm3dmp.sys)"
};

static std::vector<std::string> PROCESSES = {
        "vmtoolsd.exe",
        "xenservice.exe",
        "VMSrvc.exe",
        "VMUSrvc.exe"
};

static std::vector<std::string> NAMED_PIPES = {
        R"(\\.\pipe\VBoxMiniRdDN)",
        R"(\\.\pipe\VBoxTrayIPC)"
};


std::vector<unsigned int> VMWARE_MAGIC = {0x56, 0x4D, 0x57, 0x41, 0x52, 0x45};


void VMWare::CreateFakeFiles() {
    for (const auto& file : FILES) {
        std::cout << "Creating file: " << file << std::endl;
        std::ofstream fileStream(file, std::ios::out | std::ios::binary | std::ios::app);
        if (!fileStream.is_open()) {
            std::cout << "Failed to open file: " << file << std::endl;
            std::cout << fileStream.exceptions() << std::endl;
            continue;
        }
        for (const auto& magic : VMWARE_MAGIC) {
            fileStream << magic;
        }
        fileStream.close();
    }
}

void VMWare::RemoveFakeFiles() {
    for (const auto& file : FILES) {
        std::cout << "Removing file: " << file << std::endl;
        if (!DeleteFile((LPCSTR) file.c_str())) {
            std::cout << "Failed to remove file: " << file << std::endl;
        }
    }
}

void VMWare::CreateFakeRegistryKeys() {
    for (const auto& key : REGKEYS) {
        std::cout << "Creating registry key: " << key << std::endl;
        Registry::CreateRegistryKey((const wchar_t *) key.c_str());
    }
}

void VMWare::RemoveFakeRegistryKeys() {
    for (const auto& key : REGKEYS) {
        std::cout << "Removing registry key: " << key << std::endl;
        Registry::DeleteRegistryKey((const wchar_t *) key.c_str());
    }
}