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

/*
 * Given a card's name, returns the value of the card
 * or -1, if the card is invalid.
 *
 * card_name: buffer for a card's name
 */
int parseCard(char* card_name) {
    int val;

    if (card_name[0] == 'A') val = 11;
    else if (card_name[0] == 'K' ||
        card_name[0] == 'Q' ||
        card_name[0] == 'J' ) val = 10;
    else {
        val = atoi(card_name);

        // Catch invalid card values
        if (val > 10 || val < 2) return -1;
    }

    return val;
}

int main() {
    const char EXIT_FLAG = 'X';
    int val;

    // Take user input
    char card_name[3];
    int count = 0;

    do {
        puts("Enter the card name: ");
        scanf("%2s", card_name);

        // Shortcut to exit
        if (card_name[0] == EXIT_FLAG) return 0;

        // Get value of card
        val = parseCard(card_name);

        // Check if count value has gone up or down
        if (val == -1) {
            continue;
            printf("Invalid card value.\n");
        }
        else if (val >= 3 && val <= 6) count++;
        else if (val == 10) count--;

        // Display count
        printf("Current count: %i\n", count);
    } while (card_name[0] != EXIT_FLAG);
    return 0;
}
