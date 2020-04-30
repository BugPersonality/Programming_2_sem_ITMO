#include "circle_buffer.h"

Circle_Buffer::Circle_Buffer(int N)
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

Circle_Buffer::~Circle_Buffer()
{
    delete[](this->array);

    cout << "You memory is free";
}

int *Circle_Buffer::start()
{
    return array;
}

int *Circle_Buffer::end()
{
    return start() + (capacity - 1);
}

int Circle_Buffer::operator[](int n)
{
    return *(start() + (n % capacity));
}

void Circle_Buffer::insert_start()
{
    int value;
    int count = 1;

    cout << "enter the value :" << endl;
    cin >> value;

    int *help_array = new int[capacity++];

    for (auto i = start(); i < end(); i++)
    {
        *(help_array + count) = *i;
        count++;
    }

    free(array);
    this->array = help_array;
    *start() = value;
}

void Circle_Buffer::delete_start()
{
    int *help_array = new int[this->capacity - 1];
    int count = 0;
    int i = 0;

    while (count < this->capacity)
    {
        if (i != 0)
        {
            *(help_array + count) = *(start() + i);
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

void Circle_Buffer::insert_end()
{
    int value;
    int count = 0;

    cout << "enter the value :" << endl;
    cin >> value;

    int *help_array = new int[capacity++];

    for (auto i = start(); i < end(); i++)
    {
        *(help_array + count) = *i;
        count++;
    }

    free(array);
    this->array = help_array;
    *end() = value;
}

void Circle_Buffer::delete_end()
{
    int *help_array = new int[this->capacity - 1];
    int count = 0;
    int i = 0;

    while (count < this->capacity)
    {
        if (i != this->capacity - 1)
        {
            *(help_array + count) = *(start() + i);
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

void Circle_Buffer::insert_n(const int *index, int value)
{
    int poss = index - start();
    int *help_array = new int[this->capacity + 1];
    int count = 0;
    int i = 0;

    while (count <= this->capacity)
    {
        if (count != poss)
        {
            *(help_array + count) = *(array + i);
            count++;
            i++;
        }
        else if (count == poss)
        {
            *(help_array + count) = value;
            count++;
            continue;
        }
    }

    free(array);
    this->capacity++;
    this->array = help_array;
}

void Circle_Buffer::delete_n(int index)
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

void Circle_Buffer::resize(int n)
{
    int *help_array = new int[n];
    int count = 0;

    while (count < n)
    {
        *(help_array + count) = *(start() + (count % capacity));
        count++;
    }

    free(array);
    this->capacity = n;
    this->array = help_array;
}

void Circle_Buffer::print()
{
    int count = 0;
    while (count < this->capacity)
    {
        cout << *(start() + count) << " ";
        count++;
    }
}
