/*
This file implements the FrontListAsA class.
dj5172pl Teagen Lee
11/17/2025
Dr. Jie Hu Meichsner
*/


#include "FrontListAsA.h"

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA()
    : LinkedList<ItemType>()
{ }

template<class ItemType>
FrontListAsA<ItemType>::FrontListAsA(const FrontListAsA<ItemType>& aList)
    : LinkedList<ItemType>(static_cast<const LinkedList<ItemType>&>(aList))
{ }

/** Destructor
*  @pre None
*  @post All nodes in the list are deallocated */
template<class ItemType>
FrontListAsA<ItemType>::~FrontListAsA()
{
    clear();
}

/** Insert at front
 *  @param newEntry Item to insert
 *  @pre None
 *  @post newEntry is first in the list
 *  @return true if successful */
template<class ItemType>
bool FrontListAsA<ItemType>::insert(const ItemType& newEntry)
{
    return LinkedList<ItemType>::insert(1, newEntry);
}

/** Remove first element
 *  @pre List is not empty
 *  @post First item is removed
 *  @return true if successful */
template<class ItemType>
bool FrontListAsA<ItemType>::remove()
{
    return LinkedList<ItemType>::remove(1);
}

/** Retrieve first element
 *  @pre List is not empty
 *  @post Returns first element without removing */
template<class ItemType>
ItemType FrontListAsA<ItemType>::retrieve() const
{
    if (LinkedList<ItemType>::isEmpty())
        throw PrecondViolatedExcept("retrieve() called on an empty FrontListAsA.");
    return LinkedList<ItemType>::getEntry(1);
}

template<class ItemType>
bool FrontListAsA<ItemType>::isEmpty() const noexcept
{
    return LinkedList<ItemType>::isEmpty();
}

template<class ItemType>
int FrontListAsA<ItemType>::getLength() const noexcept
{
    return LinkedList<ItemType>::getLength();
}

template<class ItemType>
void FrontListAsA<ItemType>::clear() noexcept
{
    LinkedList<ItemType>::clear();
}
