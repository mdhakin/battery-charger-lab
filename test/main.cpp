#include "Battery.h"

#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>

const char* stateToString(BatteryState state)
{
    switch (state)
    {
        case BatteryState::NoSlot:
            return "NoSlot";

        case BatteryState::InSlotCharging:
            return "InSlotCharging";

        case BatteryState::InSlotNotCharging:
            return "InSlotNotCharging";
    }

    return "Unknown";
}

void printCommands()
{
    std::cout << "********* Battery State Machine Test Harness *****" << "\n";
    std::cout << "Command Menu" << "\n";
    std::cout << "---------------------------------------------------" << "\n";
    std::cout << "help          print help menu" << "\n";
    std::cout << "level         Set battery level in %" << "\n";
    std::cout << "install       install battery into a slot" << "\n";
    std::cout << "remove        remove battery from the slot" << "\n";
    std::cout << "update        update the state machine" << "\n";
    std::cout << "state         print battery state" << "\n";
    std::cout << "quit          exit the test harness" << "\n";
    std::cout << "---------------------------------------------------" << "\n";
    std::cout << "\n\n";
}


int main()
{
    Battery battery;
    bool running = true;

    printCommands();

    while (running)
    {
        std::cout << "> ";

        std::string line;
        if (!std::getline(std::cin, line))
        {
            std::cout << '\n';
            break;
        }

        std::istringstream input(line);

        std::string command;
        input >> command;

        if (command == "help")
        {
           printCommands();
        }
        else if (command == "level")
        {
            int level;

            if (!(input >> level))
            {
                std::cout << "Usage: level <0-100>\n";
            }
            else if (level < 0 || level > 100)
            {
                std::cout << "Charge level must be between 0 and 100\n";
            }
            else
            {
                battery.setChargeLevel(
                    static_cast<std::uint8_t>(level));

                std::cout << "Charge level set to "
                        << level
                        << "%\n";
            }
        }
        else if (command == "install")
        {
            
            if(!battery.isInstalled())
            {
                battery.installInSlot();
                std::cout << "Installed Battery into slot" << std::endl;
            }else
            {
                std::cout << "Battery is already in a slot" << std::endl;
                std::cout << "Battery Voltage Level%: " << static_cast<int>(battery.getChargeLevel()) << std::endl;
                std::cout << "Battery State: " << stateToString(battery.getState()) << std::endl;
            }
        }
        else if (command == "remove")
        {
            if(battery.isInstalled())
            {
                battery.removeFromSlot();
                std::cout << "Battery removed from slot\n";
            }else
            {
                std::cout << "Battery is not installed in a slot" << std::endl;
            }
            
        }
        else if (command == "update")
        {
            battery.update();
            std::cout << "State machine updated\n";
            std::cout << "Battery State: "
              << stateToString(battery.getState())
              << '\n';
        }
        else if (command == "state")
        {
           std::cout << "Battery State: "
                    << stateToString(battery.getState())
                    << '\n';

            std::cout << "Installed: "
                    << (battery.isInstalled() ? "true" : "false")
                    << '\n';

            std::cout << "Charge Level: "
                    << static_cast<int>(battery.getChargeLevel())
                    << "%\n";

            std::cout << "Fully Charged: "
                    << (battery.isFullycharged() ? "true" : "false")
                    << '\n';
        }
        else if (command == "quit")
        {
            running = false;
        }
        else
        {
            std::cout << "Unknown command\n";
        }
        battery.update();
    }
}