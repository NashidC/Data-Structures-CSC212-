//
//  sequence3.cxx
//  Assignment 4
//
//  Created by Nashid  on 10/15/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "node1.h"
#include "sequence3.h"
using namespace std;

namespace main_savitch_5
{
    sequence::sequence( )
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        cursor = NULL;
        precursor = NULL;
        total_nodes = 0;
    }
    
    sequence::sequence(const sequence& source)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        list_copy(source.cursor, cursor, precursor);
        total_nodes = source.total_nodes;
    }
    
    sequence::~sequence( )
    {
        list_clear(head_ptr);
        total_nodes = 0;
    }
    
    void sequence::start( )
    {
        cursor = head_ptr;
        precursor = NULL;
    }
    
    void sequence::advance( )
    {
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    
    void sequence::insert(const value_type& entry)
    {
        if(is_item())
        {
            if((precursor = NULL))
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else
            {
                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }
        if(!is_item())
        {
            list_head_insert(head_ptr, entry);
            cursor = head_ptr;
            precursor = NULL;
        }
        total_nodes++;
    }
    
    void sequence::attach(const value_type& entry)
    {
        //assert(is_item());
        if(is_item())
        {
            precursor = cursor;
            list_insert(cursor, entry);
            cursor = cursor->link();
        }
        if(!is_item())
        {
            if((precursor = NULL))
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
            else
            {
                cursor = list_locate(head_ptr, list_length(head_ptr));
                list_insert(cursor, entry);
                cursor = precursor->link();
            }
        }
        total_nodes++;
    }
    
    void sequence::remove_current( )
    {
        assert(is_item());
        if(cursor == head_ptr)
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;
        }
        else
        {
            cursor = cursor->link();
            list_remove(precursor);
        }
        total_nodes--;
    }
    
    void sequence::operator =(const sequence& source)
    {
        if(this == &source)
            return;
        else
        {
            list_clear(head_ptr);
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            if(source.precursor == NULL)
            {
                if(source.cursor == NULL)
                {
                    cursor = NULL;
                    precursor = NULL;
                }
                else
                {
                    cursor = head_ptr;
                    precursor = NULL;
                }
            }
            else
            {
                node *tmp_ptr = head_ptr;
                node *source_ptr = source.head_ptr;
                while(source_ptr != source.precursor)
                {
                    source_ptr = source_ptr->link();
                    tmp_ptr = tmp_ptr->link();
                }
                cursor = tmp_ptr->link();
                precursor = tmp_ptr;
            }
            total_nodes = source.total_nodes;
        }
    }
    
    sequence::size_type sequence::size( ) const
    {
        return total_nodes;
    }
    
    bool sequence::is_item( ) const
    {
        return ((cursor != NULL) && (size() > 0));
    }
    
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return cursor->data();
    }
}
//Codes I used in command prompt to compile:
//g++ -Wall -c sequence3.cxx sequence_exam.cxx node1.cxx
//g++ sequence3.o sequence_exam.o node1.o -o exam
//
