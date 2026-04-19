/* main.c - main function */
/*
* Copyright (c) 2026 Trenser Technology Solutions (P) Ltd
*/
/*
modification history --------------------
19april26, Updated Implementations
*/
/*
DESCRIPTION
This module is the includes main function of the system. The function uses the 
following functions defined in menu.h, student.h
INCLUDE FILES: menu.h, student.h
*/

/* includes */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "menu.h"
#include "student.h"

/*******************************************************************************
*
* main - This function invoke mainMenu function 
* 
*
* DESCRIPTION
* The function [main] will invoke mainMenu function to store data from students
*
* PARAMETERS
* \is
* \i N/A
* \ie
*
* GLOBALS:
* \is
*
* \i N/A
* \ie
*
* RETURNS:
* \is
* \i <FAILURE>
* when mainMenu fails
*
* \i <SUCCESS>
* when mainMenu success
*
* \ie
* 
* ERRNO:
* \is
* \i N/A
*
* \i N/A
* \ie
*
* SEE ALSO:
* Thread.c
*
* \INTERNAL
*/

int main() 
{
    while(1)
    {

        status status = STATUS_ERROR;
        status = menuMain();
        if(status == STATUS_SUCCESS)
        {
            printf("Menu executed successfully\n");
        }
        else
        {
            printf("An error occurred while executing the menu.\n");
        }
    }

    return 0;
}