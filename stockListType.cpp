//Homework 27

/*
 *  Filename:           stockListType.cpp
 * 
 *  Purpose:            The purpose of this program is to 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#include "stockListType.h"
#include "listType.h"

//--------------------------------------------------------------------------//

//Function:     void printBySymbol()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to print the list of a
//              portfolio where the stock shares are alphabetically ordered.

void stockListType::printBySymbol()
{
    double closingAssets = 0;
    cout.imbue(locale("en_US.UTF-8"));
    sortBySymbol();
    cout << "        *********  First Investor's Heaven   *********" << endl;
    cout << "        *********      Financial Report      *********" << endl;
    cout << endl;
    cout << "Stock   Today   Today   Today   Today   Previous  Percent";
    cout << endl;
    cout << "Symbol  Open    Close   High    Low     Close     Gain   "  ; 
    cout << "     Volume" << endl;
    cout << "------  ------  ------  ------  ------  --------  -------";
    cout << "     " << endl;

    for(int i = 0; i < length; i++)
    {
        cout << fixed << setprecision(2) << setw(6);
        cout << elements[sortIndiciesGainLoss[i]].getSymbol() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getOpenPrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getClosePrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getHighPrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getLowPrice() << "  ";
        cout << setw(8);
        cout << elements[sortIndiciesGainLoss[i]].getPrevPrice() << "  ";
        cout << setw(7);
        cout << elements[sortIndiciesGainLoss[i]].getPercentChange();
        cout << "%     ";
        cout << setw(6);
        cout << elements[sortIndiciesGainLoss[i]].getNoOfShares();
        closingAssets += (elements[sortIndiciesGainLoss[i]].getClosePrice()
                         *elements[sortIndiciesGainLoss[i]].getNoOfShares());
        cout << endl;                
    }
    cout << endl << endl;
    cout << "Closing Assets: $" << closingAssets;
    cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
    cout << endl;
    
}

//--------------------------------------------------------------------------//

//Function:     void printByGain()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to print the list of a
//              portfolio where the stock shares are ordered in order from
//              the highest gain to the lowest gain.

void stockListType::printByGain()
{
    cout.imbue(locale("en_US.UTF-8"));
    sortByGain();
    cout << "        *********  First Investor's Heaven   *********" << endl;
    cout << "        *********     Financial Report       *********" << endl;
    cout << "        *********         Gain/Loss          *********" << endl;
    cout << endl;
    cout << "Stock   Today   Today   Today   Today   Previous  Percent";
    cout << endl;
    cout << "Symbol  Open    Close   High    Low     Close     Gain   "  ; 
    cout << "     Volume" << endl;
    cout << "------  ------  ------  ------  ------  --------  -------";
    cout << "     " << endl;

    for(int i = 0; i < length; i++)
    {
        cout << elements[sortIndiciesGainLoss[i]].getSymbol() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getOpenPrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getClosePrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getHighPrice() << "  ";
        cout << elements[sortIndiciesGainLoss[i]].getLowPrice() << "  ";
        cout << setw(8);
        cout << elements[sortIndiciesGainLoss[i]].getPrevPrice() << "  ";
        cout << setw(7);
        cout << elements[sortIndiciesGainLoss[i]].getPercentChange();
        cout << "%     ";
        cout << setw(6);
        cout << elements[sortIndiciesGainLoss[i]].getNoOfShares();
        cout << endl;                
    }
    cout << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
    cout << endl;
}

//--------------------------------------------------------------------------//

//Function:     void printReports()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this program is to print a full report. The
//              function calls both printBySymbol() and printByGain().

void stockListType::printReports()
{
    printBySymbol();
    printByGain();
}

//--------------------------------------------------------------------------//

//Function:     void sortBySymbol()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to use the predefined sort
//              function to sort the list in alphabetical order. Because the
//              stockType relational operators are overloaded, no function
//              redefinition is required.

void stockListType::sortBySymbol()
{
    if(!isEmptyList())
    {
        //Placeholder temp variable
        stockType rahul;
        for(int i = 0; i < length; i++)
        {
            for(int j = 0; j < length - 1; j++)
            {
                //Compare elements
                if(elements[j] > elements[j+1])
                {
                    //Swap if items at index j < items at index j+1
                    rahul = elements[j];
                    elements[j] = elements[j+1];
                    elements[j+1] = rahul;
                }
            }
        }
    }
    else
    {
        cout << "List is empty" << endl;
    }
    
}

//--------------------------------------------------------------------------//

//Function:     void sortByGain()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to fill a dynamic array with
//              the index values of a list that is sorted by the gain in the
//              order of largest to smallest.

void stockListType::sortByGain()
{
    int temp;
    sortBySymbol();
    for(int i = 0; i < length; i++)
    {
        sortIndiciesGainLoss[i] = i;
    }
        
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length-1; j++)
        {
            if(elements[j].getPercentChange() < 
               elements[j+1].getPercentChange())
            {
                temp = sortIndiciesGainLoss[j];
                sortIndiciesGainLoss[j] = sortIndiciesGainLoss[j+1];
                sortIndiciesGainLoss[j+1] = temp;
            }
        }
    }
}

//--------------------------------------------------------------------------//

//Function:     stockListType()  |  Constructor
//
//Inputs:       None
//Outputs:      None, Constructor implementation
//Purpose:      Constructor implementation for default values upon
//              instantiation.

stockListType::stockListType()
{
    listType();
    sortIndiciesGainLoss = new int[50];
}

//--------------------------------------------------------------------------//

//Function:     stockListType(int size)  |  Constructor
//
//Inputs:       int size
//Outputs:      None, Constructor implementation
//Purpose:      Constructor implementation for Constructor with parameters.

stockListType::stockListType(int size)
{
    assert(size <= maxSize);
    if(size <= 0)
    {
        cout << "Array must be positive. Creating array of length 50";
        cout << endl;
        sortIndiciesGainLoss = new int[50];
        listType(50);
    }
    else
    {
        sortIndiciesGainLoss = new int[size];
        listType(size);
    }
    
}

//--------------------------------------------------------------------------//

//Function:     ~stockTypeList()  |  Destructor
//
//Inputs:       None
//Outputs:      None, Destructor Implementation
//Purpose:      The purpose of this program is to define the implementation
//              of the destructor for the stockListType class

stockListType::~stockListType()
{
    delete [] sortIndiciesGainLoss;
}

//--------------------------------------------------------------------------//