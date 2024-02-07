#include "search_algos.h"

/**
 * linear_search - searches for a value in an array.
 * integers using the Linear search algorithm
 *
 * @array: is a pointer to the first element of the array to search in
 * @size: is the number of elements in array
 * @value: is the value to search for
 * Returns: -1 if array is NULL or size is 0
 */
int linear_search(int *array, size_t size, int value)
{
    int i;

    if (array == NULL || size == 0)
    {
        return -1;
    }

    for (i = 0; i < (int)size; i++)
    {
        printf("Value checked array[%u] = [%d]\n", i, array[i]);
        if (value == array[i])
        {
            return i;
        }
    }

    return -1;
}

