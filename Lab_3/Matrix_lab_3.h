//
// Created by User on 12.02.2020.
//

#ifndef C___LABS_MATRIX_LAB_3_H
#define C___LABS_MATRIX_LAB_3_H

#include <iostream>
using namespace std;

class Matrix {

private:

    int row, column;
    int **mat;

public:

    Matrix () : row(3) , column(3)
    {
        mat = new int*[3];

        for (int i = 0; i < 3; i ++)
        {
            mat[i] = new int[3];
        }
    }

    void set()
    {
        cout << "enter the matrix elements" << endl;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cin >> mat[i][j];
            }
        }
    }

    void get()
    {
        cout << "your matrix is : " << endl;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << "   " << mat[i][j];
            }
            cout << endl;
        }
    }

    Matrix &operator+ (const Matrix &mat_2)
    {
        for (int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                this->mat[i][j] = this->mat[i][j] + mat_2.mat[i][j];
            }
        }
        return *this;
    }

    Matrix &operator- (const Matrix &mat_2)
    {
        for (int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                this->mat[i][j] -= mat_2.mat[i][j];
            }
        }
        return *this;
    }

    Matrix &operator* (const Matrix &mat_2)
    {
        Matrix result_matrix;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                result_matrix.mat[i][j] = 0;
                for(int k = 0; k < 3; k++)
                {
                    result_matrix.mat[i][j] += mat[i][k] * mat_2.mat[k][j];
                }
            }
        }

        for (int l = 0; l < 3; ++l)
        {
            for (int i = 0; i < 3; ++i) {
                result_matrix.mat[l][i] = this->mat[l][i];
            }
        }

        return *this;
    }

    Matrix &operator^ (int dudos)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                this->mat[i][j] = this->mat[i][j] * dudos;
            }
        }
        return *this;
    }

    bool operator== (const Matrix &mat_2) const
    {
        bool flag = true;

        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if(mat[i][j] != mat_2.mat[i][j])
                {
                    flag = false;
                }
            }
        }
        return flag;
    }

    bool operator!= (const Matrix &mat_2) const
    {
        bool flag = this->mat == mat_2.mat;

        return !flag;
    }

    bool operator> (const Matrix &mat_2)
    {
        int determinant_1, determinant_2;
        bool flag;

        determinant_2 = (mat_2.mat[0][1] * mat_2.mat[1][1] * mat_2.mat[2][2])
                        + (mat_2.mat[0][2] * mat_2.mat[1][0] * mat_2.mat[2][1])
                        + (mat_2.mat[2][0] * mat_2.mat[0][1] * mat_2.mat[1][2])
                        - (mat_2.mat[0][2] * mat_2.mat[1][1] * mat_2.mat[2][0])
                        - (mat_2.mat[2][2] * mat_2.mat[1][0] * mat_2.mat[0][1])
                        - (mat_2.mat[0][0] * mat_2.mat[1][1] * mat_2.mat[2][2]);

        determinant_1 = (mat[0][1] * mat[1][1] * mat[2][2])
                        + (mat[0][2] * mat[1][0] * mat[2][1])
                        + (mat[2][0] * mat[0][1] * mat[1][2])
                        - (mat[0][2] * mat[1][1] * mat[2][0])
                        - (mat[2][2] * mat[1][0] * mat[0][1])
                        - (mat[0][0] * mat[1][1] * mat[2][2]);

        flag = determinant_1 > determinant_2;

        return flag;
    }

    bool operator< (const Matrix &mat_2)
    {
        bool flag = this->mat > mat_2.mat;

        return !flag;
    }

   ~Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            delete []mat[i];
        }

        cout << endl << "Your memory is free" << endl;
    }
};

#endif //C___LABS_MATRIX_LAB_3_H
