#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

User::User() {
    cout << "here" << endl;
    int min = 1000000, max = 9999999;
    accountNumber = min + rand() % (max - min + 1); 
    getUserData();
    cout << "down here" << endl;
}

// constructors
User::User(int accountNumber) {
    this->accountNumber = accountNumber;
    
    ifstream ifs("./users/" + to_string(accountNumber) + ".txt");
    if(ifs.fail()){
        cerr << "Error. Unable to load user." << endl;
        exit(1);
    }

    string line;
    ifs >> line;
    firstName = line;
    ifs >> line;
    middleName = line;
    ifs >> line;
    lastName = line;
    ifs >> line;
    password = line;
    ifs >> line;
    isAdminAccount = stoi(line);
    ifs.close();
}

// accessor methods
int User::getAccountNumber() { return accountNumber; }
string User::getFirstName() { return firstName; }
string User::getMiddleName() { return middleName; }
string User::getLastName() { return lastName; }
string User::getPassword() { return password; }
bool User::isAdmin() { return isAdminAccount; }

// mutator methods
void User::setFirstName(string firstName) { 
    this->firstName = firstName; 
    saveUserData();
}
void User::setMiddleName(string middleName) { 
    this->middleName = middleName; 
    saveUserData();
}
void User::setLastName(string lastName) { 
    this->lastName = lastName; 
    saveUserData();
}
void User::setPassword(string password) { 
    this->password = password; 
    saveUserData();
}

void User::getUserData() {
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter middle name: ";
    cin >> middleName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter password: ";
    cin >> password;
    isAdminAccount = false;
    saveUserData();
}

void User::saveUserData() {
    ofstream ofs("./users/" + to_string(accountNumber) + ".txt");
    if(ofs.fail()) {
        cerr << "Error! Unable to save user data!";
        exit(1);
    }
    ofs << firstName << endl;
    ofs << middleName << endl;
    ofs << lastName << endl;
    ofs << password << endl;
    ofs << isAdminAccount << endl;
    ofs.close(); 
} 
