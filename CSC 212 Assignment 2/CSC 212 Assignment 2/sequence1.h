//
//  sequence1.h
//  CSC 212 Assignment 2
//
//  Created by Nashid  on 9/16/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//Receipt: dcfdbdf7f347833097f046624012fcc83dc23aaf


#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_3
{
    
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // enum {CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
//        -- Fill in your private member variables here.
//        -- Read Section 3.2 for guidelines.
        value_type data [CAPACITY];
        size_type used;
        size_type index;
            };
}

#endif
