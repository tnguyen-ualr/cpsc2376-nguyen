// problem1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void greet(const std::string& prefix, const std::string& name) {
    std::cout << prefix << ", " << name << "!" << std::endl;
}

int main()
{
    int choice;

    while (true) {
        std::cout << "\n1. Default Greeting\n"
            << "2. Greet by Name\n"
            << "3. Custom Greeting\n"
            << "4. Exit\n"
            << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            greet("Hello","Guest");
        }
        else if (choice == 2) {
            std::string name;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet("Hello", name);
        }
        else if (choice == 3) {
            std::string prefix;
            std::string name;
            std::cout << "Enter greeting prefix: ";
            std::getline(std::cin, prefix);
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            greet(prefix, name);
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    std::cout << "Goodbye!" << std::endl;

    return 0;
}