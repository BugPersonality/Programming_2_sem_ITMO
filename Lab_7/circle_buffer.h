#ifndef CIRCLE_BUFFER_CIRCLE_BUFFER_H
#define CIRCLE_BUFFER_CIRCLE_BUFFER_H

#include <iostream>
using namespace std;

template<typename T>
class Circle_Buffer
{
    class iterator : public std::iterator<std::random_access_iterator_tag, T> {
    private:
        T* iterat;

    public:
        using value_type = typename std::iterator<std::random_access_iterator_tag, T>::value_type;

        iterator(T *iterat) : iterat(iterat) {}

        iterator(const iterator &itr) : iterat(itr.iterat) {}

        bool operator==(const iterator& itr) const {
            return iterat == itr.iterat;
        }
        bool operator!=(const iterator& itr) const {
            return iterat != itr.iterat;
        }

        bool operator>(const iterator& itr) const {
            return iterat > itr.iterat;
        }
        bool operator<(const iterator& itr) const {
            return iterat < itr.iterat;
        }

        iterator &operator+=(std::iterator<std::random_access_iterator_tag, T> new_iterat) {
            iterat += new_iterat;
            return *this;
        }

        iterator &operator-=(value_type new_iterat) {
            iterat -= new_iterat;
            return *this;
        }
        T &operator*() const {
            return *iterat;
        }

        T *operator->() const {
            return iterat;
        }

        T &operator[](value_type new_iterat) const {
            return iterat[new_iterat];
        }

        iterator &operator++() {
            iterat++;
            return *this;
        }

        iterator &operator--() {
            iterat--;
            return *this;
        }

        iterator operator++(T) {
            iterator tmp(*this);
            ++iterat;
            return tmp;
        }

        iterator operator--(T) {
            iterator tmp(*this);
            --iterat;
            return tmp;
        }

        value_type operator-(const iterator &itr) const {
            return iterat - itr.iterat;
        }

        iterator operator+(value_type new_iterat) const {
            return iterator(iterat + new_iterat);
        }

        iterator operator-(value_type new_iterat) const {
            return iterator(iterat - new_iterat);
        }
    };

private:
    int capacity{};
    T *array{};

public:
    Circle_Buffer(int N)
    {
        capacity = N;
        this->array = new T[N];
    }

    ~Circle_Buffer()
    {
        delete []array;
        cout << "You memory is free";
    }

    T operator[](int n)
    {
        return (array[n % capacity]);
    }

    iterator start()
    {
        return iterator(array);
    }

    iterator end()
    {
        return iterator(array+capacity);
    }

    void insert_start(T value)
    {
        int count = 1;

        T *help_array = new T[capacity++];

        for (auto i = start(); i != end(); i++)
        {
            *(help_array + count) = *i;
            count++;
        }

        free(array);
        this->array = help_array;
        *start() = value;
    }

    void delete_start()
    {
        T *help_array = new T[this->capacity - 1];
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

    void insert_end(T value)
    {
        int count = 0;
        T *help_array = new T[capacity++];

        for (auto i = start(); i != end(); i++)
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
    }

    void delete_end()
    {
        T *help_array = new T[this->capacity - 1];
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

    void insert_n(const T *index, int value)
    {
        int poss = index - start();
        int *help_array = new T[this->capacity + 1];
        int count = 0;
        int i = 0;

        while (count <= this->capacity)
        {
            if (count != poss)
            {
                *(help_array + count) = *(start() + i);
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

    void delete_n(iterator &index)
    {
        T *help_array = new T[this->capacity - 1];
        int count = 0;

        auto i = start();

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

    void resize(int n)
    {
        T *help_array = new T[n];
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

    void print()
    {
        int count = 0;
        while (count < this->capacity)
        {
            cout << *(start() + count) << " ";
            count++;
        }
    }
};


#endif //CIRCLE_BUFFER_CIRCLE_BUFFER_H
