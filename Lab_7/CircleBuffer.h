#ifndef CIRCLE_BUFFER_CIRCLEBUFFER_H
#define CIRCLE_BUFFER_CIRCLEBUFFER_H

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
    Circle_Buffer(int N);

    ~Circle_Buffer();

    T operator[](int n);

    iterator begin();

    iterator end();

    void insert_start(T value);

    void delete_start();

    void insert_end(T value);

    void delete_end();

    void insert_n(const T *index, int value);

    void delete_n(iterator &index);

    void resize(int n);

    void print();
};

#endif //CIRCLE_BUFFER_CIRCLEBUFFER_H
