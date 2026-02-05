/*
This file implements the FrontListIsA class.
dj5172pl Teagen Lee
11/17/2025
Dr. Jie Hu Meichsner
*/

#include "FrontListIsA.h"

/** Default constructor
 *  @pre None
 *  @post Creates an empty FrontListIsA */
template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA()
    : LinkedList<ItemType>()
{ }

/** Copy constructor
 *  @param aList The FrontListIsA to copy
 *  @pre None
 *  @post Creates a deep copy of aList */
template<class ItemType>
FrontListIsA<ItemType>::FrontListIsA(const FrontListIsA<ItemType>& aList)
    : LinkedList<ItemType>(aList)
{ }

template<class ItemType>
void FrontListIsA<ItemType>::clear() noexcept
{
    // Remove first until empty
    while (!LinkedList<ItemType>::isEmpty())
        LinkedList<ItemType>::remove(1);
}

/** Insert a new item at the front
 *  @param newEntry Item to insert
 *  @pre None
 *  @post newEntry is at the front of the list
 *  @return true if successful*/
template<class ItemType>
bool FrontListIsA<ItemType>::insert(const ItemType& newEntry)
{
    // Always insert at front
    return LinkedList<ItemType>::insert(1, newEntry);
}

/** Remove the first item
 *  @pre List is not empty
 *  @post First item is removed
 *  @return true if successful */
template<class ItemType>
bool FrontListIsA<ItemType>::remove()
{
    // Always remove first item
    return LinkedList<ItemType>::remove(1);
}

/** Retrieve the first item
 *  @pre List is not empty
 *  @post Returns first item without removing it */
template<class ItemType>
ItemType FrontListIsA<ItemType>::retrieve() const
{
    if (LinkedList<ItemType>::isEmpty())
        throw PrecondViolatedExcept("retrieve() called on an empty FrontListIsA.");

    return LinkedList<ItemType>::getEntry(1);
}

// ===== Disabled methods from the base class =====

template<class ItemType>
bool FrontListIsA<ItemType>::insert(int /*newPosition*/, const ItemType& /*newEntry*/)
{
    // Disallow arbitrary position insertion
    return false;
}

template<class ItemType>
bool FrontListIsA<ItemType>::remove(int /*position*/)
{
    // Disallow arbitrary position removal
    return false;
}

template<class ItemType>
void FrontListIsA<ItemType>::replace(int /*position*/, const ItemType& /*newEntry*/)
{
    throw PrecondViolatedExcept("replace(pos, ...) is disabled for FrontListIsA.");
}
