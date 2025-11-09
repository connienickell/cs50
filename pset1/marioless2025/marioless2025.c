#include <stdio.h>
#include <cs50.h>

int main (void){

        int size = get_int("size:");

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size -i -1; j++){
             printf(" ");
        }

            for (int k = size - i -1; k < size; k++){
            printf("#");
        }
    printf("\n");

    }
    return 0;
}

