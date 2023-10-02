//
// Created by TaxMachine on 2023-09-28.
//

#ifndef HOSTVMSPOOFER_VSPHERE_HPP
#define HOSTVMSPOOFER_VSPHERE_HPP

#include "../VM.hpp"

class VSphere : public VM {
    public:
        VSphere() = default;

        const char* GetName() override { return "VSphere"; }
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

        ~VSphere() override = default;
};

#endif //HOSTVMSPOOFER_VSPHERE_HPP
