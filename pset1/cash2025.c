#include <stdio.h>
#include <cs50.h>
#include <cs50.h>

int change;

int counter;

int main (void){
    do {
    change = get_int("Please enter change:");
    }
    while (change < 0);
    if (change == 0){
        printf("0 \n");
    }
    counter = 0;
    while(change > 24){
        change -= 25;
        counter++;
    }
    while(change > 9){
        change -= 10;
        counter++;
    }
    while(change > 4){
        change -= 5;
        counter++;
    }
    while(change > 0){
        change -= 1;
        counter++;
    }
    printf("%i \n", counter);
    return 0;
}
