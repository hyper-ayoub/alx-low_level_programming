#include "shell.h"

/**
* afree - free a pointer and NULLs the address
* @ptr1: address of pointer to be free.
*
*Return: 1 if freed , otherwise 0.
*/
int afree(void **ptr1)
{
    if (ptr1 && *ptr1)
    {
        free(*ptr1);
        *ptr1 = NULL;
        return (1);
    }
    return (0);
}

