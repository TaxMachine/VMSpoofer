//
// Created by TaxMachine on 2023-09-30.
//

#ifndef HOSTVMSPOOFER_WINUTILS_HPP
#define HOSTVMSPOOFER_WINUTILS_HPP

#include <string>

namespace WinUtils {
    /**
     * Creates a file at the specified path and writes the specified content to it
     * @param path The path to the file
     * @param content The content to write to the file
     */
    void WriteFile(const std::string& path, const std::string& content);

    /**
     * Spawns a fake process with the specified name and returns the process ID
     * @param name
     */
    int SpawnFakeProcess(const std::string& name);

    /**
     * Create a fake Windows service with the specified name
     * @param name The name of the service
     */
    void CreateFakeService(const std::string& name);

    /**
     * Create a fake named pipe with the specified name
     * @param name The name of the named pipe
     */
    void SpawnNamedPipe(const std::string& name);

    /**
     * Kill a process with the specified name
     * @param name The name of the process
     */
    void KillProcess(const std::string& name);

    /**
     * Disonnect a named pipe with the specified name
     * @param name The name of the named pipe
     */
    void KillNamedPipe(const std::string& name);

    /**
     * Kill a service with the specified name
     * @param name The name of the service
     */
    void KillFakeService(const std::string& name);
}

#endif //HOSTVMSPOOFER_WINUTILS_HPP
