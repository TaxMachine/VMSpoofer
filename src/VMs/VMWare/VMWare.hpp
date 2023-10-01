//
// Created by taxis on 2023-09-26.
//

#ifndef HOSTVMSPOOFER_VMWARE_HPP
#define HOSTVMSPOOFER_VMWARE_HPP

#include "../VM.hpp"

class VMWare : public VM {
    public:
        VMWare() = default;

        const char* GetName() override { return "VMware"; }
        void CreateFakeFiles() override;
        void CreateFakeRegistryKeys() override;
        void CreateFakeProcesses() override;
        void CreateFakeNamedPipes() override;
        void CreateFakeServices() override;

        ~VMWare() override = default;
};

#endif //HOSTVMSPOOFER_VMWARE_HPP

