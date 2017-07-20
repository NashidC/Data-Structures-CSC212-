//
//  main.cpp
//  CSC 212 Assignment 5
//
//  Created by Nashid  on 10/28/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#include <iostream>
#include "rec_fun.h"
using namespace recursion;
using namespace std;

int main()
{
    int binary_input;
    int m_stars;
    int n_stars;
    int x_value;
    int n_value;
    int count_from;
    int count_to;
    
//    cin >> binary_input;
//    cout << "n = " << binary_input << "            ";
//    cout << "Output: ";
//    binary_print(cout, binary_input);
//    cout << endl;
//    cout << endl;
//    
//    cin >> m_stars;//m
//    cin >> n_stars;//n
//    triangle(cout, m_stars, n_stars);
//    cout << endl;
//    cout << endl;
//    
//    cin >> x_value;//x
//    cin >> n_value;//n
//    pow(x_value, n_value);
//    cout << pow(x_value, n_value);
//    cout << endl;
//    cout << endl;
    
    cin >> count_from;//m
    cin >> count_to;//n
    indented_sentences(count_from, count_to);
    cout << endl;
    cout << endl;
}
