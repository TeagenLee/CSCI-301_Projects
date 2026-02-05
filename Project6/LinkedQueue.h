/*
This file creates the LinkedQueue class.
dj5172pl Teagen Lee
Due: 11/4/2025
Dr. Jie Hu Meichsner
*/

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** ADT queue: Link-based implementation.
 @file LinkedQueue.h */

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "Node.h"
#include <memory>
#include <iostream>

template <typename ItemType>
class LinkedQueue {
private:
   // The queue is implemented as a chain of linked nodes that has 
   // two external pointers, a head pointer for front of the queue and
   // a tail pointer for the back of the queue.
    std::shared_ptr<Node<ItemType>> frontPtr;
    std::shared_ptr<Node<ItemType>> backPtr;

public:
    LinkedQueue() : frontPtr(nullptr), backPtr(nullptr) {}
    LinkedQueue(const LinkedQueue<ItemType>& aQueue) { 
        if (aQueue.frontPtr == nullptr) {
            frontPtr = backPtr = nullptr;
        } else {
            frontPtr = std::make_shared<Node<ItemType>>(aQueue.frontPtr->getItem());
            auto origChainPtr = aQueue.frontPtr->getNext();
            auto newChainPtr = frontPtr;

            while (origChainPtr != nullptr) {
                auto newNode = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
                newChainPtr->setNext(newNode);
                newChainPtr = newNode;
                origChainPtr = origChainPtr->getNext();
            }
            backPtr = newChainPtr;
        }
    }

    ~LinkedQueue() {}

    bool isEmpty() const { return frontPtr == nullptr; } 

    bool enqueue(const ItemType& newEntry);
    bool dequeue();
    ItemType peekFront() const;
}; // end LinkedQueue

#include "LinkedQueue.cpp"

#endif
