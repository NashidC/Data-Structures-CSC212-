//
//  rec_fun.cxx
//  CSC 212 Assignment 5
//
//  Created by Nashid  on 10/28/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "rec_fun.h"
using namespace std;
using namespace recursion;

namespace recursion
{
    void binary_print(ostream& outs, unsigned int n)
    {
        if((n == 0) || (n == 1))
        {
            cout << n;
        }
        else //not 0 or 1
        {
            binary_print(outs, n/2);
            binary_print(outs, n%2);
        }
    }
    
    void triangle(ostream& outs, unsigned int m, unsigned int n)
    {
        assert(m <= n);
        if(m == n)
        {
            for (int i = 0; i < m; ++i)
                cout << "*";
            cout << endl;
        }
        else//m != n && m > n
        {
            for(int i = 0; i < m; i++)
                cout << "*";
            cout << endl;
            triangle(outs, m+1, n);
            for(int i = 0; i < m; i++)
                cout << "*";
            cout << endl;
        }
    }
    
    double pow(double x, int n)
    {
        if(x == 0)
            assert(n > 0);
        if(n == 0)
            return 1;
        if(n < 0)//n is negative
            return (1/pow(x,-n));
        if(n % 2 == 1)//n is odd
            return (x*pow(x,n/2)*pow(x,n/2));
        else//n is even
            return (pow(x,n/2)*pow(x,n/2));
    }
    
    void indented_sentences(size_t m, size_t n)
    {
        assert(m <= n+1);
        if(m > n)
            return;
        else//m < n
        {
            for(int i = 1; i > 0; i++)
                cout << " ";
            cout << "This was written by calling number " << m << endl;
            indented_sentences(m+1, n);
            for(int i = 1; i > 0; i++)
                cout << " ";
            cout << "This was ALSO written by calling number " << m << endl;
        }
    }
}

//i > 1;
