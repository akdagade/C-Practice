//
// Created by akshay on 26/10/17.
//

#include <stdlib.h>
#include <stdio.h>

int partition(int*, int, int);
void quickSort(int*, int, int);

int main(){

    int a[12]={7,2,1,6,8,5,3,4,33,14,11,10};

    for(int i= 0; i<12;i++)
        printf("%d\t",a[i]);
    printf("\n");

    quickSort(a,0,11);

    for(int i= 0; i<12;i++)
        printf("%d\t",a[i]);
    printf("\n");
    return 0;
} //main

void quickSort(int* a, int s, int e){

    if(s>=e)
        return;
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int partition(int* a, int s, int e){

    int pivot = a[e];
    int pin = s;
    int tmp;

    for (int i = s; i<=e; i++) {
        if(a[i] <= pivot){
            tmp = a[pin];
            a[pin] = a[i];
            a[i] = tmp;
            pin++;
        }
    }

    return --pin;
}

