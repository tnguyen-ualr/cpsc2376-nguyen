// problem2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

template <typename T>
T findMax(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

//check for valid int
int intValid() {
    int value;
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> value;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        }
        else {
            break;
        }
    }
    return value;
}

int main()
{
    int choice;
    std::cout << "Compare (1) Numbers or (2) Strings? ";
    std::cin >> choice;
    std::cin.ignore();  // Clear newline from input buffer

    if (choice == 1) {
        int a = intValid();
        int b = intValid();
        int c = intValid();

        std::cout << "Max value: " << findMax<int>(a, b, c) << std::endl;
    }
    else if (choice == 2) {
        std::string a, b, c;
        std::cout << "Enter first value: ";
        std::getline(std::cin, a);
        std::cout << "Enter second value: ";
        std::getline(std::cin, b);
        std::cout << "Enter third value: ";
        std::getline(std::cin, c);
        std::cout << "Max value: " << findMax<std::string>(a, b, c) << std::endl;
    }
    else {
        std::cout << "Invalid choice." << std::endl;
    }

    return 0;
}