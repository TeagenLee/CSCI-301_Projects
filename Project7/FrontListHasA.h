/*
This file creates the FrontListHasA class.
Teagen Lee
Due: 11/17/2025
*/


#ifndef FRONT_LIST_HAS_A_
#define FRONT_LIST_HAS_A_

#include "FrontListInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcept.h"
#include <memory>

template<class ItemType>
class FrontListHasA : public FrontListInterface<ItemType>
{
private:
    std::unique_ptr<LinkedList<ItemType>> listPtr;

public:
        /** Constructor; 
     /** Default constructor
     *  @pre None
     *  @post Creates an empty FrontListHasA*/
    FrontListHasA();

        /** Copy constructor
     *  @param aList The FrontListHasA to copy
     *  @pre None
     *  @post Creates a deep copy of aList */
    FrontListHasA(const FrontListHasA<ItemType>& aList);

    
    /** Destructor
     *  @pre None
     *  @post All nodes in the list are deallocated */
    virtual ~FrontListHasA();

     /** Inserts a new item at the front of the list
     *  @param newEntry Item to insert
     *  @pre None
     *  @post newEntry is at the front of the list
     *  @return true if successful */
    bool insert(const ItemType& newEntry) override;

     /** Removes the first item of the list
     *  @pre List is not empty
     *  @post First item is removed
     *  @return true if successful*/
    bool remove() override;

    
    /** Retrieves the first item of the list
     *  @pre List is not empty
     *  @post Returns the first item without removing it
     *  @throw PrecondViolatedExcept if list is empty */
    ItemType retrieve() const override;


    bool isEmpty() const noexcept;
    int getLength() const noexcept;
    void clear() noexcept;
};

#include "FrontListHasA.cpp"
#endif
