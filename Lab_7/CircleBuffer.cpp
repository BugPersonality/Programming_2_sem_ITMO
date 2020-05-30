#include "CircleBuffer.h"

template<typename T>
Circle_Buffer<T>::Circle_Buffer(int N)
{
    capacity = N;
    this->array = new T[N];
}

template<typename T>
Circle_Buffer<T>::~Circle_Buffer()
{
    delete []array;
    cout << "You memory is free";
}

template<typename T>
T Circle_Buffer<T>::operator[](int n)
{
    return (array[n % capacity]);
}

template<typename T>
typename Circle_Buffer<T>::iterator Circle_Buffer<T>::begin()
{
    return iterator(array);
}

template<typename T>
typename Circle_Buffer<T>::iterator Circle_Buffer<T>::end()
{
    return iterator(array + capacity);
}

template<typename T>
void Circle_Buffer<T>::insert_start(T value)
{
    int count = 1;

    T *help_array = new T[capacity++];

    *(help_array + 0) = value;

    for (auto i = begin(); i != end(); i++)
    {
        *(help_array + count) = *i;

        count++;
    }

    free(array);
    this->array = help_array;
    this->capacity++;
}

template<typename T>
void Circle_Buffer<T>::insert_end(T value)
{
    int new_capacity = capacity++;
    int count = 0;
    T *help_array = new T[new_capacity];

    for (auto i = begin(); i != end(); i++)
    {
        *(help_array + count) = *i;

        if( i == end() - 1)
        {
            *(help_array + count) = value;
        }

        count++;
    }

    free(array);
    this->array = help_array;
    this->capacity = new_capacity;
}

template<typename T>
void Circle_Buffer<T>::delete_start()
{
    T *help_array = new T[this->capacity - 1];
    int count = 0;
    int i = 0;

    while (count < this->capacity)
    {
        if (i != 0)
        {
            *(help_array + count) = *(begin() + i);
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

template<typename T>
void Circle_Buffer<T>::delete_end()
{
    T *help_array = new T[this->capacity - 1];
    int count = 0;
    int i = 0;

    while (count < this->capacity)
    {
        if (i != this->capacity - 1)
        {
            *(help_array + count) = *(begin() + i);
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

template<typename T>
void Circle_Buffer<T>::insert_n(const T *index, int value)
{
    int poss = index - begin();
    int *help_array = new T[this->capacity + 1];
    int count = 0;
    int i = 0;

    while (count <= this->capacity)
    {
        if (count != poss)
        {
            *(help_array + count) = *(begin() + i);
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

template<typename T>
void Circle_Buffer<T>::delete_n(iterator &index)
{
    T *help_array = new T[this->capacity - 1];
    int count = 0;

    auto i = begin();

    while (count < this->capacity)
    {
        if (i != index)
        {
            *(help_array + count) = *(i);
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

template<typename T>
void Circle_Buffer<T>::resize(int n)
{
    T *help_array = new T[n];
    int count = 0;

    while (count < n)
    {
        *(help_array + count) = *(begin() + (count % capacity));
        count++;
    }

    free(array);
    this->capacity = n;
    this->array = help_array;
}

template<typename T>
void Circle_Buffer<T>::print()
{
    int count = 0;
    while (count < this->capacity)
    {
        cout << *(begin() + count) << " ";
        count++;
    }
}






























