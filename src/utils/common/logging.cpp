//
// Created by TaxMachine on 2023-10-01.
//

#include "logging.hpp"

#include <iostream>
#include "colors.hpp"

void Logs::Success(const char* message) {
    std::cout << Colors(0, 255, 0).GetTerminal() << "[+] " << message << RESET << std::endl;
}

void Logs::Error(const char* message) {
    std::cout << Colors(255, 0, 0).GetTerminal() << "[-] " << message << RESET << std::endl;
}

void Logs::Info(const char* message) {
    std::cout << Colors(16, 53, 240).GetTerminal() << "[*] " << message << RESET << std::endl;
}

void Logs::Warning(const char* message) {
    std::cout << Colors(255, 255, 0).GetTerminal() << "[!] " << message << RESET << std::endl;
}

void Logs::Debug(const char* message) {
    std::cout << Colors(255, 255, 255).GetTerminal() << "[D] " << message << RESET << std::endl;
}
