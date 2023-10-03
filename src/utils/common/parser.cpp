//
// Created by TaxMachine on 2023-10-01.
//
#include "parser.hpp"

#include <fstream>
#include <filesystem>

#include "json.hpp"

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

nlohmann::json Parser::GetConfig() {
    std::string path = getenv("USERPROFILE") + std::string(R"(\.hostvm\config.json)");
    if (!std::filesystem::exists(path)) throw std::runtime_error("Config file does not exist!");
    std::ifstream cfgfile(path);
    nlohmann::json cfg = nlohmann::json::parse(cfgfile);
    return cfg;
}

void Parser::SetConfig(const nlohmann::json &config) {
    std::string path = getenv("USERPROFILE") + std::string(R"(\.hostvm\config.json)");
    std::ofstream cfgfile(path);
    cfgfile << config.dump();
    cfgfile.close();
}