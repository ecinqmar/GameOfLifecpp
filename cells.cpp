/**
 * @file cells.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "cells.hpp" 
#include <stdint.h>
#include <iostream>

using namespace std;

/**\
 * prototypes
*/
static bool isInRange( int val, int low, int high );


/**
 * @brief print the array in console
 * 
 */
void CellArray::PrintArray()
{
    for (auto i = 0; i < Dimensions; i++)
    {
        for (auto i = 0; i < Dimensions; i++)
        {
            cout << "x"; 
        }
        cout << "\n";
    }
    
}

/**
 * @brief process loop for checking the 
 * 
 */
void CellArray::Cycle()
{
    for (auto i = 0; i < Dimensions; i++)
    {
        for (auto i = 0; i < Dimensions; i++)
        {
            
        }
    }
}

/**
 * @brief check how many partners are active
 * 
 * @return int number of active cells 
 */
int Membrane::checkPartners()
{

    //check if boundaries are available
    return 0;
}

/**
 * @brief determine if this cell is going to live or die this cycle.
 * 
 */
void Membrane::lifeCycle()
{
    /* rules:
    Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies, as if by overpopulation.
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    */

   if ( thisCell.active = true )
   {
        if (this->activePartners > 3) //greater than 3 dies
        {
            thisCell.setNew(false);
        }

        else if( isInRange(activePartners, 2, 3) ) // two or three lives on to next generation
        {
            thisCell.setNew(true);
        }

        else if ( this->activePartners <= 2 )
        {
            thisCell.setNew(false);
        }
   }
   else if ( thisCell.active == false && this->activePartners == 3 )
   {
        thisCell.setNew(true);
   }
   else
   {
        thisCell.setNew(false);
   }
}

/**
 * @brief return the current state
 */
bool Cell::checkActive()
{
    return this->active;
}

/**
 * @brief set the current state to the new one.
 * 
 * @param newState incoming state
 */
void Cell::setActive( void )
{
    this->active = this->newstate;
}

/**
 * @brief set the incoming state.
 * 
 * @param newstate incoming state
 */
void Cell::setNew( bool newstate )
{
    this->newstate = newstate;
}

/**
 * @brief simple var check
 * 
 * @param val 
 * @param low 
 * @param high 
 * @return true 
 * @return false 
 */
static bool isInRange( int val, int low, int high )
{
    return ( val >= low ) && ( val && high );
}