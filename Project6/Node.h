/*
This file creates the Node class.
dj5172pl Teagen Lee
Due: 11/4/2025
Dr. Jie Hu Meichsner
*/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** @file Node.h 
    Listing 4-1 */

#ifndef NODE_H
#define NODE_H

#include <memory> 

template <typename ItemType>
class Node {
private:
    ItemType item;                         // A data item
    std::shared_ptr<Node<ItemType>> next;  // Pointer to next node

public:
    Node() : next(nullptr) {} // default constructor
    Node(const ItemType& anItem) : item(anItem), next(nullptr) {} // constructor
    Node(const ItemType& anItem, std::shared_ptr<Node<ItemType>> nextNodePtr)
        : item(anItem), next(nextNodePtr) {}

    void setItem(const ItemType& anItem) { item = anItem; }
    void setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) { next = nextNodePtr; }

    ItemType getItem() const { return item; }
    std::shared_ptr<Node<ItemType>> getNext() const { return next; }
};

#endif
