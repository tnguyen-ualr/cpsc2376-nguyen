// practice05_3a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <numeric>

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

//Write a program that prompts the user to enter a list of integers. Use std::for_each with a lambda function to print each element squared. 
// Then, use a new lambda to help sum up all squared values using accumulate and print the result.
int main()
{
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
    
    //square------------
    cout << "Squared vector elements: ";

    for_each(nums.begin(), nums.end(), [](int n) {
        cout << n * n << " ";
        });
    cout << endl;
    
    //sum---------------
    int squareSum = accumulate(nums.begin(), nums.end(), 0, [](int sum, int n) {
        return sum + n * n;
        });

    cout << "Sum of squared vector elements: " << squareSum << endl;


    return 0;
}
