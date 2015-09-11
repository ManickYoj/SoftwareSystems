/* natural_number.c
 * ----------------
 * Nick Francisci
 * 
 * A quick test of some of the c code in the assembly/C reading here:
 * https://www.recurse.com/blog/7-understanding-c-by-learning-assembly 
 */

#include <stdio.h>

int naturalNumber () {
    static int b = -1;
    return b++;
}

int main() {
    printf("%i\n", naturalNumber());
    printf("%i\n", naturalNumber());
    printf("%i\n", naturalNumber());
}