//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VIRTUALBOX_HPP
#define HOSTVMSPOOFER_VIRTUALBOX_HPP

#include "../VM.hpp"

class VirtualBox : public VM {
    public:
        VirtualBox() = default;

        const char* GetName() override { return "VirtualBox"; }
        void CreateFakeFiles() override;
        void CreateFakeRegistryKeys() override;
        void CreateFakeProcesses() override;
        void CreateFakeNamedPipes() override;
        void CreateFakeServices() override;

        ~VirtualBox() override = default;
};

#endif //HOSTVMSPOOFER_VIRTUALBOX_HPP
