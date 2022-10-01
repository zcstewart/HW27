//Homework 27

/*
 *  Filename:           newString.cpp
 * 
 *  Purpose:            The purpose of this program is to 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cassert>
#include "newString.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

//Constructor: conversion from the char string to newString
newString::newString(const char *str)
{
    strLength = strlen(str);
    strPtr = new char[strLength + 1]; //allocate memory to
    //store the char string
    strcpy(strPtr, str); //copy string into strPtr
}

//--------------------------------------------------------------------------//

//Default constructor to store the null string
newString::newString()
{
    strLength = 0;
    strPtr = new char[1];
    strcpy(strPtr, "");
}

//--------------------------------------------------------------------------//

//Copy constructor
newString::newString(const newString& rightStr)
{
    strLength = rightStr.strLength;
    strPtr = new char[strLength + 1];
    strcpy(strPtr, rightStr.strPtr);
}

//--------------------------------------------------------------------------//

newString::~newString() //destructor
{
    delete [] strPtr;
}

//--------------------------------------------------------------------------//

//overload the assignment operator

//Function:     newString operator=(const newString&)
//
//Inputs:       const newString& rightStr
//Outputs:      const newString&
//Purpose:      The purpose of this function is to overload the assignment
//              operator. An object of newString is passed by reference,
//              and the newString object that is on the left-hand side
//              of the assignment operation has its private member variables
//              assigned the value of the equivalent private member variables
//              of the newString object passed by reference.
const newString& newString::operator=(const newString& rightStr)
{
    if (this != &rightStr) //avoid self-copy
    {
        delete [] strPtr;
        strLength = rightStr.strLength;
        strPtr = new char[strLength + 1];
        strcpy(strPtr, rightStr.strPtr);
    }
    return *this;
}

//--------------------------------------------------------------------------//

//Function      char& operator[] (int)
//
//Inputs:       int index
//Outputs:      char&
//Purpose:      
char& newString::operator[] (int index)
{
    assert(0 <= index && index < strLength);
    return strPtr[index];
}

//--------------------------------------------------------------------------//

//Function:     const char& operator[] (int) const
//
//Inputs:       int index
//Outputs:      const char&
//Purpose:      
const char& newString::operator[](int index) const
{
    assert(0 <= index && index < strLength);
    return strPtr[index];
}

//--------------------------------------------------------------------------//

//Overload the relational operators.

//Function:     bool operator==(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator==(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) == 0);
}

//--------------------------------------------------------------------------//

//Function:     bool operator<(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator<(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) < 0);
}

//--------------------------------------------------------------------------//

//Function:     bool operator<=(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator<=(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) <= 0);
}

//--------------------------------------------------------------------------//

//Function:     bool operator>(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator>(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) > 0);
}

//--------------------------------------------------------------------------//

//Function:     bool operator>=(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator>=(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) >= 0);
}

//--------------------------------------------------------------------------//

//Function:     bool operator!=(const newString& rightStr) const
//
//Inputs:       const newString& rightStr
//Outputs:      bool
//Purpose:      
bool newString::operator!=(const newString& rightStr) const
{
    return (strcmp(strPtr, rightStr.strPtr) != 0);
}

//--------------------------------------------------------------------------//

//Overload the stream insertion operator <<
//Function:     ostream& operator << (ostream& osObject, const newString& str)
//
//Inputs:       ostream& osObject, const newString& str
//Outputs:      ostream&
//Purpose:      
ostream& operator << (ostream& osObject, const newString& str)
{
    osObject << str.strPtr;
    return osObject;
}

//--------------------------------------------------------------------------//

//Overload the stream extraction operator >>
//Function:     istream& operator >> (istream& isObject, newString& str)
//
//Inputs:       istream& isObject, newString& str
//Outputs:      istream&
//Purpose:      
istream& operator >> (istream& isObject, newString& str)
{
    char temp[81];
    isObject >> setw(81) >> temp;
    str = temp;
    return isObject;
}

//--------------------------------------------------------------------------//