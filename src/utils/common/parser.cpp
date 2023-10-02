//
// Created by TaxMachine on 2023-10-01.
//
#include "parser.hpp"

#include <fstream>
#include <filesystem>

std::vector<std::string> Parser::SplitString(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> result;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos) {
        result.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    result.push_back(str.substr(prev));
    return result;
}

std::vector<std::string> Parser::SplitString(const std::string& str, const char& delimiter) {
    std::vector<std::string> result;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos) {
        result.push_back(str.substr(prev, pos - prev));
        prev = pos + 1;
    }
    result.push_back(str.substr(prev));
    return result;
}

std::map<std::string, std::string> Parser::ParseKeyValue(const std::string& str, const std::string& delimiter) {
    std::map<std::string, std::string> result;
    std::vector<std::string> splitted = SplitString(str, delimiter);
    for (const auto& i : splitted) {
        std::vector<std::string> tmp = SplitString(i, '=');
        result[tmp[0]] = tmp[1];
    }
    return result;
}

std::map<std::string, std::string> Parser::GetConfig() {
    std::string path = getenv("USERPROFILE") + std::string(R"(\.hostvm\config.ini)");
    if (!std::filesystem::exists(path)) throw std::runtime_error("Config file does not exist!");
    std::ifstream file(path);
    std::string line;
    std::map<std::string, std::string> result;
    while (std::getline(file, line)) {
        std::map<std::string, std::string> tmp = ParseKeyValue(line, "=");
        result[tmp.begin()->first] = tmp.begin()->second;
    }
    return result;
}