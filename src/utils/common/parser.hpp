//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_PARSER_HPP
#define HOSTVMSPOOFER_PARSER_HPP

#include <vector>
#include <string>
#include <map>

namespace Parser {
    std::vector<std::string> SplitString(const std::string& str, const std::string& delimiter);
    std::vector<std::string> SplitString(const std::string& str, const char& delimiter);

    std::map<std::string, std::string> ParseKeyValue(const std::string& str, const std::string& delimiter);
    std::map<std::string, std::string> GetConfig();
}

#endif //HOSTVMSPOOFER_PARSER_HPP
