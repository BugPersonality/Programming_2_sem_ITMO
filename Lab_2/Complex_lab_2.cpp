#include "Complex_lab_2.h"

int main()
{
    Complex num_1;
    string command;

    cout << "enter the command: " << endl;
    cin >> command;

    if(command == "len")
    {
        num_1.length();
    }
    else if(command == "*")
    {
        Complex num_2;

        num_1.multiplication(num_2);
    }
    else if(command == "+")
    {
        Complex num_2;

        num_1.addition(num_2);
    }
    else if(command == "x")
    {
        double num;
        cout << "enter the number value: " << endl;
        cin >> num;

        num_1.multiplication_on_number(num);
    }

    return 0;
}