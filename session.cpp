#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include "session.h"
#include "user.h"

using namespace std;

// constructors
Session::Session(User user) {
    this->user = user;
    prompt();
}

// accessor methods
User Session::getUser() {
    return user;
}

string Session::askAccountName(int valid) {
    string accountName;
    cout << "Enter account name: ";
    cin >> accountName;
    while(user.getAccountIndex(accountName) == valid) {
        cerr << "Error: Invalid account name!" << endl;
        cout << "Enter account name: ";
        cin >> accountName;
    }
    return accountName;
}

int Session::askAccountNumber() {
    bool validAccount = false;
    int accountNumber;
    while(!validAccount) {
        validAccount = true;
        cin >> accountNumber;
        ifstream ifs("./users/" + to_string(accountNumber) + ".txt");
        if(ifs.fail()) {
            cerr << "Error: Invalid account number!" << endl; 
            validAccount = false;
        }
    }
    return accountNumber;
}

double Session::askAmount() {
    return askAmount(numeric_limits<double>::max());
}

double Session::askAmount(double max) {
    double amount;
    cout << "Enter amount: $";
    cin >> amount;
    while(amount <= 0 || amount > max) {
        cerr << "Error: Invalid amount!" << endl;
        cout << "Enter amount: $";
        cin >> amount;
    }
    return amount;
}

bool Session::deposit() {
    cout << endl << "============DEPOSIT============" << endl;
    string accountName = askAccountName(-1);
    double amount = askAmount();
    return user.deposit(accountName, amount); 
}

double Session::withdraw() {
    cout << endl << "============WITHDRAW===========" << endl;
    string accountName = askAccountName(-1);
    int index = user.getAccountIndex(accountName);
    double max = user.getAccounts()[index].balance;
    double amount = askAmount(max);
    user.withdraw(accountName, amount);
    return amount;
}

void Session::transfer() {
    cout << endl << "============TRANSFER===========" << endl;
    cout << "Enter depositee account number: ";
    int accountNumber = askAccountNumber();
    double amount = withdraw();
    User other(accountNumber);
    other.deposit("chequings", amount);
    other.saveUserData();
}

void Session::payBill() {
    cout << endl << "============PAYBILL===========" << endl;
    transfer();
}

void Session::createAccount() {
    cout << endl << "========CREATE ACCOUNT========" << endl;
    if(!user.isAdmin()) { 
        cerr << "Error: privileged transaction!" << endl; 
    } else {
        string accountName = askAccountName(0);
        user.createAccount(accountName);
    }
}

void Session::disableAccount() {
    cout << endl << "========DISABLE ACCOUNT=======" << endl;
    if(!user.isAdmin()) { 
        cerr << "Error: privileged transaction!" << endl; 
    } else {
        string accountName = askAccountName(-1);
        user.disableAccount(accountName);
    }
}

void Session::deleteAccount() {
    cout << endl << "========DELETE ACCOUNT========" << endl;
    if(!user.isAdmin()) { 
        cerr << "Error: privileged transaction!" << endl; 
    } else {
        string accountName = askAccountName(-1);
        user.deleteAccount(accountName);
    } 
}

void Session::changePlan() {
    cout << endl << "=========CHANGE PLAN==========" << endl;
    if(!user.isAdmin()) { 
        cerr << "Error: privileged transaction!" << endl; 
    } else {
        string accountName = askAccountName(-1);
        user.changePlan(accountName);
    }
}

void Session::prompt() {
    int max = user.isAdmin() ? 8 : 4;
    while(true) {
        int option;
        bool validOption = false;
        cout << endl << "===========OPTIONS============" << endl;
        cout << "[0] Logout" << endl;
        cout << "[1] Deposit" << endl;
        cout << "[2] Withdraw" << endl;
        cout << "[3] Transfer" << endl;
        cout << "[4] Pay-Bill" << endl;
        if(user.isAdmin()) {
            cout << "[5] Create Account" << endl;
            cout << "[6] Disable Account" << endl;
            cout << "[7] Delete Account" << endl;
            cout << "[8] Change Plan" << endl;
        }
        while(!validOption) {
            validOption = true;
            cout << "Option: ";
            cin >> option;
            if(option < 0 || option > max) { validOption = false; } 
        }
        if(option == 0) {
            break;
        } else if (option == 1) {
            deposit();
        } else if (option == 2) {
            withdraw();
        } else if (option == 3) {
            transfer();
        } else if (option == 4) {
            payBill();
        } else if (option == 5) {
            createAccount();
        } else if (option == 6) {
            disableAccount();
        } else if (option == 7) {
            deleteAccount();
        } else if (option == 8) {
            changePlan();
        }
    }
}

void Session::save() {
    user.saveUserData();
}