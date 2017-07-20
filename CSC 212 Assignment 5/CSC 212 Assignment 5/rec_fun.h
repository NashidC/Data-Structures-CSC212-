//
//  rec_fun.h
//  CSC 212 Assignment 5
//
//  Created by Nashid  on 10/28/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//
//Receipt: d17b8c121f6cf9fef46ce50731b7539a6551fdbb

#ifndef rec_fun
#define rec_fun
#include <iostream>
#include <cstdlib>
using std::ostream;

namespace recursion
{
    void binary_print(ostream& outs, unsigned int n);
    void triangle(ostream& outs, unsigned int m, unsigned int n);
    double pow(double x, int n);
    void indented_sentences(size_t m, size_t n);
}

#endif
