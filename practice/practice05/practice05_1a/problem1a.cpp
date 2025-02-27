// practice05_1a.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        cout << "]" << endl;
    }

    cout << "\n\nThe reversed vector is: ";
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

