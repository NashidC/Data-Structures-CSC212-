//
//  sequence3.h
//  Assignment 4
//
//  Created by Nashid  on 10/15/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#ifndef MAIN_SAVITCH_SEQUENCE3_H
#define MAIN_SAVITCH_SEQUENCE3_H
#include <cstdlib> // Provides size_t and NULL
#include "node1.h"   // Provides linked list toolkit

namespace main_savitch_5
{
    
    class sequence
    {
    public:
        // TYPEDEF
        typedef size_t size_type; //typedef std::size_t size_type;
        typedef node::value_type value_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence( );
        sequence(const sequence& source);
        ~sequence( );
        // MODIFICATION MEMBER FUNCTIONS
        void start( );
        void advance( );
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current( );
        void operator =(const sequence& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const;
        bool is_item( ) const;
        value_type current( ) const;
    private:
        //    -- Declare your private members here. I suggest that
        //    -- you have the five private member variables that are
        //    -- described in Section 5.4 (page 259) of the textbook.
        size_type total_nodes;//keep track of number of nodes in the list
        node* head_ptr;//start
        node* tail_ptr;//end
        node* cursor;//points to node with current item
        node* precursor;//points to node before current item
    };
}

#endif


