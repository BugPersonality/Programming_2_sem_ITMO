//
// Created by User on 10.02.2020.
//

#include <math.h>

#ifndef C___LABS_HEADER_2_H
#define C___LABS_HEADER_2_H

struct dot
{
    float x;
    float y;
};

struct vector
{
    dot A;
    dot B;
};

struct square
{
    dot point_1;
    dot point_2;
    dot point_3;
    dot point_4;
};

struct complex
{
    float re;
    float im;
};

void swap_1 (int &a, int &b)
{
    int buffer = a;
    a = b;
    b = buffer;
}

void swap_2 (int *a, int *b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

void decrease_1 (double &a)
{
    double b;
    b = floor(a);
    a = a - b;
}

void decrease_2 (float *a)
{
    int b;
    b = floor(*a);
    *a = *a - b;
}

void conjugate_number_1(complex &a){
    a.im = -(a.im);
}

void conjugate_number_2(complex *a){
    a->im = -(a->im);
}

void vector_transfer_1 (vector const &_vector, square &_square)
{
    float x_trans = _vector.B.x - _vector.A.x;
    float y_trans = _vector.B.y - _vector.A.y;

    _square.point_1.x = _square.point_1.x + x_trans;
    _square.point_1.y = _square.point_1.y + y_trans;
    _square.point_2.x = _square.point_2.x + x_trans;
    _square.point_2.y = _square.point_2.y + y_trans;
    _square.point_3.x = _square.point_3.x + x_trans;
    _square.point_3.y = _square.point_3.y + y_trans;
    _square.point_4.x = _square.point_4.x + x_trans;
    _square.point_4.y = _square.point_4.y + y_trans;
}

void vector_transfer_2 (vector *_vector, square *_square)
{
    float x_trans = _vector->B.x - _vector->A.x;
    float y_trans = _vector->B.y - _vector->A.y;

    _square->point_1.x = _square->point_1.x + x_trans;
    _square->point_1.y = _square->point_1.y + y_trans;
    _square->point_2.x = _square->point_2.x + x_trans;
    _square->point_2.y = _square->point_2.y + y_trans;
    _square->point_3.x = _square->point_3.x + x_trans;
    _square->point_3.y = _square->point_3.y + y_trans;
    _square->point_4.x = _square->point_4.x + x_trans;
    _square->point_4.y = _square->point_4.y + y_trans;
}

#endif //C___LABS_HEADER_2_H
