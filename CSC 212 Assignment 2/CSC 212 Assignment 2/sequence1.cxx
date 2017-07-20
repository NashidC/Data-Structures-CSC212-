//
//  sequence1.cxx
//  CSC 212 Assignment 2
//
//  Created by Nashid  on 9/16/16.
//  Copyright © 2016 Nashid Chowdhury. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include "sequence1.h"
using namespace std;

namespace main_savitch_3
{
    sequence::sequence()
    {
        index = 0;
        used = 0;
    }
    
    void sequence::start( )
    //     The first item on the sequence becomes the current item
    //     (but if the sequence is empty, then there is no current item).
    {
        index = 0;
    }
    
    void sequence::advance( )
    //    If the current item was already the last item in the
    //     sequence, then there is no longer any current item. Otherwise, the new
    //     current item is the item immediately after the original current item.
    {
        if((is_item()) && (used >index))
            index++;
    }
    
    void sequence::insert(const value_type& entry)
    {
        //A new copy of entry has been inserted in the sequence
        //before the current item. If there was no current item, then the new entry
        //has been inserted at the front of the sequence. In either case, the newly
        //inserted item is now the current item of the sequence.
        //assert(entry != 0);
        //assert(index < sequence::CAPACITY);
        if(!(is_item()))
        {
            if(used == 0)
            {
                data[0] = entry;
                used++;
            }
            else
            {
                start();
                for(size_type i = used; i > index; i--)
                    data[i] = data[i-1];
                index++;
                data[0] = entry;
                used++;
            }
        }
        else
        {
            for(size_type i = used; i > index; i--)
                data[i] = data[i-1];
            data[index] = entry;
            used++;
        }
    }
    
    void sequence::attach(const value_type& entry)
    {
        //A new copy of entry has been inserted in the sequence after
        //the current item. If there was no current item, then the new entry has
        //been attached to the end of the sequence. In either case, the newly
        //inserted item is now the current item of the sequence.
        //assert(entry != 0);
        //assert(index < sequence::CAPACITY);
        if(!(is_item()))
        {
            data[index] = entry;
            used++;
        }
        else
        {
            for(size_type i = used; i > index; i--)
                data[i] = data[i-1];
            ++index;
            data[index] = entry;
            used++;
        }
    }
    void sequence::remove_current( )
    {
        //The current item has been removed from the sequence, and the
        //item after this (if there is one) is now the new current item.
        if(is_item())
        {
            for(size_type k = index; k < used; k++)
                data[k] = data[k+1];
        }
        used--;
    }
    
    sequence::size_type sequence::size( ) const
    {
        return used;
    }
    
    bool sequence::is_item( ) const
    {
        //     A true return value indicates that there is a valid
        //     "current" item that may be retrieved by activating the current
        //     member function (listed below). A false return value indicates that
        //     there is no valid current item
        return (index < used);
    }
    
    sequence::value_type sequence::current( ) const
    {
        return data[index];
    }
}
