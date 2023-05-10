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

class CellArray
{
    public:
        //display 
        Membrane Array[Dimensions][Dimensions];

        CellArray()
        {

        };

        ~CellArray()
        {

        }

        /**
         * @brief Print the array in the console
         * 
         */
        void PrintArray( void );

        /**
         * @brief print the 
         * 
         */
        void Cycle( void );


    private:

};

/**
 * @brief handle all operations around a cell and the cells next to it.
 * 
 */
class Membrane
{
    public:
        //vars 
        char    displayToken;
        uint8_t activePartners;
        Cell    thisCell;       //holds display char for the 
        int     position, xCord, yCord;;


        Membrane( void )
        {
            activePartners = 0; 
            position = 0;
        };

        ~Membrane( void )
        {

        };

        void lifeCycle( void );

    private:
        int checkPartners( void );

};

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

        bool checkActive( void );
        void setActive( void );
        void setNew( bool newstate );
};
