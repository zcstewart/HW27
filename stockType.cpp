//Homework 27

/*
 *  Filename:           stockType.cpp
 * 
 *  Purpose:            The purpose of this program is to implement the member
 *                      functions of the stockType class.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//--------------------------------------------------------------------------//

//Preprocessor Directives
#include "stockType.h"

//Function:     void stockType(newString symbol, double openPrice, 
//                             double closePrice, double High, double Low, 
//                             double prevClose, int shares)
//
//Inputs:       newString symbol, double openPrice, double closePrice, 
//              double High, double Low, double prevClose, int shares
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to set the value of the 
//              private member variables of the stockType object to the values
//              passed in the formal argument of the function.
void stockType::setStockInfo(newString symbol, double openPrice, 
                             double closePrice, double High, double Low, 
                             double prevClose, int shares)
{
    assert(openPrice >= 0 && closePrice >= 0 && High >= 0 && Low >= 0 
           && prevClose >= 0 && shares >= 0);
    stockSymbol = symbol;
    todayOpenPrice = openPrice;
    todayClosePrice = closePrice;
    todayHigh = High;
    todayLow = Low;
    yesterdayClose = prevClose;
    if(prevClose == 0)
    {
        percentChange = closePrice * 100;
    }
    else
    {
        percentChange = ((prevClose - closePrice)/prevClose) * 100;
    }
    noOfShares = shares;
}

//--------------------------------------------------------------------------//

//Function:     getSymbol()
//
//Inputs:       None
//Outputs:      Return type newString
//Purpose:      The purpose of this program is to return the newString
//              value of the private member variable stockSymbol.
newString stockType::getSymbol()
{
    return stockSymbol;
}

//--------------------------------------------------------------------------//

//Function:     double stockType::getPercentChange()

//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable percentChange.
double stockType::getPercentChange()
{
    return percentChange;
}

//--------------------------------------------------------------------------//

//Function:     getOpenPrice()
//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable todayOpenPrice.
double stockType::getOpenPrice()
{
    return todayOpenPrice;
}

//--------------------------------------------------------------------------//

//Function:     getClosePrice()
//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable todayClosePrice.
double stockType::getClosePrice()
{
    return todayClosePrice;
}

//--------------------------------------------------------------------------//

//Function:     getHighPrice()
//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable todayHigh.
double stockType::getHighPrice()
{
    return todayHigh;
}

//--------------------------------------------------------------------------//

//Function:     getLowPrice()
//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable todayLow.
double stockType::getLowPrice()
{
    return todayLow;
}

//--------------------------------------------------------------------------//

//Function:     getPrevPrice()
//
//Inputs:       None
//Outputs:      Return type double
//Purpose:      The purpose of this program is to return the double value
//              of the private member variable yesterdayClose.
double stockType::getPrevPrice()
{
    return yesterdayClose;
}

//--------------------------------------------------------------------------//

//Function:     getNoOfShares()
//
//Inputs:       None
//Outputs:      Return type int
//Purpose:      The purpose of this function is to return the int value
//              of the private member variables noOfShares.
int stockType::getNoOfShares()
{
    return noOfShares;
}

//--------------------------------------------------------------------------//

//Function:     bool operator==(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this program is to overload the '==' relational
//              operator.

bool stockType::operator==(const stockType &other)
{
    return ((stockSymbol == other.stockSymbol)&&
            (todayOpenPrice == other.todayOpenPrice)&&
            (todayClosePrice == other.todayClosePrice)&&
            (todayHigh == other.todayHigh)&&
            (todayLow == other.todayLow)&&
            (yesterdayClose == other.yesterdayClose)&&
            (percentChange == other.percentChange)&&
            (noOfShares == other.noOfShares));
}

//--------------------------------------------------------------------------//

//Function:     bool operator!=(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this function is to overload the '!='
//              relational operator for the stockType class.
bool stockType::operator!=(const stockType &other)
{
    return ((stockSymbol != other.stockSymbol)||
            (todayOpenPrice != other.todayOpenPrice)||
            (todayClosePrice != other.todayClosePrice)||
            (todayHigh != other.todayHigh)||
            (todayLow != other.todayLow)||
            (yesterdayClose != other.yesterdayClose)||
            (percentChange != other.percentChange)||
            (noOfShares != other.noOfShares));
}

//--------------------------------------------------------------------------//

//Function:     bool operator<=(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this function is to overload the '<=" 
//              relational operator for the stockType class.
bool stockType::operator<=(const stockType &other)
{
    return(stockSymbol <= other.stockSymbol);
}

//--------------------------------------------------------------------------//

//Function:     bool operator>=(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this function is to overload the '>=' relational
//              operator for the stockType class.
bool stockType::operator>=(const stockType &other)
{
    return(stockSymbol >= other.stockSymbol);
}

//--------------------------------------------------------------------------//

//Function:     bool operator>(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this function is to overload the '>' relational
//              operator for the stockType class.
bool stockType::operator>(const stockType &other)
{
    return(stockSymbol > other.stockSymbol);
}

//--------------------------------------------------------------------------//

//Function:     bool operator<(const stockType &other)
//
//Inputs:       const stockType &other
//Outputs:      bool
//Purpose:      The purpose of this function is to overload the '<' relational
//              operator for the stockType class.
bool stockType::operator<(const stockType &other)
{
    return(stockSymbol < other.stockSymbol);
}

//--------------------------------------------------------------------------//

//Function:     friend ostream& operator<< (ostream&, const stockType&)
//
//Inputs:       ostream&, const stockType&
//Outputs:      ostream&
//Purpose:      The purpose of this function is to overload the stream
//              insertion operator '<<' to be used with the stockType class.
//              Note: This function is a friend function due to the fact that
//              ostream is not an object of type stockType.
ostream& operator<< (ostream& osObject, const stockType& stock)
{
    osObject << stock.stockSymbol << stock.todayOpenPrice 
             << stock.todayClosePrice << stock.todayHigh << stock.todayLow 
             << stock.yesterdayClose << stock.noOfShares;
    return osObject;
}

//--------------------------------------------------------------------------//

//Function:     friend ifstream& operator>> (ifstream&, stockType&)
//
//Inputs:       ifstream&, stockType&
//Outputs:      ifstream&
//Purpose:      The purpose of this function is to overload the stream
//              extraction operator '>>' to be used with the stockType class.
//              note: This function is a friend function due to the fact that
//              ifstream is not an object of type stockType.
ifstream& operator>> (ifstream& isObject, stockType& stock)
{
    isObject >> stock.stockSymbol >> stock.todayOpenPrice 
             >> stock.todayClosePrice >> stock.todayHigh >> stock.todayLow 
             >> stock.yesterdayClose >> stock.noOfShares;
    return isObject;
}

//--------------------------------------------------------------------------//

//Function:     stockType() Constructor
//
//Inputs:       None
//Outputs:      None, Constructor implementation
//Purpose:      The purpose of this function is to define a Constructor 
//              without parameters for the stockType class.
stockType::stockType()
{
    setStockInfo("ECE", 0, 0, 0, 0, 0, 0);
}

//--------------------------------------------------------------------------//

//Function:     stockType (newString symbol, double openPrice, 
//              double closePrice, double High, double Low, double prevClose, 
//              int shares)
//
//Inputs:       newString symbol, double openPrice, double closePrice, 
//              double High, double Low, double prevClose, int shares
//Outputs:      None, Constructor implementation
//Purpose:      The purpose of this function is to define a Constructor with
//              parameters for the stockType class.
stockType::stockType (newString symbol, double openPrice, double closePrice, 
           double High, double Low, double prevClose, int shares)
{
    setStockInfo(symbol, openPrice, closePrice, High, Low, prevClose, shares);
}

//--------------------------------------------------------------------------//