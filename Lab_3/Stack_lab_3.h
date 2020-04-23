//
// Created by User on 18.02.2020.
//

#ifndef C___LABS_STACK_LAB_3_H
#define C___LABS_STACK_LAB_3_H

#include <iostream>
#include <vector>
using namespace std;

class Stack {

private:

    vector<int> array;

public:

    Stack()
    {
        array.push_back(0);
    }

    void operator<<(int &number)
    {
        check();
        show();

        this->array.push_back(number);

        show();
    }

    void operator>>(int &num)
    {
        check();
        show();

        for(int i = 0; i < this->array.size(); i++)
        {
            if(array[i] == num)
            {
                this->array.erase(this->array.begin() + i);
            }
        }

        show();
    }

    void operator--()
    {
        check();
        show();

        this->array.pop_back();

        show();
    }

    void check()
    {
        if(this->array.size() > 100)
        {
            this->array.clear();
        }
    }

    void show()
    {
        cout << "Your stack: " << endl;

        for(auto &item : this->array)
        {
            cout << item << " ";
        }

        cout << endl;
    }

    ~Stack()
    {
        array.clear();
    }
};


#endif //C___LABS_STACK_LAB_3_H
