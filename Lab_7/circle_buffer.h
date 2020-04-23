#ifndef C___LABS_4__5__6__CIRCLE_BUFFER_H
#define C___LABS_4__5__6__CIRCLE_BUFFER_H

#include <iostream>

using namespace std;

template <int N>

class Circle_Buffer
{
private:
    int capacity{};
    int *array{};

public:

    Circle_Buffer()
    {
        this->capacity = N;
        this->array = new int[capacity];

        for (int i = 0; i < N; i++)
        {
            int value;

            cout << "enter the value :" << endl;
            cin >> value;

            *(this->array + i) = value;
        }
    }

    int operator[](int n)
    {
        return *(this->array + (n % capacity));
    }

    int *start()
    {
        return array;
    }

    int *end()
    {
        return array + (capacity - 1);
    }

    void insert_start()
    {
        int value;

        cout << "enter the value :" << endl;
        cin >> value;

        *array = value;
    }

    void delete_start()
    {
        int *help_array = new int[this->capacity - 1];
        int count = 0;
        int i = 0;

        while (count < this->capacity)
        {
            if (i != 0)
            {
                *(help_array + count) = *(array + i);
                count++;
                i++;
            }
            else
            {
                i++;
                continue;
            }
        }

        free(array);
        this->capacity--;
        this->array = help_array;
    }

    void insert_end()
    {
        int value;

        cout << "enter the value :" << endl;
        cin >> value;

        *(array + (capacity - 1)) = value;
    }

    void delete_end()
    {
        int *help_array = new int[this->capacity - 1];
        int count = 0;
        int i = 0;

        while (count < this->capacity)
        {
            if (i != this->capacity - 1)
            {
                *(help_array + count) = *(array + i);
                count++;
                i++;
            }
            else if (i == this->capacity - 1)
            {
                i++;
                continue;
            }
        }

        free(array);
        this->capacity--;
        this->array = help_array;
    }

    void insert_n(int n)
    {
        int value;

        cout << "enter the value :" << endl;
        cin >> value;

        *(array + (n % capacity)) = value;
    }

    void delete_n(int index)
    {
        int *help_array = new int[this->capacity - 1];
        int count = 0;
        int i = 0;

        while (count < this->capacity)
        {
            if (i != index)
            {
                *(help_array + count) = *(array + i);
                count++;
                i++;
            }
            else if (i == index)
            {
                i++;
                continue;
            }
        }

        free(array);
        this->capacity--;
        this->array = help_array;
    }

    void resize(int n)
    {
        int *help_array = new int[n];
        int count = 0;

        while (count < n)
        {
            *(help_array + count) = *(array + (count % capacity));
            count++;
        }

        free(array);
        this->capacity = n;
        this->array = help_array;
    }

    void print()
    {
        int count = 0;
        while (count < this->capacity)
        {
            cout << *(array + count) << " ";
            count++;
        }
    }

    ~Circle_Buffer()
    {
        delete[](array);

        cout << "Free you memory";
    }
};


#endif //C___LABS_4__5__6__CIRCLE_BUFFER_H
