// practice02
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <type_traits>
#include <sstream>
using namespace std;

//check if input is a float
float isFloat(const string& check) {
    //get value and check if it is the appropriate type
    //if it is the appropriate type then pass it as the variable, if not then ask for a proper value
    float num;
    int intNum;
    string input = check;
    goto firstcheck;

    while (true) {
        cout << "Enter a valid input: ";
        cin >> input;
        firstcheck:
        
        //try to convert the string to a float
        istringstream ss(input);
        ss >> num;
        
        //check if the conversion was successful (got to the end AND didnt fail)
        if (ss.eof() && !ss.fail()) {
            return num;
        }
        else {
            cout << "Invalid input.\n";
        }
    }

    //return num;
}

//display balance from file
void DisplayBalance(const string& filename) {
    //open file and display balance
    ifstream inf(filename);
    string line;
    while (inf >> line) {
        cout << "Your current balance is: $" << fixed << setprecision(2) << stof(line) << std::endl;
    }
    inf.close();
}

//deposit money and write to file
void DepositMoney(const string& filename, const float& money) {
    //open the file and get the current balance and add it to the total
    float total = 0;
    ifstream inf(filename);
    string line;
    while (inf >> line) {
        total += stof(line);
    }
    inf.close();

    //add the the deposit into the total and overwrite the file
    ofstream outf(filename);
    total += money;
    outf << total;
    outf.close();
    cout << "Deposit Successful. Your new balance is $" << fixed << setprecision(2) << total << endl;
}

//withdraw money and write to file
void WithdrawMoney(const string& filename, const float& money) {
    //get balance
    float balance = 0;
    ifstream inf(filename);
    string line;
    while (inf >> line) {
        balance += stof(line);
    }
    inf.close();
    //if balance is less than withdrawal then deny, else proceed with withdrawal
    if (balance < money) {
        cout << "Balance too low for withdrawal.";
    }
    else {
        balance -= money;
        ofstream outf(filename);
        outf << balance;
        outf.close();
        cout << "Withdrawal Successful. Your new balance is $" << fixed << setprecision(2) << balance << endl;
    }
}

//new account with initial balance
void NewAccount(const string& filename, const float& money) {
    //create file and write initial balance
    ofstream outf{ filename };
    outf << money;
    outf.close();
}

void ShowMenu() {
    cout << "\n\n1. Check Balance\n2. Deposit Money\n3. Withdraw Money\n4. Exit\n" << endl;
}

int main()
{
    cout << "Welcome to Your Bank Account!\n";
    //check if an account_balance.txt file exists, if it doesnt then create one with $100
    ifstream inf{ "account_balance.txt" };
    float initialBal = 100.00;
    if (!inf)
    {
        // Create file with initial amount if not found
        NewAccount("account_balance.txt", initialBal);
        cout << "Initializing account with $" << fixed << setprecision(2) << initialBal << endl;
    }
    else {
        DisplayBalance("account_balance.txt");
        inf.close();
    }
    //allow user to perform: Check Balance, Deposit, Withdraw (affects the .txt file)
    string response;
    string money;
    while (true) {
        ShowMenu();
        cout << "Enter Your choice : ";
        cin >> response;
        if (isFloat(response) == 1) {
            //check balance
            DisplayBalance("account_balance.txt");
        }
        else if (isFloat(response) == 2) {
            //deposit
            while (true) {
                cout << "Enter Deposit amount: ";
                cin >> money;
                if (isFloat(money) >= 0) {
                    break;
                }
                else {
                    cout << "Amount is invalid. Please enter a valid amount." << endl;
                }
            }
            DepositMoney("account_balance.txt", isFloat(money));
        }
        else if (isFloat(response) == 3) {
            //withdraw
            while (true) {
                cout << "Enter Withdraw amount: ";
                cin >> money;
                if (isFloat(money) >= 0) {
                    break;
                }
                else {
                    cout << "Amount is invalid. Please enter a valid amount." << endl;
                }
            }
            WithdrawMoney("account_balance.txt", isFloat(money));
        }
        else if (isFloat(response) == 4) {
            //exit
            cout << "Thank you for banking with us!" << endl;
            break;
        }
        else {
            cout << "Response was invalid. Please enter an existing option." << endl;
            continue;
        }
    }
}
