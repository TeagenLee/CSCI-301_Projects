// Creates the DoublyLinkedBag class
// Teagen Lee
// 10/3/2025

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file DoublyLinkedBag.h 
    Listing 4-3 */

#ifndef _DOUBLY_LINKED_BAG
#define _DOUBLY_LINKED_BAG

#include "BagInterface.h"
#include "Node.h"
#include <vector>
#include <memory>

template<class ItemType>
class DoublyLinkedBag : public BagInterface<ItemType> {
private:
    std::shared_ptr<Node<ItemType>> headPtr;    // Pointer to first node
    int itemCount;                              // Current count of bag items

    // Returns either a pointer to the node containing a given entry
    // or the null pointer if the entry is not in the bag.
    std::shared_ptr<Node<ItemType>> getPointerTo(const ItemType& target) const; 

public:
        /** Constructor; 
    /* @pre None
    /* @post initializes the DoublyLinkedBag */
    DoublyLinkedBag();
        
        /** Copy Constructor; 
    /* @param aBag the bag that is going to be copied
    /* @pre There must be another bag
    /* @post a second bag that is a copy of aBag */
    DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag);  // Copy constructor
            
        /** Destructor; 
    /* @pre None
    /* @post deconstructs the DoublyLinkedBag */
    virtual ~DoublyLinkedBag();                              // Destructor should be virtual

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** adds an item to the DoublyLinkedBag
	/* @param newEntry the item added to the DoublyLinkedBag
	/* @pre None
	/* @post The item tries to be added and the value returned is a true/false depending if it was succesful or not.*/
    bool add(const ItemType& newEntry);

	/** removes an item to the DoublyLinkedBag
	/* @param newEntry the item removed to the DoublyLinkedBag
	/* @pre Checks to see if the item in in the DoublyLinkedBag
	/* @post The item tries to be removed and the value returned is a true/false depending if it was succesful or not.*/
    bool remove(const ItemType& anEntry);
    	
    /** removes all nodes from the DoublyLinkedBag
	/* @pre None
	/* @post The DoublyLinkedBag is empty. */
    void clear();


            /** CONSTANT MEMBER FUNCTIONS*/
    /** Checks to see if the DoublyLinkedBag is empty
	/* @pre None
	/* @post The value returned is a true/false depending if the DoublyLinkedBag is empty or not.*/
    bool isEmpty() const;
	
    /** returns the size of the DoublyLinkedBag
	/* @pre None
	/* @post The value returned is the size of the DoublyLinkedBag .*/
    int getCurrentSize() const;

	/** returns the frequency of an item in the DoublyLinkedBag
    /* @param anEntry the name of the item being checked for
	/* @pre None
	/* @post The value returned is the frequency of an item in the DoublyLinkedBag.*/
    int getFrequencyOf(const ItemType& anEntry) const;
    	
    /** returns the frequency of an item in the DoublyLinkedBag
    /* @param anEntry the name of the item being checked for
	/* @pre None
	/* @post The value returned true/false on if the item is in the DoublyLinkedBag.*/
    bool contains(const ItemType& anEntry) const;
    	
    /** The items in the DoublyLinkedBag are put into a vector
	/* @pre None
	/* @post The items in the DoublyLinkedBag are put into a vector.*/
    std::vector<ItemType> toVector() const;

}; // end DoublyLinkedBag

#include "DoublyLinkedBag.cpp" // Implementation File

#endif
