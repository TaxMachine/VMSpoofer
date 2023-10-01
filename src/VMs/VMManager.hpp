//
// Created by TaxMachine on 2023-10-01.
//

#ifndef HOSTVMSPOOFER_VMMANAGER_HPP
#define HOSTVMSPOOFER_VMMANAGER_HPP

#include <vector>
#include <string>

#include "Proxmox/Proxmox.hpp"
#include "VirtualBox/VirtualBox.hpp"
#include "VMware/VMware.hpp"
#include "VSphere/VSphere.hpp"

static std::vector<VM*> VMs;

void Add(VM* vm) {
    for (auto& vm_ : VMs)
        if (vm_->GetName() == vm->GetName()) return;
    VMs.push_back(vm);
}

void initVMs() {
    Add(new Proxmox());
    Add(new VirtualBox());
    Add(new VMWare());
    Add(new VSphere());
}

#endif //HOSTVMSPOOFER_VMMANAGER_HPP
