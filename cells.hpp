/**
 * @file cell.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-05-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>
#include <string>

const int Dimensions = 15;

class Cell
{
    public:
        bool active;
        bool newstate;

        Cell( void )
        {
            active = false;
            newstate = false;
        }

        ~Cell( void )
        {

        }

        bool isActive( void );
        void setActive( void );
        void setNew( bool incomingstate );

};

/**
 * @brief handle all operations of a cell.
 * 
 */
class Membrane
{
    public:
        //vars 
        char    displayToken;
        uint8_t activePartners;
        Cell    thisCell;       //holds display char for the 


        Membrane( )
        {
            activePartners = 0; 
        };

        ~Membrane( void )
        {

        };

        //perform the logic of a life cycle
        void lifeLogic( void );

        // affectuate the change of the life cycle
        void lifeCycle( void );

};

/*****************************************************
 * @brief handle operations along the entire array
 * 
*****************************************************/
class CellArray
{
    public:

        Membrane Cells[Dimensions][Dimensions];

        CellArray()
        {
            //create an array of 

        };

        ~CellArray()
        {

        }

        /*****************************************************
         * @brief Initial function. get user input for the inital amount of active cells, then seed them randomly.
         * 
         * @param initalActives  quantity of inital active cells
        *****************************************************/
        void Seed( int initalActives );

        /**
         * @brief Print the array in the console
         * 
         */
        void PrintArray( void );

        /**
         * @brief Perform all necessary logic
         * 
         */
        void Cycle( void );

        /*****************************************************
         * @brief 
         * 
        *****************************************************/
        void InitialCycle();


    private:

    int checkPartners( int x, int y );
    void generate( void );
};
