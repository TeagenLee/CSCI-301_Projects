/*
This file creates the ListInterface class.
Teagen Lee
Due: 11/17/2025
*/

/*
ListInterface.h
Frank M. Carrano & Timothy M. Henry
*/

#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

template<class ItemType>
class ListInterface {
public:
    /** Sees whether this list is empty.
        @return True if the list is empty; otherwise false. */
    virtual bool isEmpty() const noexcept = 0;

    /** Gets the current number of entries in this list.
        @return The integer number of entries currently in the list. */
    virtual int getLength() const noexcept = 0;

    /** Inserts an entry into this list at a given position.
        @pre  None.
        @post  If 1 <= newPosition <= getLength() + 1 and the insertion is
               successful, newEntry is at the given position in the list.
        @param newPosition  The list position at which to insert newEntry.
        @param newEntry  The entry to insert into the list.
        @return  True if insertion is successful, or false if not. */
    virtual bool insert(int newPosition, const ItemType& newEntry) = 0;

    /** Removes the entry at a given position from this list.
        @pre  None.
        @post  If 1 <= position <= getLength() and the removal is successful, 
               the entry at the given position in the list is removed and the other
               entries are renumbered accordingly.
        @param position  The list position of the entry to remove.
        @return  True if removal is successful, or false if not. */
    virtual bool remove(int position) = 0;

    /** Removes all entries from this list.
        @pre  None.
        @post  List contains no entries, and getLength() == 0. */
    virtual void clear() noexcept = 0;

    /** Gets the entry at the given position in this list.
        @pre  1 <= position <= getLength().
        @post  The desired entry has been returned.
        @param position  The list position of the desired entry.
        @return  The entry at the given position. */
    virtual ItemType getEntry(int position) const = 0;

    /** Replaces the entry at the given position in this list.
        @pre  1 <= position <= getLength().
        @post  The entry at the given position is newEntry.
        @param position  The list position of the entry to replace.
        @param newEntry  The replacement entry. */
    virtual void replace(int position, const ItemType& newEntry) = 0;

    /** Destroys this list and frees its assigned memory. */
    virtual ~ListInterface() { }
};

#endif
