/**
 * Encrypts user's message through Vigenere
 **/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[]) {
    //Check if there are two arguments
    if (argc != 2) {
        printf("Error: Must have two arguments\n");
        return 1;
    }

    string key = argv[1];

    //Check if key is alphabetic
    int keyLength = strlen(key);
    for (int i = 0; i < keyLength; i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key is non-alpha\n");
            return 1;
        }
    }

    string plainText = get_string("plaintext: ");

    int count = 0;
    //Increment plainText[i] by key[j]
    for (int i = 0, n = strlen(plainText); i < n; i++) {
        if (isalpha(plainText[i])) {
            if (islower(plainText[i])) {
                int j = count % keyLength; //Position of each character of key
                plainText[i] = (((plainText[i] - 97) + (tolower(key[j]) - 97)) % 26) + 97;
                count++;
            } else {
                int j = count % keyLength;
                plainText[i] = (((plainText[i] - 65) + (toupper(key[j]) + 65)) % 26) + 65;
                count++;
            }
        }
    }
    printf("\nciphertext: %s\n", plainText);
}

