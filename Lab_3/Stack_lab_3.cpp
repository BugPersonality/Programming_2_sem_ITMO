//
// Created by User on 18.02.2020.
//

#include "Stack_lab_3.h"

int main()
{
    Stack my_stack;
    string command;

    while (command != "stop")
    {
        cout << "enter the command: " << endl;
        cin >> command;

        if(command == "<<")
        {
            int num;

            cout << "Enter the num: " << endl;
            cin >> num;

            my_stack << num;
        }
        else if(command == ">>")
        {
            int num;

            cout << "Enter the num: " << endl;
            cin >> num;

            my_stack >> num;
        }
        else if(command == "pop")
        {
            --my_stack;
        }
    }
}