#ifndef login_h
#define login_h
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include "user.h"

class Login {
    private:
        int attempts;
        bool validLogin;
        bool validPassword;
        bool admin;
        User user;
    public:
        Login();
        bool verifyCredentials();
};

#endif