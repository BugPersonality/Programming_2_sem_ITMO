#include <iostream>
#include <math.h>
using namespace std;

#ifndef C___LABS_COMPLEX_LAB_2_H
#define C___LABS_COMPLEX_LAB_2_H

class Complex {
private:

    double re{};
    double im{};

public:

    Complex()
    {
        cout << "Enter real part" << endl;
        cin >> this->re;
        cout << "Enter imaginary part" << endl;
        cin >> this->im;

        show();
    }

    Complex(const Complex &object)
    {
        this->re = object.re;
        this->im = object.im;
    }

    Complex(const double &real, const double &imaginary)
    {
        this->re = real;
        this->im = imaginary;

        show();
    }

    void show()
    {
        if (this->im > 0 )
        {
            cout << "your complex number = " << this->re << " + " << this->im << "i" << endl;
        }
        else
        {
            cout << "your complex number = " << this->re << " - " << -(this->im) << "i" << endl;
        }
    }

    void length()
    {
        double number_length;

        number_length = sqrt(pow(this->re, 2) + pow(this->im, 2));

        cout << "length = " << number_length << endl;

    }

    void multiplication(const Complex &number_2)
    {
        double real, imaginary;

        real = this->re * number_2.re - this->im * number_2.im;
        imaginary = this->re * number_2.im + this->im * number_2.re;

        if (imaginary > 0)
        {
            cout << "multiplication result = " << real << " + " << imaginary << "i" << endl;
        }
        else
        {
            cout << "multiplication result = " << real << " - " << -imaginary << "i" << endl;
        }
    }

    void addition(const Complex &number_2)
    {
        double real, imaginary;

        real = this->re + number_2.re;
        imaginary = this->im + number_2.im;

        if (imaginary > 0 )
        {
            cout << "addition result = " << real << " + " << imaginary << "i" << endl;
        }
        else
        {
            cout << "addition result = " << real << " - " << -imaginary << "i" << endl;
        }
    }

    void multiplication_on_number(const double &num)
    {
        double real, imaginary;

        real = this->re * num;
        imaginary = this->im * num;

        if (imaginary > 0 )
        {
            cout << "multiplication result = " << real << " + " << imaginary << "i" << endl;
        }
        else
        {
            cout << "multiplication result = " << real << " - " << -imaginary << "i" << endl;
        }
    }

    ~Complex()
    {
        cout << endl << typeid(*this).name() << " <-- deleted" << endl;
    }
};


#endif //C___LABS_COMPLEX_LAB_2_H
