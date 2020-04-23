#include <iostream>
#include "header_1.h"
using namespace std;

int main()
{
    string command;
    int number_1, number_2;

    cout << "enter the number_1" << endl;
    cin >> number_1;
    cout << "enter the number_2" << endl;
    cin >> number_2;
    cout << "enter the command" << endl;
    cin >> command;
    cout << "before swap:\n" << "number_1 = " << number_1 << "\tnumber_2 = " << number_2 << endl;

    if (command == "1")
    {
        swap_1(number_1, number_2);
        cout << "after swap:\n" << "number_1 = " << number_1 << "\tnumber_2 = " << number_2;
    }
    else
    {
        swap_2(&number_1, &number_2);
        cout << "after swap:\n" << "number_1 = " << number_1 << "\tnumber_2 = " << number_2;
    }

    return 0;
}