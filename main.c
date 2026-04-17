#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "menu.h"
#include "student.h"

/*Header*/
int main() 
{
    status status = STATUS_ERROR;
    status = menuMain();
    if(status == STATUS_SUCCESS)
    {
        printf("Menu executed successfully\n");
        return 1;
    }
    else
    {
        printf("An error occurred while executing the menu.\n");
    }
    return 0;
}