//
// Created by User on 27.02.2020.
//

#include <iostream>
#include <exception>
#include <utility>
using namespace std;

#ifndef C___LABS_4__5__6__EXCLUSION_PATTERNS_H
#define C___LABS_4__5__6__EXCLUSION_PATTERNS_H

template <typename T>

void find_max_elem(T elem_1, T elem_2)
{
    if (elem_1 > elem_2)
    {
        cout << elem_1 << " > " << elem_2 << endl;
    }
    else
    {
        cout << elem_2 << " > " << elem_1 << endl;
    }
}

class MyException : public exception
{
        string msg_;
public:
        MyException(string msg) : msg_(std::move(msg)) {}

        const string& getError() const
        {
            return msg_;
        }
};

template <typename type, int N, int M>
class matrix
{
public:

    type **mat;

    matrix ()
    {
        mat = new type*[N];

        for (int i = 0; i < 3; i ++)
        {
            mat[i] = new type[M];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                type symbol;

                cout << "Enter the value (" << i << "," << j << ")" << endl;
                cin >> symbol;

                this->mat[i][j] = symbol;
            }
        }
    }

    void check(int i, int j)
    {
        if (i >= N || j >= M || i < 0 || j < 0)
            throw MyException("Out of range");

        cout << "(" << i << "," << j << ") = " << this->mat[i][j] << endl;
    }

    ~matrix()
    {
        for (int i = 0; i < N; i++)
        {
            delete []mat[i];
        }
    }
};

#endif //C___LABS_4__5__6__EXCLUSION_PATTERNS_H
