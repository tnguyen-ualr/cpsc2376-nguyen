// practice05_1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int getInt() {
    int number;
    while (true) {
        cout << "Enter a valid number: ";
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter an integer." << endl;
        }
        else {
            return number;
        }
    }
}

//Write a program that takes user input for a list of integers, stores them in a std::vector, and prints them in reverse order using iterators.
int main() {
    vector<int> nums = {};

    cout << "Enter 5 numbers to add to the vector: " << endl;

    for (int i = 0; i < 5; ++i) {
        int num = getInt();
        nums.push_back(num);
        cout << "The updated vector is: [ ";
        for (auto it = nums.begin(); it != nums.end(); ++it) {
            cout << *it << " ";
        }
        cout << "]\n" << endl;
    }

    cout << "The reversed vector is: ";
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
