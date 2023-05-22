/*****************************************************
 * @file utlities.cpp
 * @author Ethan Cinq-Mars (ecinqmar@ualberta.ca)
 * @brief 
 * @version 0.1
 * @date 2023-05-22
 * 
 * @copyright Copyright (c) 2023
 * 
*****************************************************/

/*****************************************************
 * @brief includes
*****************************************************/
#include <stdlib.h>

/*****************************************************
 * @brief clear the terminal based on the 
*****************************************************/
void Clear( void )
{
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}