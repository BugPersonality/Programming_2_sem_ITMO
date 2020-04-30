#include <iostream>
#include "circle_buffer.h"

int main()
{
    string command;
    int size;

    cout << "Enter size:" << endl;
    cin >> size;

    Circle_Buffer buffer(size);

    while (command != "stop")
    {
        cout << endl << "Enter the command:" << endl;
        cin >> command;

        if (command == "insert")
        {
            int index;
            int value;

            cout << "Enter the index and value:" << endl;
            cin >> index >> value;

            buffer.insert_n(buffer.start() + index, value);
            buffer.print();
        }
        else if (command == "insert_s")
        {
            buffer.insert_start();
            buffer.print();
        }
        else if (command == "insert_e")
        {
            buffer.insert_end();
            buffer.print();
        }
        else if (command == "print")
        {
            buffer.print();
        }
        else if (command == "resize")
        {
            int _size;

            cout << "Enter new size:" << endl;
            cin >> _size;

            size = _size;
            buffer.resize(_size);
            buffer.print();
        }
        else if (command == "delete")
        {
            int index;

            cout << "Enter the index:" << endl;
            cin >> index;

            buffer.delete_n(index);
            buffer.print();
        }
        else if (command == "delete_s")
        {
            buffer.delete_start();
            buffer.print();
        }
        else if (command == "delete_e")
        {
            buffer.delete_end();
            buffer.print();
        }
        else if (command == "print_r")
        {
            for (int i = 0; i < size; i++)
            {
                cout << buffer[i] << " ";
            }

            cout << endl;
        }
        else
        {
            cout << "Commands: " << endl;
            cout << "1) stop" << endl << "2) insert" << endl << "3) insert_s" << endl << "4) insert_e" << endl;
            cout << "5) resize" << endl << "6) delete" << endl << "7) delete_s" << endl << "8) delete_e" << endl << "8) print" << endl;
        }
    }
}