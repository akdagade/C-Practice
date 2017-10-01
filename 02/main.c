//
// Created by akshay on 9/9/17.
//

#include <stdio.h>
#include <ctype.h>
int main(){

    char password[20];
    printf("Enter a password : ");
    scanf("%s", password);

    int cap=0b0000;

    for (int i = 0; password[i] != '\0' ; ++i) {

        if(isupper(password[i]))
            cap |= 0b0001;
        if(isdigit(password[i]))
            cap |= 0b0010;
        if(password[i] == '$')
            cap |= 0b0100;
        printf("%d ",cap);
        if(cap==7)
            break;
    }

    if(cap==7)
        printf("\n Cool! Your password is accepted\n");
    else
        printf("\n Password sucks!!\n");

    return 0;
}