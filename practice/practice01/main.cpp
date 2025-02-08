#include <iostream>
#include <vector>
using namespace std;

// 1). Add to the vector
void AddItem(vector<int>& vec, int& item) {
    vec.push_back(item);
}

// 2). Printing the vector
void PrintVector(const vector<int>& vec) {
    for (const int& i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

// 3). Doubling the vector
void DoubleVector(vector<int>& vec) {
    for (int& i : vec) {
        i *= 2;
    }
    cout << "vector elements have been doubled." << endl;
}

// 4). Calculating the sum
void CalcVector(const vector<int>& vec) {
    int sum = 0;

    cout << "The sum of the vector is: ";

    for (const int& i : vec) {
        sum += i;
    }

    cout << sum << endl;
}

// 5). Printing multiples
void PrintMultiples(const vector<int>& vec, int& multiple) {
    for (const int& i : vec) {
        if (i % multiple == 0)
            cout << i << " ";
    }
    cout << endl;
}

//Print menu options
void PrintMenu() {
    cout << "\n1). Add an item to the Vector" << endl;
    cout << "2). Print the vector" << endl;
    cout << "3). Double the vector" << endl;
    cout << "4). Calculate the sum of the vector" << endl;
    cout << "5). Print multiples of a value" << endl;
    cout << "6). End\n" << endl;
    cout << "Choose an option: ";
}

int main() {
    vector<int> numbers{ 1, 2, 3, 4, 5 };
    int response;
    int num;

    //Print the menu for user response
    while (true) {
        PrintMenu();
        cin >> response;
        cout << endl;
        switch (response) {
        case 1:
            //Prompt the user for a number and add it to the vector
            cout << "Enter a number to add to the vector: ";
            cin >> num;
            AddItem(numbers, num);
            cout << endl;
            continue;
        case 2:
            //Display all numbers in the vector
            PrintVector(numbers);
            continue;
        case 3:
            //Multiply each number in the vector by 2. (This should permanently change the vector.)
            DoubleVector(numbers);
            cout << endl;
            continue;
        case 4:
            //Calculate and print the sum of all numbers in the vector.
            CalcVector(numbers);
            continue;
        case 5:
            //Ask the user for a number and print all elements of the vector that are multiples of that number.
            cout << "Check the vector for multiples of: ";
            cin >> num;
            PrintMultiples(numbers, num);
            cout << endl;
            continue;
        case 6:
            //Terminate the program.
            break;
        default:
            cout << "Response not recognized, please enter one of the corresponding numbers 1-6." << endl;
            continue;
        }
        break;
    }
    cout << "Exiting" << endl;
    return 0;
}
