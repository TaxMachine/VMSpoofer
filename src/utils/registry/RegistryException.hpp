//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_REGISTRYEXCEPTION_HPP
#define HOSTVMSPOOFER_REGISTRYEXCEPTION_HPP

#include <stdexcept>
#include <ntdef.h>

class RegistryException : public std::runtime_error {
    public:
        explicit RegistryException(const char* message, LONG errorCode) : std::runtime_error{message} {}
        LONG ErrorCode() const noexcept {
            return errorCode;
        }
    private:
        LONG errorCode;


};

#endif //HOSTVMSPOOFER_REGISTRYEXCEPTION_HPP
