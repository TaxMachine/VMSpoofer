//
// Created by TaxMachine on 2023-10-01.
//

#include "logging.hpp"

#include <iostream>
#include "colors.hpp"

Logger::Logger(const char* clazz) {
    classname = clazz;
}

void Logger::Success(const char* message) {
    std::cout
        << "<" << Colors(77, 71, 255).GetTerminal() << classname << RESET << "> "
        << Colors(0, 255, 0).GetTerminal() << "[+] " << message << RESET << std::endl;
}

void Logger::Error(const char* message) {
    std::cout
        << "<" << Colors(77, 71, 255).GetTerminal() << classname << RESET << "> "
        << Colors(255, 0, 0).GetTerminal() << "[-] " << message << RESET << std::endl;
}

void Logger::Info(const char* message) {
    std::cout
        << "<" << Colors(77, 71, 255).GetTerminal() << classname << RESET << "> "
        << Colors(16, 53, 240).GetTerminal() << "[*] " << message << RESET << std::endl;
}

void Logger::Warning(const char* message) {
    std::cout
        << "<" << Colors(77, 71, 255).GetTerminal() << classname << RESET << "> "
        << Colors(255, 255, 0).GetTerminal() << "[!] " << message << RESET << std::endl;
}

void Logger::Debug(const char* message) {
    std::cout
        << "<" << Colors(77, 71, 255).GetTerminal() << classname << RESET << "> "
        << Colors(255, 255, 255).GetTerminal() << "[D] " << message << RESET << std::endl;
}
