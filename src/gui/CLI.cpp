//
// Created by TaxMachine on 2023-10-01.
//

#include "CLI.hpp"

#include "../VMs/VMManager.hpp"
#include "../utils/common/colors.hpp"
#include "../utils/common/parser.hpp"

void CLI::CreateCLI() {
    std::vector<std::string> title = {
            "      (`-.   _   .-')            .-')     _ (`-.                                         ('-.  _  .-')   \n",
            "    _(OO  )_( '.( OO )_         ( OO ).  ( (OO  )                                      _(  OO)( \\( -O )  \n",
            ",--(_/   ,. \\,--.   ,--.)      (_)---\\_)_.`     \\ .-'),-----.  .-'),-----.    ,------.(,------.,------.  \n",
            "\\   \\   /(__/|   `.'   |       /    _ |(__...--''( OO'  .-.  '( OO'  .-.  '('-| _.---' |  .---'|   /`. ' \n",
            " \\   \\ /   / |         |       \\  :` `. |  /  | |/   |  | |  |/   |  | |  |(OO|(_\\     |  |    |  /  | | \n",
            "  \\   '   /, |  |'.'|  |        '..`''.)|  |_.' |\\_) |  |\\|  |\\_) |  |\\|  |/  |  '--. (|  '--. |  |_.' | \n",
            "   \\     /__)|  |   |  |       .-._)   \\|  .___.'  \\ |  | |  |  \\ |  | |  |\\_)|  .--'  |  .--' |  .  '.' \n",
            "    \\   /    |  |   |  |       \\       /|  |        `'  '-'  '   `'  '-'  '  \\|  |_)   |  `---.|  |\\  \\  \n",
            "     `-'     `--'   `--'        `-----' `--'          `-----'      `-----'    `--'     `------'`--' '--' \n"
    };
    int r = 205;
    for (const auto & i : title) {
        std::cout << Colors(r, 67, 252).GetTerminal() << i << RESET;
        r -= 15;
    }
    std::cout << std::endl;
}

void CLI::Choices() {
    initVMs();
    nlohmann::json config = Parser::GetConfig();
    int r = 147;
    for (int i = 0; i < VMs.size(); i++) {
        std::cout
            << "\t\t\t"
            << Colors(37, 240, 112).GetTerminal() << "[" << i << "] " << RESET
            << Colors(r, 67, 252).GetTerminal() << VMs[i]->GetName() << RESET;
            config[VMs[i]->GetName()].get<bool>()
                ? std::cout << Colors(0, 255, 0).GetTerminal() << " [ ENABLED ]" << RESET
                : std::cout << Colors(255, 0, 0).GetTerminal() << " [ DISABLED ]" << RESET;
            std::cout << std::endl;
        r += 15;
    }
    std::cout << std::endl;
    std::cout << "\t\t" << Colors(35, 209, 236).GetTerminal()
        << "What VM do you want you host to show up as -> " << RESET;
    int choice;
    std::cin >> choice;
    if (choice < 0 || choice > VMs.size()) {
        std::cout << "\t\t"
            << Colors(255, 0, 0).GetTerminal() << "Invalid choice!" << RESET
            << std::endl;
        return;
    }
    if (config[VMs[choice]->GetName()].get<bool>()) {
        config[VMs[choice]->GetName()] = false;
        Parser::SetConfig(config);
        VMs[choice]->DeleteFakeFiles();
        VMs[choice]->DeleteFakeRegistryKeys();
        VMs[choice]->KillFakeProcesses();
        //VMs[choice]->DeleteFakeNamedPipes();
        VMs[choice]->DeleteFakeServices();
        std::cout << "\t\t"
                  << Colors(255, 0, 0).GetTerminal() << "Successfully unspoofed as " << VMs[choice]->GetName() << RESET
                  << std::endl;
    } else {
        config[VMs[choice]->GetName()] = true;
        Parser::SetConfig(config);
        VMs[choice]->CreateFakeFiles();
        VMs[choice]->CreateFakeRegistryKeys();
        VMs[choice]->CreateFakeProcesses();
        //VMs[choice]->CreateFakeNamedPipes();
        VMs[choice]->CreateFakeServices();
        std::cout << "\t\t"
                  << Colors(0, 255, 0).GetTerminal() << "Successfully spoofed as " << VMs[choice]->GetName() << RESET
                  << std::endl;
    }
    std::cout << std::endl;
}