#include <stdio.h>
#include <cs50.h>

int main(void) {
    double change;
    int coins = 0;

    do {
        printf("Change owed: ");
        change = get_double();
    } while(change < 0);

    //Convert to cents
    int money = change * 100;

    int quarters = 0;
    int dimes = 0;
    int nickels = 0;

    if(money >= 25) {
        quarters = money / 25;
        money = money - (quarters * 25);
    }
    if(money >= 10) {
        dimes = money / 10;
        money = money - (dimes * 10);
    }
    if(money >= 5) {
        nickels = money / 5;
        money = money - (nickels * 5);
    }
    //Add up all the types of coins to get total coins
    //The money variable represents the remaining pennies
    coins = quarters + dimes + nickels + money;
    printf("%i\n", coins);


}