#include <iostream>
#include "header_1.h"
using namespace std;

int main ()
{

    complex pair;
    string command;

    cout << "enter the RE part\n";
    cin >> pair.re;
    cout << "enter the IM part\n";
    cin >> pair.im;
    cout << "enter the command\n";
    cin >> command;

    if (pair.im > 0)
    {
        cout << "complex number befor pairing: " << pair.re << "+" << pair.im << "i\n";
    }
    else
    {
        cout << "complex number befor pairing: " << pair.re << pair.im << "i\n";
    }

    if (command == "1")
    {
        conjugate_number_1(pair);
    }
    else
    {
        conjugate_number_2(&pair);
    }

    if (pair.im > 0)
    {
        cout << "complex number after pairing: "<< pair.re << "+" << pair.im << "i\n";
    }
    else
    {
        cout << "complex number after pairing: " << pair.re << pair.im << "i\n";
    }

    return 0;
}

