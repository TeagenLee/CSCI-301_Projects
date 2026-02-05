/*
This file implements the FrontListHasA class.
Teagen Lee
11/17/2025
*/

#include "FrontListHasA.h"

/** Default constructor
 *  @pre None
 *  @post Creates an empty FrontListHasA */
template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA()
    : listPtr(std::make_unique<LinkedList<ItemType>>())
{ }

/** Copy constructor
 *  @param aList The FrontListHasA to copy
 *  @pre None
 *  @post Creates a deep copy of aList */
template<class ItemType>
FrontListHasA<ItemType>::FrontListHasA(const FrontListHasA<ItemType>& aList)
    : listPtr(std::make_unique<LinkedList<ItemType>>())
{
    // copy items using public LinkedList interface
    for (int pos = 1; pos <= aList.listPtr->getLength(); ++pos)
        listPtr->insert(pos, aList.listPtr->getEntry(pos));
}

/** Destructor
 *  @pre None
 *  @post All nodes are deallocated */
template<class ItemType>
FrontListHasA<ItemType>::~FrontListHasA()
{
    clear();
}


/** Insert a new item at the front
 *  @param newEntry Item to insert
 *  @pre None
 *  @post newEntry is at the front of the list
 *  @return true if successful */
template<class ItemType>
bool FrontListHasA<ItemType>::insert(const ItemType& newEntry)
{
    // insert at position 1 (front)
    return listPtr->insert(1, newEntry);
}

/** Removes the first item of the list
*  @pre List is not empty
*  @post First item is removed
*  @return true if successful*/
template<class ItemType>
bool FrontListHasA<ItemType>::remove()
{
    return listPtr->remove(1);
}


/** Retrieve the first item
 *  @pre List is not empty
 *  @post Returns first item without removing it
 *  @throw PrecondViolatedExcept if list is empty */
template<class ItemType>
ItemType FrontListHasA<ItemType>::retrieve() const
{
    if (listPtr->isEmpty())
        throw PrecondViolatedExcept("retrieve() called on an empty FrontListHasA.");
    return listPtr->getEntry(1);
}

template<class ItemType>
bool FrontListHasA<ItemType>::isEmpty() const noexcept
{
    return listPtr->isEmpty();
}

template<class ItemType>
int FrontListHasA<ItemType>::getLength() const noexcept
{
    return listPtr->getLength();
}

template<class ItemType>
void FrontListHasA<ItemType>::clear() noexcept
{
    listPtr->clear();
}
