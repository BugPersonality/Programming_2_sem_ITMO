#include "exclusion_patterns.h"

int main()
{
    char part;
    string type;

    cout << "Enter the part of the task:" << endl;
    cin >> part;

    if (part == '1')
    {
        cout << "Enter the type of elements" << endl;
        cin >> type;

        if (type == "int")
        {
            int a, b;

            cout << "Enter the values of a and b: " << endl;
            cin >> a >> b;

            find_max_elem<int>(a, b);
        }

        else if (type == "char")
        {
            char a, b;

            cout << "Enter the values of a and b: " << endl;
            cin >> a >> b;

            find_max_elem<char>(a, b);
        }
    }
    else if (part == '2')
    {
        matrix<int, 3, 3> element;

        try
        {
            element.check(1, 1);
        }
        catch (MyException e)
        {
            cout << e.getError() << endl;
        }
    }
}