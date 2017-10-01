//
// Created by akshay on 9/9/17.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    puts("Rolling the dice!!");

    int nsum,face,sum;
    nsum=face=sum=0;
    for (int i = 0; i < 3; ++i) {
        face=( rand()%6 )+1;
        sum += face;
        printf("%d ",face);
    }

    printf("\nSum is : %d.\n", sum);
    puts("What will be the next roll? (h/l/s) : ");
    char option;
    scanf("%c", &option);

    for (int i = 0; i < 3; ++i) {
        face=( rand()%6 )+1;
        nsum += face;
        printf("%d ",face);
    }
    printf("\nNew sum is : %d.\n", nsum);

    if((option=='h' && nsum>sum) || (option=='l' && nsum<sum) || (option=='s' && nsum==sum))
        puts("You are a wizard!");
    else
        puts("You suck!");


    return 0;
}