//
// Created by taxis on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_QEMU_HPP
#define HOSTVMSPOOFER_QEMU_HPP

#include "../VM.hpp"

class Qemu : public VM {
    public:
        Qemu() = default;

        const char* GetName() override { return "Qemu"; }
        void CreateFakeFiles() override;
        void CreateFakeRegistryKeys() override;
        void CreateFakeProcesses() override;
        void CreateFakeNamedPipes() override;
        void CreateFakeServices() override;

        void DeleteFakeFiles() override;
        void DeleteFakeRegistryKeys() override;
        void KillFakeProcesses() override;
        void DeleteFakeNamedPipes() override;
        void DeleteFakeServices() override;

        ~Qemu() override = default;
};

#endif //HOSTVMSPOOFER_QEMU_HPP
