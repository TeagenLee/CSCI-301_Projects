/*
This file impelments the LinkedQueue class.
dj5172pl Teagen Lee
Due: 11/4/2025
Dr. Jie Hu Meichsner
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file LinkedQueue.cpp */

#include "LinkedQueue.h"
#include <memory>
#include <iostream>

template <typename ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry) {
    auto newNode = std::make_shared<Node<ItemType>>(newEntry);

    // Insert the new node
    if (isEmpty()) {
        frontPtr = backPtr = newNode;   // Insertion into empty queue
    } else {
        backPtr->setNext(newNode);     // Insertion into nonempty queue
        
        backPtr = newNode;             // New node is at back
    }
    return true;
}   // end enqueue

template <typename ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    if (isEmpty()) {
        return false;
    }

    frontPtr = frontPtr->getNext();

    if (frontPtr == nullptr) {
        backPtr = nullptr;
    } // end if

    return true;
} // end dequeue

template <typename ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }
    
   // Queue is not empty; return front
    return frontPtr->getItem();
}  // end peekFront
// End of implementation file.