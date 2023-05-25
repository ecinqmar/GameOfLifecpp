/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "main.hpp"
#include "cells.hpp"
#include "utilities.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

CellArray Cellarray;

int main( )
{
    int ActiveNum = 0;

    //get user input
    cout << "Enter the amount of starting cells:";
    cin >> ActiveNum;
    // get inital condition
    Cellarray.Seed( ActiveNum );

    Cellarray.InitialCycle();
    Cellarray.PrintArray();

    // go forever
    while(1)
    {
        //clear the current screen
        Clear();

        //perform all logic then print the results
        Cellarray.Cycle();
        Cellarray.PrintArray();

        //delay for a second
        this_thread::sleep_for(1s);   
    }

    return 0;
}