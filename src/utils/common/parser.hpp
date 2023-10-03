//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_PARSER_HPP
#define HOSTVMSPOOFER_PARSER_HPP

#include <vector>
#include <string>
#include <map>

#include "json.hpp"

namespace Parser {
    std::vector<std::string> SplitString(const std::string& str, const std::string& delimiter);
    std::vector<std::string> SplitString(const std::string& str, const char& delimiter);

    nlohmann::json GetConfig();
    void SetConfig(const nlohmann::json& config);
}

#endif //HOSTVMSPOOFER_PARSER_HPP
