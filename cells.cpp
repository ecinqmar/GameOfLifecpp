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
#include <stdlib.h>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

/*****************************************************
 * PROTOTYPES 
*****************************************************/
static bool isInRange( int val, int low, int high );


/*****************************************************
 * Functions
*****************************************************/

/**
 * @brief print the array in console
 * 
 */
void CellArray::PrintArray()
{
    // temp function
    for (auto x = 0; x < Dimensions; x++)
    {
        for (auto y = 0; y < Dimensions; y++)
        {
            if ( Cells[x][y].thisCell.isActive() )
            {
                cout << "x";
            }
            else
            {
                cout << "-";
            }
        }
        cout << "\n";
    }
    
}

/**
 * @brief perform a life cycle on the game.
 *  determines the amount of partners, then determines the next lifecycle
 *  finally, performs the transition to the next cycle.
 */
void CellArray::Cycle()
{
    for (auto y = 0; y < Dimensions; y++)
    {
        for (auto x = 0; x < Dimensions; x++)
        {
            // determine the amount of active partners
            Cells[x][y].activePartners = this->checkPartners( x , y );
        }
    }

    for (auto y = 0; y < Dimensions; y++)
    {
        for (auto x = 0; x < Dimensions; x++)
        {
            //allow every state to perform the logic
            Cells[x][y].lifeLogic();
        }
    }

    //set the new state of all cells for display
    for (auto y = 0; y < Dimensions; y++)
    {
        for (auto x = 0; x < Dimensions; x++)
        {
             Cells[x][y].lifeCycle();
        }
    }
}

/*****************************************************
 * @brief perform the initial lifecycle.
 * 
*****************************************************/
void CellArray::InitialCycle()
{
    //set the new state of all cells for display
    for (auto y = 0; y < Dimensions; y++)
    {
        for (auto x = 0; x < Dimensions; x++)
        {
             Cells[x][y].lifeCycle();
        }
    }
}

/**
 * @brief check how many partners are active
 * 
 * @return int number of active cells 
 */
int CellArray::checkPartners( int x, int y )
{
    //check if boundaries are available
    int activeCount = 0;

    if ( x == 0 && y == 0)
    {
        // x+1 y+1
        if ( Cells[x+1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y+1].thisCell.isActive() )
        {
            activeCount++;
        }
    }
    else if ( x == (Dimensions - 1 ) && y == (Dimensions - 1 ) )
    {
        // x-1 y-1
        if ( Cells[x-1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y-1].thisCell.isActive() )
        {
            activeCount++;
        }
    }
    else if( x == 0 )
    {
        // x+1 y-1 y+1
        if ( Cells[x+1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y-1].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y+1].thisCell.isActive() )
        {
            activeCount++;
        }        
    }
    else if ( y == 0 )
    {
        // x+1 x-1 y+1 
        if ( Cells[x+1][y].thisCell.isActive() )
        {
            activeCount++;
        }  
        if ( Cells[x-1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y+1].thisCell.isActive() )
        {
            activeCount++;
        }
    }
    else if ( x == (Dimensions - 1 ) )
    {
        // x+1 x-1 y11 
        if ( Cells[x-1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y-1].thisCell.isActive() )
        {
            activeCount++;
        }  
        if ( Cells[x][y+1].thisCell.isActive() )
        {
            activeCount++;
        }
    }
    else if ( y == (Dimensions - 1 ) )
    {
        // x+1 x-1 y+1 
        if ( Cells[x+1][y].thisCell.isActive() )
        {
            activeCount++;
        }  
        if ( Cells[x-1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y-1].thisCell.isActive() )
        {
            activeCount++;
        }
    }
    else
    {
        if ( Cells[x+1][y].thisCell.isActive() )
        {
            activeCount++;
        }  
        if ( Cells[x-1][y].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y-1].thisCell.isActive() )
        {
            activeCount++;
        }
        if ( Cells[x][y+1].thisCell.isActive() )
        {
            activeCount++;
        }
    }

    //if completely out of bounds for some reason it will return 0
    return activeCount;
}

/*****************************************************
* @brief Initial function. get user input for the inital amount of active cells, then seed them randomly.
* 
* @param actives  quantity of inital active cells
*****************************************************/
void CellArray::Seed( int actives )
{
    int totalSize = Dimensions*Dimensions;
    std::vector<int> binary_array(totalSize, 0); // Create an array of zeros of specified size

    // fill the array with _actives_ amount of ones
    for ( auto i = 0; i <= actives ; i++)
    {
        binary_array[i] = 1;
    }

    auto rng = std::default_random_engine {};

    std::srand(std::time(nullptr)); // Seed the random number generator
    std::shuffle( std::begin(binary_array), std::end(binary_array), rng );

    auto iterator = 0;
    for (auto y = 0; y < Dimensions; y++)
    {
        for (auto x = 0; x < Dimensions; x++)
        {
            Cells[x][y].thisCell.setNew(binary_array[iterator]);
            iterator++;
        }
    }
}

/**
 * @brief determine if this cell is going to live or die this cycle.
 * 
 */
void Membrane::lifeLogic()
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

        else if ( this->activePartners < 2 )
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

/*****************************************************
 * @brief affectuate the change of the life cycle for a specific cell
 * 
*****************************************************/
void Membrane::lifeCycle()
{
    this->thisCell.setActive();
}

/**
 * @brief return the current state
 */
bool Cell::isActive()
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

    //clear newstate
    this->newstate = false;
}

/**
 * @brief set the incoming state.
 * 
 * @param incomingstate incoming state
 */
void Cell::setNew( bool incomingstate )
{
    this->newstate = incomingstate;
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