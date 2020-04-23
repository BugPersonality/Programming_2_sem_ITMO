//
// Created by User on 12.02.2020.
//

#include "Matrix_lab_3.h"

int main()
{
    Matrix mat;
    string command;

    mat.set();
    mat.get();


    cout << "Enter the command" << endl;
    cin >> command;

    if (command == "+")
    {
        Matrix mat_2;
        mat_2.set();
        mat_2.get();

        mat = mat_2 + mat;

        mat.get();
    }
    else if (command == "-")
    {

        Matrix mat_2;
        mat_2.set();
        mat_2.get();

        mat = mat - mat_2;

        mat.get();
    }
    else if(command == "*")
    {
        Matrix mat_2;
        mat_2.set();
        mat_2.get();

        mat = mat * mat_2;

        mat.get();
    }
    else if(command == "^")
    {
        int num;

        cout << "enter the num value" << endl;
        cin >> num;

        mat = mat ^ num;

        mat.get();
    }
    else if(command == "==")
    {
        Matrix mat_2;
        bool flag;

        mat_2.set();
        mat_2.get();

        flag = mat == mat_2;

        if(flag)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    else if(command == "!=")
    {
        Matrix mat_2;
        bool flag;

        mat_2.set();
        mat_2.get();

        flag = mat != mat_2;

        if(flag)
        {
            cout << "False" << endl;
        }
        else
        {
            cout << "True" << endl;
        }
    }
    else if(command == "<")
    {
        Matrix mat_2;
        bool flag;

        mat_2.set();
        mat_2.get();

        flag = mat < mat_2;

        if(flag)
        {
            cout << "True" << endl;
        }
        else
        {
            cout << "False" << endl;
        }
    }
    else if(command == ">")
    {
        Matrix mat_2;
        bool flag;

        mat_2.set();
        mat_2.get();

        flag = mat > mat_2;

        if(flag)
        {
            cout << "False" << endl;
        }
        else
        {
            cout << "True" << endl;
        }
    }


    return 0;
}