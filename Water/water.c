#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("Minutes: ");
    int numMinutes = get_int();
    printf("Bottles: %i", numMinutes*12);
}