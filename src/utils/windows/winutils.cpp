//
// Created by TaxMachine on 2023-09-30.
//

#include "winutils.hpp"

#include <fstream>
#include <windows.h>
#include <filesystem>


void WinUtils::WriteFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    file << content;
    file.close();
}

int WinUtils::SpawnFakeProcess(const std::string& name) {
    std::string dir = getenv("USERPROFILE") + std::string(R"(\.hostvm\processes\)");
    std::string path = dir + name;
    std::filesystem::copy_file(name, path, std::filesystem::copy_options::overwrite_existing);

    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInformation;
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    ZeroMemory(&processInformation, sizeof(processInformation));
    startupInfo.cb = sizeof(startupInfo);

    CreateProcessA(path.c_str(), nullptr, nullptr, nullptr, FALSE, 0x00000008, nullptr, nullptr, &startupInfo, &processInformation);
    return static_cast<int>(processInformation.dwProcessId);
}

void WinUtils::CreateFakeService(const std::string& name) {
    std::string dir = getenv("USERPROFILE") + std::string(R"(\.hostvm\services\)");
    std::string path = dir + name;
    std::filesystem::copy_file(name, path, std::filesystem::copy_options::overwrite_existing);

    SC_HANDLE schSCManager = OpenSCManager(nullptr, nullptr, SC_MANAGER_CREATE_SERVICE);
    SC_HANDLE schService = CreateServiceA(
            schSCManager,
            name.c_str(),
            name.c_str(),
            SERVICE_ALL_ACCESS,
            SERVICE_WIN32_OWN_PROCESS,
            SERVICE_DEMAND_START,
            SERVICE_ERROR_NORMAL,
            path.c_str(),
            nullptr,
            nullptr,
            nullptr,
            nullptr,
            nullptr
    );

    StartServiceA(schService, 0, nullptr);
    CloseServiceHandle(schService);
    CloseServiceHandle(schSCManager);
}

void WinUtils::SpawnNamedPipe(const std::string &name) {
    std::string dir = getenv("USERPROFILE") + std::string(R"(\.hostvm\namedpipes\)");
    std::string path = dir + name;
    std::filesystem::copy_file(name, path, std::filesystem::copy_options::overwrite_existing);

    HANDLE hPipe = CreateNamedPipeA(
            path.c_str(),
            PIPE_ACCESS_DUPLEX,
            PIPE_TYPE_BYTE | PIPE_READMODE_BYTE | PIPE_WAIT,
            1,
            0,
            0,
            0,
            nullptr
    );

    ConnectNamedPipe(hPipe, nullptr);
    CloseHandle(hPipe);
}