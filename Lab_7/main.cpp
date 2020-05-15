#include <iostream>
#include "circle_buffer.h"

int main()
{
    string command;
    unsigned int size;

    cout << "Enter size:" << endl;
    cin >> size;

    Circle_Buffer<int> buffer(size);

    for (auto i = buffer.start(); i != buffer.end() ; i++)
    {
        int value;
        cout << "enter the value :" << endl;
        cin >> value;
        *i = value;
    }
    buffer.insert_end(25);

    while (command != "stop")
    {
        cout << endl << "Enter the command:" << endl;
        cin >> command;

        if (command == "insert")
        {
            //int index;
            //int value;

            //cout << "Enter the index and value:" << endl;
            //cin >> index >> value;

            //buffer.insert_n(buffer.start() + index, value);
            //buffer.print();
            continue;
        }
        else if (command == "insert_s")
        {
            int value;
            cout << "enter the value :" << endl;
            cin >> value;

            buffer.insert_start(value);
            buffer.print();
        }
        else if (command == "insert_e")
        {
            int value;
            cout << "enter the value :" << endl;
            cin >> value;
            buffer.insert_end(value);
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

            auto j = buffer.start() + --index;
            buffer.delete_n(j);
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
