//
// Created by TaxMachine on 2023-10-01.
//

#include "CLI.hpp"

#include "../VMs/VMManager.hpp"
#include "../utils/common/colors.hpp"

void CLI::CreateCLI() {
    std::cout << "      (`-.   _   .-')            .-')     _ (`-.                                         ('-.  _  .-')   \n"
                 "    _(OO  )_( '.( OO )_         ( OO ).  ( (OO  )                                      _(  OO)( \\( -O )  \n"
                 ",--(_/   ,. \\,--.   ,--.)      (_)---\\_)_.`     \\ .-'),-----.  .-'),-----.    ,------.(,------.,------.  \n"
                 "\\   \\   /(__/|   `.'   |       /    _ |(__...--''( OO'  .-.  '( OO'  .-.  '('-| _.---' |  .---'|   /`. ' \n"
                 " \\   \\ /   / |         |       \\  :` `. |  /  | |/   |  | |  |/   |  | |  |(OO|(_\\     |  |    |  /  | | \n"
                 "  \\   '   /, |  |'.'|  |        '..`''.)|  |_.' |\\_) |  |\\|  |\\_) |  |\\|  |/  |  '--. (|  '--. |  |_.' | \n"
                 "   \\     /__)|  |   |  |       .-._)   \\|  .___.'  \\ |  | |  |  \\ |  | |  |\\_)|  .--'  |  .--' |  .  '.' \n"
                 "    \\   /    |  |   |  |       \\       /|  |        `'  '-'  '   `'  '-'  '  \\|  |_)   |  `---.|  |\\  \\  \n"
                 "     `-'     `--'   `--'        `-----' `--'          `-----'      `-----'    `--'     `------'`--' '--' \n"
                 "                                                                                                         \n" << std::endl;

}

void CLI::Choices() {
    initVMs();
    int r = 147;
    for (int i = 0; i < VMs.size(); i++) {
        std::cout
            << "\t\t\t"
            << Colors(37, 240, 112).GetTerminal() << "[" << i << "] " << RESET
            << Colors(r, 67, 252).GetTerminal() << VMs[i]->GetName() << RESET
            << std::endl;
        r += 10;
    }
    std::cout << std::endl;
    std::cout << "\t\t\t"
        << "What VM do you want you host to show up as -> ";
    int choice;
    std::cin >> choice;
    if (choice < 0 || choice > VMs.size()) {
        std::cout << "\t\t\t"
            << Colors(255, 0, 0).GetTerminal() << "Invalid choice!" << RESET
            << std::endl;
        return;
    }
    VMs[choice]->CreateFakeFiles();
    //VMs[choice]->CreateFakeRegistryKeys();
    //VMs[choice]->CreateFakeProcesses();
    //VMs[choice]->CreateFakeNamedPipes();
    //VMs[choice]->CreateFakeServices();
    std::cout << "\t\t\t"
        << Colors(0, 255, 0).GetTerminal() << "Successfully spoofed as " << VMs[choice]->GetName() << RESET
        << std::endl;
}