// Implementaion of the Node class
// dj5172pl Teagen Lee
// 10/3/2025
// Dr. Jie Hu Meichsner

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Modified for Doubly Linked Bag with shared_ptr

#include "Node.h"

// Default constructor
template<class ItemType>
Node<ItemType>::Node() : next(nullptr), prev(nullptr) { }

// Constructor with item only
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem)
    : item(anItem), next(nullptr), prev(nullptr) { }

// Constructor with item + next
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType>> nextNodePtr)
    : item(anItem), next(nextNodePtr), prev(nullptr) { }

// Constructor with item + next + prev
template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem,
                     std::shared_ptr<Node<ItemType>> nextNodePtr,
                     std::shared_ptr<Node<ItemType>> prevNodePtr)
    : item(anItem), next(nextNodePtr), prev(prevNodePtr) { }

// Setters
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem) noexcept { item = anItem; }

template<class ItemType>
void Node<ItemType>::setNext(std::shared_ptr<Node<ItemType>> nextNodePtr) noexcept { next = nextNodePtr; }

template<class ItemType>
void Node<ItemType>::setPrev(std::shared_ptr<Node<ItemType>> prevNodePtr) noexcept { prev = prevNodePtr; }

// Getters
template<class ItemType>
ItemType Node<ItemType>::getItem() const noexcept { return item; }

template<class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getNext() const noexcept { return next; }

template<class ItemType>
std::shared_ptr<Node<ItemType>> Node<ItemType>::getPrev() const noexcept { return prev; }

