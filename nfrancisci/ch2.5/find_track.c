/* find_track.c
 * ------------
 * Nick Francisci
 *
 * A program which searches through a set of 'music tracks'
 * via a regex search.
 *
 * Based on example code (c) 2014 Allen Downey
 * License: Creative Commons Attribution-ShareAlike 3.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};

/*
 * Finds all tracks that match the given pattern.
 * Prints track number and title.
 *
 * pattern: The regex pattern to match
 */
void find_track_regex(char pattern[])
{
    regex_t* regex;
    int status = regcomp(regex, pattern, REG_EXTENDED);

    // Catch regex compilation errors, if any, and exit with error
    if (status != 0) {
        puts("Error in compiling regex!");
        regfree(regex);
        exit(EXIT_FAILURE);
    }

    // Declare variables needed to test 
    int nomatch;
    int num_matches = 1;
    regmatch_t matches[num_matches];

    // Search all tracks for matches
    for (int i=0; i < NUM_TRACKS; i++) {
       nomatch = regexec(regex, tracks[i], num_matches, matches, 0);

       // If a match occurs, print out the matched track name
       if (!nomatch) printf("Track %i: '%s'\n", i, tracks[i]);
    }

    regfree(regex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
	*ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // Find all tracks that match the inputted pattern
    find_track_regex(search_for);

    return 0;
}
