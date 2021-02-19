#ifndef session_h
#define session_h
#include <iostream>
#include <vector>
#include "user.h"

using namespace std;

class Session {
    private: 
        User user;
    public:
        Session(User user);
        User getUser();
        string askAccountName(int valid);
        int askAccountNumber();
        double askAmount();
        double askAmount(double max);
        bool deposit();
        double withdraw();
        void transfer();
        void payBill();
        // admin only
        void createAccount();
        void disableAccount();
        void deleteAccount();
        void changePlan();
        void prompt();
        void save();
};

#endif
