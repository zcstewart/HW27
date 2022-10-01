//Homework 27

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to implement all of the 
 *                      included header and implementation files to create a 
 *                      working program.
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "newString.h"
#include "listType.h"
#include "stockListType.h"
#include "stockType.h"

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

//Function:     main()
//
//Inputs:       int argc, char** argv
//Outputs:      None
//Purpose:      The purpose of this function is to implement all of the
//              included header and implementation files to create a working
//              program.
int main(int argc, char** argv)
{
    char fileName[51];
    
    //Prompt user to enter name of data file
    cout << "Enter the name of the file to be read: " << endl;
    cin >> fileName;
    
    //Declare filestream variable
    ifstream inData;
    
    //Open data file. Use c_str function to convert to a c-string to allow
    //the file to be opened
    inData.open(fileName);
    
    //Terminate program if file not opened.
    if(!inData)
    {
        cout << "Data file not found. Program terminating." << endl;
        exit(EXIT_FAILURE);
    }
    
//    stockListType testList(40);
//    testList.getList(inData);
//    testList.printReports();    
    
    //Close inData file
    inData.close();
    
    //Successfully terminate program upon completion
    exit(EXIT_SUCCESS);
}

//--------------------------------------------------------------------------//

