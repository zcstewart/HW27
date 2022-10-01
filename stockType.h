//Homework 27

/*
 *  Filename:           stockType.h
 * 
 *  Purpose:            The purpose of this program is to declare the
 *                      member variables and member functions of the stockType
 *                      class.+
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#ifndef STOCKTYPE_H
#define STOCKTYPE_H

#include "newString.h"
#include <iostream>
#include <fstream>
#include <cassert>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

//Class stockType
class stockType
{  
    friend ostream& operator<< (ostream&, const
    stockType&);
    friend ifstream& operator>> (ifstream&, stockType&);
private:
    newString stockSymbol;
    double todayOpenPrice;
    double todayClosePrice;
    double todayHigh;
    double todayLow;
    double yesterdayClose;
    double percentChange;
    int noOfShares;
    
public:
    
    //Default Constructor
    stockType();

    //Constructor with Parameters
    stockType (newString symbol, double openPrice, double closePrice, 
               double High, double Low, double prevClose, int shares);

    //Function setStockInfo(newString, double, double, double, double, double,
    //                      int)
    //
    void setStockInfo(newString symbol, double openPrice, double closePrice, 
                      double High, double Low, double prevClose, int shares);
    
    //Function to return stockSymbol
    newString getSymbol();
    
    //Function to return percentChange
    double getPercentChange();
    
    //Function to return todayOpenPrice
    double getOpenPrice();
    
    //Function to return todayClosePrice
    double getClosePrice();
    
    //Function to return todayHigh
    double getHighPrice();
    
   //Function to return todayLow
    double getLowPrice();
    
    //Function to return yesterdayClose
    double getPrevPrice();
    
    //Function to return noOfShares
    int getNoOfShares(); 
        
    //Overloading of == operator
    bool operator==(const stockType &other);
    
    //Overloading of != operator
    bool operator!=(const stockType &other);
    
    //Overloading of <= operator
    bool operator<=(const stockType &other);
    
    //Overloading of >= operator
    bool operator>=(const stockType &other);
    
    //Overloading of > operator
    bool operator>(const stockType &other);
    
    //Overloading of <= operator
    bool operator<(const stockType &other); 
};

//--------------------------------------------------------------------------//


#endif /* STOCKTYPE_H */

