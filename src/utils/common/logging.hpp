//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_LOGGING_HPP
#define HOSTVMSPOOFER_LOGGING_HPP

#include "../../VMs/VM.hpp"

class Logger {
    public:
        explicit Logger(const char* clazz);

        void Success(const char *message);
        void Error(const char *message);
        void Info(const char *message);
        void Warning(const char *message);
        void Debug(const char *message);

    private:
        const char *classname;
};
#endif //HOSTVMSPOOFER_LOGGING_HPP
