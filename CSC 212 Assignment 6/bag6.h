//
//  bag6.h
//  CSC 212 Assignment 6
//
//  Created by Nashid  on 11/20/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#ifndef BAG6_H
#define BAG6_H
#include <cstdlib>     // Provides NULL and size_t
#include "bintree.h"   // Provides binary_tree_node and related functions

namespace main_savitch_10
{
    template <class Item>
    class bag
    {
    public:
        // TYPEDEFS
        typedef std::size_t size_type;
        typedef Item value_type;
        // CONSTRUCTORS and DESTRUCTOR
        bag( ) { root_ptr = NULL; }
        bag(const bag& source);
        ~bag( );
        // MODIFICATION functions
        size_type erase(const Item& target);
        bool erase_one(const Item& target);
        void insert(const Item& entry);
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        // CONSTANT functions
        size_type size( ) const;
        size_type count(const Item& target) const;
        void debug( ) const { print(root_ptr, 0); }
    private:
        binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree
        void insert_all(binary_tree_node<Item>* addroot_ptr);
    };
    
    // NONMEMBER functions for the bag<Item> template class
    template <class Item>
    bag<Item> operator +(const bag<Item>& b1, const bag<Item>& b2);
}

#include "bag6.template.cxx" // Include the implementation.
#endif


