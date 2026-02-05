/*
This file creates the FrontListInterface class.
Teagen Lee
Due: 11/17/2025
*/

#ifndef FRONT_LIST_INTERFACE_
#define FRONT_LIST_INTERFACE_

template<class ItemType>
class FrontListInterface
{
public:
    /** Inserts newEntry at the front of the list.
     @post newEntry is the first item in the list.
     @return true if insertion successful, false otherwise. */
    virtual bool insert(const ItemType& newEntry) = 0;

    /** Removes the first item from the list.
     @post first item removed if list not empty.
     @return true if removal successful, false otherwise. */
    virtual bool remove() = 0;

    /** Retrieves (returns) the first item in the list.
     @pre list is not empty.
     @return The first item. */
    virtual ItemType retrieve() const = 0;

    virtual ~FrontListInterface() { }
};

#endif
