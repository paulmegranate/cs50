#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    //Prompt user for height
    do {
        printf("Height: ");
        height = get_int();
    } while(height < 0 || height > 23);

    for(int i = 0; i < height; i++) {
        //Keep track of spaces
        for(int s = height - (i + 1); s > 0; s--) {
            printf(" ");
        }
        //Keep track of hashes
        for(int h = 0; h < i + 2; h++) {
            printf("#");
        }
        printf("\n");
    }
}