/**
 * Encrypts user's message through caesar cipher
 **/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[]) {
    //Check if user enters in correct number of arguments
    if(argc != 2) {
        printf("Error: Must have two arguments\n");
        return 1;
    } else {
        int k = atoi(argv[1]); //Key
        string plainText = get_string("plaintext: ");
        for (int i = 0, n = strlen(plainText); i < n; i++) {
            if (isalpha(plainText[i])) {
                if (islower(plainText[i])) {
                    plainText[i] = (((plainText[i] - 97) + k) % 26) +
                        97; //Convert from ascii to alpha to do the calculation and then convert back to ascii (lower case)
                } else {
                    plainText[i] = (((plainText[i] - 65) + k) % 26) +
                        65; //Convert from ascii to alpha to do the calculation and then convert back to ascii (upper case)
                }
            }
        }
        printf("ciphertext: %s\n", plainText);
    }
}

