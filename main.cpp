#include <iostream>
#include "user.h"

using namespace std;

int main() {
    User s(5289383);
    cout << s << endl;
    s.addAccount("savings", 1000);
    return 0;
}