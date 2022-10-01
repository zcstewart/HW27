//Homework 27

/*
 *  Filename:           stockListType.h
 * 
 *  Purpose:            The purpose of this program is to 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#ifndef STOCKLISTTYPE_H
#define STOCKLISTTYPE_H

#include "stockType.h" 
#include "listType.h"
#include <iostream>
#include <locale>
#include <iomanip>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

//class stockListType
class stockListType:public listType<stockType>
{
public:
    //Prints list sorted by stock symbol
    void printBySymbol();
    //Prints list sorted by percent gain
    void printByGain();
    //Print list sorted by symbol and list sorted by gain
    void printReports();
    //Sorts list by symbol
    void sortBySymbol();
    //Sorts list by gain
    void sortByGain();
    //Default Constructor | No Parameters
    stockListType();
    //Default Constructor | Parameter : int size
    stockListType(int size);
    //Destructor
    ~stockListType();
private:
    //Integer pointer
    int *sortIndiciesGainLoss; 
};

//--------------------------------------------------------------------------//

#endif /* STOCKLISTTYPE_H */

