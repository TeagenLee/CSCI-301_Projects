/*
This file creates the FrontListAsA class.
dj5172pl Teagen Lee
Due: 11/17/2025
Dr. Jie Hu Meichsner
*/

#ifndef FRONT_LIST_AS_A_
#define FRONT_LIST_AS_A_

#include "FrontListInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcept.h"

template<class ItemType>
class FrontListAsA : private LinkedList<ItemType>, public FrontListInterface<ItemType>
{
public:
            /** Constructor; 
    /** Default constructor
     *  @pre None
     *  @post Creates an empty FrontListAsA */
    FrontListAsA();

    /** Copy constructor
     *  @param aList The FrontListAsA to copy
     *  @pre None
     *  @post Creates a deep copy of aList  */
    FrontListAsA(const FrontListAsA<ItemType>& aList);

        /** Deconstructor; 
    /** Destructor
     *  @pre None
     *  @post All nodes are deallocated */
    virtual ~FrontListAsA();

        /** Inserts a new item at the front of the list
     *  @param newEntry Item to insert
     *  @pre None
     *  @post newEntry is at the front of the list
     *  @return true if successful */
    bool insert(const ItemType& newEntry) override;

    /** Removes the first item of the list
     *  @pre List is not empty
     *  @post First item is removed
     *  @return true if successful */
    bool remove() override;

    /** Retrieves the first item of the list
     *  @pre List is not empty
     *  @post Returns the first item without removing it */
    ItemType retrieve() const override;

    // Expose helpers for testing
    bool isEmpty() const noexcept;
    int getLength() const noexcept;
    virtual void clear() noexcept override;

};

#include "FrontListAsA.cpp"
#endif
