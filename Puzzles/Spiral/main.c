//
// Created by akshay on 21/10/17.
//

#include <stdlib.h>
#include <stdio.h>

int main(){

    int n,m,d,si,sj;
    m=4;
    n=4;

    int **A;
    A = (int **) malloc(n*sizeof(int*));

    int v=1;
    for (int i = 0; i < n; ++i) {
        *(A+i) = (int *) malloc(m*sizeof(int));
        for (int j = 0; j < m; ++j) {
            A[i][j]=v;
            v++;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("\t%d",A[i][j]);

        }
    }
    printf("\n");

    d=1;
    si=n;
    sj=m+1;
    int i,j;
    i=0;
    j=-1;
    int c=1;
    while(c!=(m*n)+1){
        if(d==1){
            sj--;
            for(int k=0;k<sj;k++){
                A[i][++j]=c;
                c++;
            }
            d++;
        }
        else if(d==2){
            si--;
            for(int k=0;k<si;k++){
                A[++i][j]=c;
                c++;
            }
            d++;
        }
        else if(d==3){
            sj--;
            for(int k=0;k<sj;k++){
                A[i][--j]=c;
                c++;
            }
            d++;
        }
        else if(d==4){
            si--;
            for(int k=0;k<si;k++){
                A[--i][j]=c;
                c++;
            }
            d=1;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("\n");
        for (int j = 0; j < m; ++j) {
            printf("\t%d",A[i][j]);

        }
    }
    printf("\n");

    return 0;
}//main