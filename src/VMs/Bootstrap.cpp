//
// Created by TaxMachine on 2023-09-28.
//

#include "Bootstrap.hpp"

#include "VMWare/VMWare.hpp"
#include "VirtualBox/VirtualBox.hpp"
#include "QEmu/QEmu.hpp"


void Bootstrap::VMWareBootstrap() {
    VMWare::CreateFakeFiles();
    VMWare::CreateFakeRegistryKeys();
    VMWare::CreateFakeProcesses();
    VMWare::CreateFakeServices();
}

void Bootstrap::VirtualBoxBootstrap() {
    VirtualBox::CreateFakeFiles();
    VirtualBox::CreateFakeRegistryKeys();
    VirtualBox::CreateFakeProcesses();
    VirtualBox::CreateFakeServices();
}

void Bootstrap::QEmuBootstrap() {
    Qemu::CreateFakeFiles();
    Qemu::CreateFakeRegistryKeys();
    Qemu::CreateFakeProcesses();
    Qemu::CreateFakeServices();
}