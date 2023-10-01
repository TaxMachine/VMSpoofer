//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_LOGGING_HPP
#define HOSTVMSPOOFER_LOGGING_HPP

namespace Logs {
    void Success(const char *message);

    void Error(const char *message);

    void Info(const char *message);

    void Warning(const char *message);

    void Debug(const char *message);
}
#endif //HOSTVMSPOOFER_LOGGING_HPP
