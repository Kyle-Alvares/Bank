#include <iostream>
#include <fstream>
#include "login.h"
#include "user.h"
#include "session.h"

using namespace std;

int main()
{
    User user;
    Login l;
    bool isAdmin = false;
    int action = -1;
    while (true)
    {
        cout << endl
             << "=============HOME=============" << endl;
        cout << "[1] Login" << endl
             << "[2] Create Account" << endl;
        cout << "Action: ";
        cin >> action;
        if (action == 1)
        {
            l.verifyCredentials();
        }
        else if (action == 2)
        {
            user.createUser();
        }
        else
        {
            continue;
        }
        cout << endl
             << "===========LOGGED IN===========" << endl;
        Session session(user);
        session.save();
        cout << endl
             << "===========LOGGED OUT===========" << endl;
    }
    return 0;
}