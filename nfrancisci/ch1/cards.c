/*
 * cards.c
 * -------
 * Nick Francisci
 *
 * Program to evaluate card face values
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char EXIT_FLAG = 'X';

    // Take user input
    char card_name[3];
    int count = 0;
    do {
        puts("Enter the card name: ");
        scanf("%2s", card_name);

        // Shortcut to breaking to exit
        if (card_name[0] == EXIT_FLAG) return 0;

        // Parse user input to value
        int val = 0;
        if (card_name[0] == 'A') val = 11;
        else if (card_name[0] == 'K' ||
            card_name[0] == 'Q' ||
            card_name[0] == 'J' ) val = 10;
        else {
            val = atoi(card_name);

            // Catch invalid card values
            if (val > 10 || val < 2) {
                printf("Invalid card value.\n");
                continue;
            }
        }


        // Check if count value has gone up or down
        if (val >= 3 && val <= 6) count++;
        else if (val == 10) count--;

        // Display count
        printf("Current count: %i\n", count);
    } while (card_name[0] != EXIT_FLAG);
    return 0;
}
