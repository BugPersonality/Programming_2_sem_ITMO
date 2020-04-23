#include <iostream>
#include "header_1.h"
using namespace std;

int main ()
{
    string command;
    float number_1;

    cout << "enter the number_1" << endl;
    cin >> number_1;
    cout << "enter the command" << endl;
    cin >> command;
    cout << "before decrease:\n" << "number_1 = " << number_1 << endl;

    if (command == "1")
    {
        decrease_1(number_1);
        cout << "after decrease:\n" << "number_1 = " << number_1;
    }
    else
    {
        decrease_2(&number_1);
        cout << "after decrease:\n" << "number_1 = " << number_1;
    }

    return 0;
}

