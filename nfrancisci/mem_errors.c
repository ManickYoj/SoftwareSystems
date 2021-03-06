/* Example code for Software Systems at Olin College.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int read_element(int *array, int index) {
    int x = array[index];
    return x;
}


int main ()
{
    int *free_twice = malloc (sizeof (int));
    int *use_after_free = malloc (sizeof (int));
    int *never_free = malloc (sizeof (int));
    int array1[100];
    int *array2 = malloc (100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    read_element(array1, -1);
    read_element(array1, 100);

    // but it does bounds-check dynamic arrays
    read_element(array2, -1);
    read_element(array2, 100);

    // and it catches use after free
    free(use_after_free);
    *use_after_free = 17;

    // never_free is definitely lost
    *never_free = 17;

    free(never_free);
    free(free_twice);

    return 0;
}
