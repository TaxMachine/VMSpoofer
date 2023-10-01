//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_VM_HPP
#define HOSTVMSPOOFER_VM_HPP

class VM {
    public:
        VM() = default;

        virtual const char* GetName() = 0;
        virtual void CreateFakeFiles() = 0;
        virtual void CreateFakeRegistryKeys() = 0;
        virtual void CreateFakeProcesses() = 0;
        virtual void CreateFakeNamedPipes() = 0;
        virtual void CreateFakeServices() = 0;

        virtual ~VM() = default;
};

#endif //HOSTVMSPOOFER_VM_HPP
