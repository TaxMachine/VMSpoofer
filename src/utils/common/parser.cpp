//
// Created by TaxMachine on 2023-10-01.
//

#include "parser.hpp"

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