//
//  sequence2.h
//  CSC 212 Assignment 3
//
//  Created by Nashid  on 10/7/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#ifndef MAIN_SAVITCH_SEQUENCE2_H
#define MAIN_SAVITCH_SEQUENCE2_H
#include <cstdlib>  // Provides size_t

namespace main_savitch_4
{
    class sequence
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30; //enum {DEFAULT_CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence(size_type initial_capacity = DEFAULT_CAPACITY);
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        void resize(size_type new_capacity);
        void operator=(const sequence& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
        //	-- Fill in your private member variables here.
        //        -- You'll need a pointer to a dynamic array, and a size_type
        //        -- variable to keep track of the current length of the
        //        -- sequence, an index to the current item, and
        //	-- another size_type variable to keep track of the
        //        -- complete capacity of the dynamic array.
        value_type *data;
        size_type used;
        size_type current_index;
        size_type capacity;
    };
}

#endif
