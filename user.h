#ifndef user_h
#define user_h
#include <iostream>
#include <vector>

using namespace std;

class User {
    private: 
        int accountNumber;
        string firstName;
        string middleName;
        string lastName;
        bool isAdminAccount;
        string password;
        // struct account {
        //     string accountName;
        //     double balance;
        // };
        // vector<account> accounts;
    public:
        User();
        User(int accountNumber);
        User(int accountNumber, string firstName, string lastName);
        int getAccountNumber();
        string getFirstName();
        string getMiddleName();
        string getLastName();
        string getPassword();
        bool isAdmin();
        void setFirstName(string firstName);
        void setMiddleName(string middleName);
        void setLastName(string lastName);
        void setPassword(string password);
        void getUserData();
        void saveUserData();
        friend std::ostream& operator<<(std::ostream& stream, const User& u){
            stream << u.firstName << " " << u.lastName << " : " << u.accountNumber;
            return stream;
        }
};

#endif
