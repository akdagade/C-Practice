//
// Created by akshay on 9/9/17.
//

#include <stdio.h>
#include <stdlib.h>

int main(){

    int val=19;
    printf("%d\t%p\n\n",val,&val);

    int * pVal = &val;
    printf("%p\t%d\n\n",pVal,*pVal);

    *pVal=69;
    printf("%d\t%p\n\n",val,&val);
    free();
    return 0;
}