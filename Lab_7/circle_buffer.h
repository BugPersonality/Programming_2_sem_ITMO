#ifndef CIRCLE_BUFFER_CIRCLE_BUFFER_H
#define CIRCLE_BUFFER_CIRCLE_BUFFER_H

#include <iostream>
using namespace std;

class Circle_Buffer
{
private:
    int capacity{};
    int *array{};

public:
    Circle_Buffer(int N);
    ~Circle_Buffer();

    int operator[](int n);

    int *start();
    int *end();
    void insert_start();
    void delete_start();
    void insert_end();
    void delete_end();
    void insert_n(const int *index, int value);
    void delete_n(int index);
    void resize(int n);
    void print();
};


#endif //CIRCLE_BUFFER_CIRCLE_BUFFER_H
