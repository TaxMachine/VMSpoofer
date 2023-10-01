//
// Created by TaxMachine on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_PROXMOX_HPP
#define HOSTVMSPOOFER_PROXMOX_HPP

#include "../VM.hpp"

class Proxmox : public VM {
    public:
        Proxmox() = default;

        const char* GetName() override { return "Proxmox"; }
        void CreateFakeFiles() override;
        void CreateFakeRegistryKeys() override;
        void CreateFakeProcesses() override;
        void CreateFakeNamedPipes() override;
        void CreateFakeServices() override;

        ~Proxmox() override = default;
};

#endif //HOSTVMSPOOFER_PROXMOX_HPP
