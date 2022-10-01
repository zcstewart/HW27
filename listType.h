//Homework 27

/*
 *  Filename:           listType.h
 * 
 *  Purpose:            The purpose of this program is to 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#ifndef LISTTYPE_H
#define LISTTYPE_H


#include <iostream>
#include <cstdlib>
#include <cassert>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class listType{

public:
    bool isEmptyList() const;
    // Function returns a nonzero value (TRUE) if list
    // is empty. Otherwise it returns the value 0
    // (FALSE).

    bool isFullList() const;
    // Function returns a nonzero value (TRUE) if list
    // is full. Otherwise it returns the value 0
    // (FALSE).

    void setLength(int len);
    // Function that sets the length of a list.
    // Postcondition: length = len

    int showLength() const;
    // Function that returns the length of a list
    // Postcondition: returns length

    void search(Type searchItem) const;
    // Search the list for searchItem
    // Postcondition: Internal variable found is set
    // to a nonzero value (TRUE) if searchItem is found
    // in the list, otherwise found is set to 0
    // (FALSE). If the searchItem is found, the value
    // and location within the list is
    // printed to the screen, otherwise, a message
    // indicating that the item cannot
    // be found should be printed.

    void insert(Type newElement);
    // Insert newElement in the list
    // Prior to insertion list must not be full
    // Postcondition: List is old list plus the
    // newElement

    void deleteItem(Type deleteElement);
    // If deleteElement is found in the list it is
    // deleted
    // If list is empty output the message:
    // "Cannot delete from the empty list"
    // Postcondition: List is old list minus the
    // deleteItem if deleteItem is found in the list 

    void sort();
    // Sort the list
    // Precondition: List must exist
    // Postcondition: List elements are in ascending
    // order

    void print() const;
    // Output the elements of the list

    void getList(ifstream &);
    // Read and store elements in the list
    // Postcondition: length = number of elements in
    // the list
    // elements = array holding the input data

    void destroyList();
    // Postcondition: length = 0

    void printList() const;
    // Output the elements of the list

    listType(int listSize);
    // Constructor with parameters
    // Create an array of size specified by the
    // parameter listSize
    // Postcondition: elements contains the base
    // address of the array, length = 0, and
    // maxsize = listSize

    listType();
    // Default constructor
    // Create an array of 50 components
    // Postcondition: elements contains the base
    // address of the array, length = 0, and
    // maxsize = 50

    ~listType();
    // Destructor
    // Delete all elements of the list
    // Postcondition: Array elements is deleted

protected:
    void binarySearch(Type searchItem, int &found, int
    &index);
    int maxSize;
    // Maximum number that can be stored in the list
    int length;
    // Number of elements in the list
    Type *elements;
    // Pointer to the array that holds list elements 
};

//--------------------------------------------------------------------------//

#endif /* LISTTYPE_H */

