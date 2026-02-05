// Creates the Node class
// Teagen Lee
// 10/3/2025

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
/** @file Node.h */

#ifndef NODE_
#define NODE_

#include <memory>

template<class ItemType>
class Node {
private:
    ItemType item;  // A data item
    std::shared_ptr<Node<ItemType>> next; // Pointer to next node
    std::shared_ptr<Node<ItemType>> prev; // Pointer to previous node

public:
       /** Constructors; 
	/* @pre None
	/* @post sets the node to (, nullptr, nullptr)*/
    Node();

    /** 
    /* @param anItem stores the item in the node
    /* @pre None
	/* @post sets the node to (anItem, nullptr, nullptr)*/
    Node(const ItemType& anItem);

    /** 
    /* @param anItem stores the item in the node
    /* @param nextNodePtr stores the next ptr in the node
    /* @pre None
	/* @post sets the node to (anItem, nextNodePtr, nullptr)*/
    Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr);
    
    /** 
    /* @param anItem stores the item in the node
    /* @param nextNodePtr stores the next ptr in the node
    /* @param prevNodePtr stores the next ptr in the node
    /* @pre There has to be a node already
	/* @post sets the node to (anItem, nextNodePtr, prevNodePtr)*/
    Node(const ItemType& anItem,
         std::shared_ptr<Node<ItemType>> nextNodePtr,
         std::shared_ptr<Node<ItemType>> prevNodePtr);

        /** MODIFICATION MEMBER FUNCTIONS*/
	/** sets the item in the node
	/* @param anItem the item going in the node
	/* @pre None
	/* @post The node's item is set to (anItem)*/
    void setItem(const ItemType& anItem) noexcept;

    /** sets the next ptr in the node
	/* @param nextNodePtr is the ptr for the next node 
	/* @pre None
	/* @post The node's next ptr is set to (nextNodePtr)*/
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept;

    /** sets the previous ptr in the node
	/* @param prevNodePtr is the ptr for the previous node 
	/* @pre There has to already be a node
	/* @post The node's next ptr is set to (prevNodePtr)*/
    void setPrev(std::shared_ptr<Node<ItemType>> prevNodePtr) noexcept;

    
        /** CONSTANT MEMBER FUNCTIONS*/
	/** returns the item in the node
    /* @pre None
	/* @post The value returned is the item in the node.*/
    ItemType getItem() const noexcept;

    /** returns the next ptr in the node
    /* @pre None
	/* @post The value returned is the next ptr in the node.*/
    std::shared_ptr<Node<ItemType>> getNext() const noexcept;

    /** returns the previous ptr in the node
    /* @pre None
	/* @post The value returned is the previous ptr in the node.*/
    std::shared_ptr<Node<ItemType>> getPrev() const noexcept;

}; // end Node

#include "Node.cpp" // Implementation File

#endif
