// practice05_2b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Write a program that finds the largest element in a vector using std::max_element. Then, modify the program to also find and print the smallest element using std::min_element.
int main()
{
    vector<int> nums = { 111, 250, 34, 41, 56 };
    
    cout << "The vector contains: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Max Element: " << *max_element(nums.begin(), nums.end()) << endl;
    cout << "Min Element: " << *min_element(nums.begin(), nums.end()) << endl;

    return 0;
}
