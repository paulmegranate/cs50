// Helper functions for music

#include <cs50.h>
#include <math.h>
#include "helpers.h"
#include <stdio.h>
#include <string.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    char X = atoi(&fraction[0]);
    char Y = atoi(&fraction[2]);
    int result = (8.0/Y) * X;
    return result;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
    int n = 0;
    char letter = note[0];
    char accidental;
    int octave;
    if(strlen(note) == 3) {
        accidental = note[1];
        octave = atoi(&note[2]);
        if(accidental == '#') {
            n += 1;
        } else if (accidental == 'b') {
            n -= 1;
        }
    } else {
        octave = atoi(&note[1]);
    }

    switch (letter) {
        case 'A':
            n += 0;
            break;
        case 'B':
            n += 2;
            break;
        case 'C':
            n -= 9;
            break;
        case 'D':
            n -= 7;
            break;
        case 'E':
            n -= 5;
            break;
        case 'F':
            n -= 4;
            break;
        case 'G':
            n -= 2;
            break;
    }

    n += (octave - 4) * 12;
    float exponent = n / 12.0;
    float results = round(pow(2, exponent) * 440);
    return results;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if (strcmp(s, "") == 0)
        return true;
    else
        return false;
}
