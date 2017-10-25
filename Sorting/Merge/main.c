//
// Created by akshay on 25/10/17.
//
#include <stdio.h>
#include <stdlib.h>

void mergeArray(int, int, int);
void mergeSort(int , int);

int a[8] = {2,4,1,6,8,5,3,7};
int b[8];
int main(){

    printf("\n");
    for(int i= 0; i<8;i++)
        printf("%d\t",a[i]);
    printf("\n");

    mergeSort(0,7);

    printf("\n");
    for(int i= 0; i<8;i++)
        printf("%d\t",b[i]);
    printf("\n");

}

void mergeSort(int l, int u){

    if(l>=u)
        return;
    int m = (l+u)/2;
    mergeSort(l,m);
    mergeSort(m+1,u);
    mergeArray(l,m,u);
}

void mergeArray(int l, int m, int u){

    int i=l,j=m+1,k=l;
    while (i<m+1 && j< u+1){
        if(a[i] <= a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while(i<m+1){
        b[k] = a[i];
        i++; k++;
    }

    while(j<u+1){
        b[k] = a[j];
        j++; k++;
    }

    for(int i=l;i<=u;i++)
        a[i]=b[i];

}
