/*
This file creates the FrontListIsA class.
dj5172pl Teagen Lee
Due: 11/17/2025
Dr. Jie Hu Meichsner
*/


#ifndef FRONT_LIST_IS_A_H
#define FRONT_LIST_IS_A_H

#include "LinkedList.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class FrontListIsA : public LinkedList<ItemType> {
public:
        /** Constructor; 
    /** Default constructor
     *  @pre None
     *  @post Creates an empty FrontListIsA
     */
    FrontListIsA();

        /** Copy constructor
     *  @param aList The FrontListIsA to copy
     *  @pre None
     *  @post Creates a deep copy of aList */
    FrontListIsA(const FrontListIsA<ItemType>& aList);

       /** Destructor
     *  @pre None
     *  @post All nodes are deallocated */
    void clear() noexcept;

        /** Inserts a new item at the front of the list
     *  @param newEntry Item to insert
     *  @pre None
     *  @post newEntry is at the front of the list
     *  @return true if successful*/
    bool insert(const ItemType& newEntry);  // add front

        /** Removes the first item of the list
     *  @pre List is not empty
     *  @post First item is removed
     *  @return true if successful*/
    bool remove();                          // remove front

        /** Retrieves the first item of the list
     *  @pre List is not empty
     *  @post Returns the first item without removing it */
    ItemType retrieve() const;              // get front


    bool insert(int newPosition, const ItemType& newEntry) override;
    bool remove(int position) override;
    void replace(int position, const ItemType& newEntry) override;
};

#include "FrontListIsA.cpp" 

#endif
