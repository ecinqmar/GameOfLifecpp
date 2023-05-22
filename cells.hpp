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

        bool checkActive( void );
        void setActive( void );
        void setNew( bool newstate );

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


        Membrane( int x, int y )
        {
            xCord = x;
            yCord = y;
            activePartners = 0; 
            position = 0;
        };

        ~Membrane( void )
        {

        };

        void lifeCycle( void );

};


class CellArray
{
    public:

        Cell Cells[Dimensions][Dimensions];

        CellArray()
        {
            //create an array of 

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
         * @brief Perform all necessary logic
         * 
         */
        void Cycle( void );

    private:

    int checkPartners( void );
    void generate( void );
};
