#include "login.h"
using namespace std;

Login::Login()
{
    validLogin = false;
    validPassword = false;
    attempts = 0;
}

bool Login::verifyCredentials()
{
    int accountNumber;
    string password;
    while (!validLogin && !validPassword)
    {
        validLogin = true;
        validPassword = true;
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        // Check if we have a file that matches the account #
        ifstream ifs("./users/" + to_string(accountNumber) + ".txt");
        if (ifs.fail())
        {
            // We don't have a file that matches the account #, invalid login
            cerr << "Error: Invalid account number!" << endl;
            validLogin = false;
        }

        // Instantly fail login after 3 failed password attempts.
        else if (attempts > 2)
        {
            cout << "Error: 3 failed login attempts!" << endl;
            return false;
        }

        else
        {
            user.getUserData(accountNumber);
            cout << "Enter Password: ";
            cin >> password;
            if (user.getPassword() != password)
            {
                cout << "Error: Incorrect password!" << endl;
                attempts++;
                validPassword = false;
            }
        }
    }
    return false;
}
