// problem1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <limits>

int main()
{
    float redPotion{ 0.0f };    // Amount of red potion in mL
    float bluePotion{ 0.0f };   // Amount of blue potion in mL
    float* flask{ nullptr };    // Pointer to the selected potion
    
    std::string choice;
    float amount = 0;

    while (true) {
        std::cout << "Which potion to add liquid to? (Red/Blue) or type 'Done' to finish: ";
        std::cin >> choice;

        //exit condition
        if (choice == "Done" || choice == "done") {
            break;
        }

        //set pointer
        if (choice == "Red" || choice == "red") {
            flask = &redPotion;
        }
        else if (choice == "Blue" || choice == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid potion choice. Please choose 'Red' or 'Blue'.\n";
            continue;
        }

        //potion amount
        while (true) {
            std::cout << "How many milliliters to add: ";
            std::cin >> amount;

            //invalid check
            if (std::cin.fail() || (*flask + amount < 0)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Please enter a valid number.\n";
            }
            else {
                break;
            }
        }

        *flask += amount;

        std::cout << "Red Potion: " << redPotion << " mL" << std::endl;
        std::cout << "Blue Potion: " << bluePotion << " mL\n" << std::endl;
    }
    std::cout << "Red Potion: " << redPotion << " mL" << std::endl;
    std::cout << "Blue Potion: " << bluePotion << " mL\n" << std::endl;
    
    std::cout << "Brewing session is complete!\n";

    return 0;
}