////////////////////////////////////////////////////////////////////////////////
// Module Name:  main.cpp
// Authors:      Sergey Shershakov
// Version:      0.2.0
// Date:         30.01.2017
//
// This is a part of the course "Algorithms and Data Structures" 
// provided by  the School of Software Engineering of the Faculty 
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <assert.h>

#include "safearray.h"
#include <string>

using namespace std;


int main()
{
    using namespace xi;

    cout << "Hello, World!" << endl;


    // Simple safearray
    SafeArray<int> sa(3);
    sa[0] = 1;
    sa[1] = 3;
    sa[2] = 5;

    for (int i = 0; i < 3; ++i)
    {
        cout << sa[i] << "; ";
    }
    cout << endl;
    try
    {
        sa[4];
    }
    catch (exception e)
    {
        cout << e.what() << ": index out of range " << endl;
    }


    SafeArray<int> sa_new = sa;
    for (int j = 0; j < 3; ++j)
    {
        cout << sa_new[j] << "; ";
    }

    cout << endl;
    SafeArray<int> sa_new1(sa);
    for (int j = 0; j < 3; ++j)
    {
        cout << sa_new1[j] << "; ";
    }
    return 0;
}