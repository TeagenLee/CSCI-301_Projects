// Implementation of the DoublyLinkedBag Class
// dj5172pl Teagen Lee
// 10/3/2025
// Dr. Jie Hu Meichsner

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
    @file DoublyLinkedBag.cpp */

#include "DoublyLinkedBag.h"
#include <iostream>

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag() : headPtr(nullptr), itemCount(0) { } // end default constructor

template<class ItemType>
DoublyLinkedBag<ItemType>::DoublyLinkedBag(const DoublyLinkedBag<ItemType>& aBag) {
    itemCount = aBag.itemCount;
    if (aBag.headPtr == nullptr) {
        headPtr = nullptr;
    } // end if 
    else {
        headPtr = std::make_shared<Node<ItemType>>(aBag.headPtr->getItem());
        auto origChainPtr = aBag.headPtr->getNext();
        auto newChainPtr = headPtr;

        while (origChainPtr != nullptr) {
            auto newNode = std::make_shared<Node<ItemType>>(origChainPtr->getItem());
            newChainPtr->setNext(newNode);
            newNode->setPrev(newChainPtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        } // end while
    } // end else
} // end copy constructor

template<class ItemType>
DoublyLinkedBag<ItemType>::~DoublyLinkedBag() { clear(); } // end destructor

template<class ItemType>
int DoublyLinkedBag<ItemType>::getCurrentSize() const { return itemCount; }

template<class ItemType>
bool DoublyLinkedBag<ItemType>::isEmpty() const { return itemCount == 0; }

template<class ItemType>
bool DoublyLinkedBag<ItemType>::add(const ItemType& newEntry) {
    auto newNode = std::make_shared<Node<ItemType>>(newEntry, headPtr, nullptr);
    if (headPtr != nullptr) {
        headPtr->setPrev(newNode);
    } // end if
    headPtr = newNode;
    itemCount++;
    return true;
} // end add

template<class ItemType>
bool DoublyLinkedBag<ItemType>::remove(const ItemType& anEntry) {
    auto entryNodePtr = getPointerTo(anEntry);
    if (entryNodePtr != nullptr) {
        auto prevNode = entryNodePtr->getPrev();
        auto nextNode = entryNodePtr->getNext();

        if (prevNode != nullptr) prevNode->setNext(nextNode);
        if (nextNode != nullptr) nextNode->setPrev(prevNode);
        if (entryNodePtr == headPtr) headPtr = nextNode;

        itemCount--;
        return true;
    } // end if
    return false;
}  // end remove

template<class ItemType>
void DoublyLinkedBag<ItemType>::clear() {
    while (headPtr != nullptr) {
        headPtr = headPtr->getNext();
    } // end while
    itemCount = 0;
}  // end clear

template<class ItemType>
int DoublyLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {
    int frequency = 0;
    auto curPtr = headPtr;
    while (curPtr != nullptr) {
        if (anEntry == curPtr->getItem()) frequency++;
        curPtr = curPtr->getNext();
    } // end while
    return frequency;
} // end getFrequencyOf

template<class ItemType>
bool DoublyLinkedBag<ItemType>::contains(const ItemType& anEntry) const {
    return (getPointerTo(anEntry) != nullptr);
} // end contains

template<class ItemType>
std::vector<ItemType> DoublyLinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents;
    auto curPtr = headPtr;
    while (curPtr != nullptr) {
        bagContents.push_back(curPtr->getItem());
        curPtr = curPtr->getNext();
    } // end while
    return bagContents;
} // end toVector

template<class ItemType>
std::shared_ptr<Node<ItemType>> DoublyLinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const {
    auto curPtr = headPtr;
    while (curPtr != nullptr) {
        if (anEntry == curPtr->getItem()) return curPtr;
        curPtr = curPtr->getNext();
    } // end while
    return nullptr;
} // end getPointerTo