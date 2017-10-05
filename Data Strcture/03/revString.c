//
// Created by akshay on 5/10/17.
//

//
// Created by akshay on 5/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node * next;
};

struct Node* top=NULL;

void printStack();
void push(char n);
char pop();
char getTop();

int main(){

    int n;
    char ele[20];
    printf("\nEnter the string : \n");
    gets(ele);
    printf("\nThe string is : %s\n",ele);
    for (int i = 0; i < strlen(ele); ++i)
        push(ele[i]);

    printf("\n~~~~~~~~ Rev ~~~~~~~~\n\n");
    for (int i = 0; i < strlen(ele); ++i)
        ele[i]=pop();

    printf("The reversed string is : %s\n\n",ele);
}

void printStack() {

    struct Node* tmp=top;
    if(top == NULL) {
        printf("\n No elements in the Stack!!\n");
    }else {

        while (tmp != NULL) {
            printf("%c\t", tmp->data);
            tmp = tmp->next;
        }

        printf("\n");
    }
}

void push(char n){

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=n;
    tmp->next=top;
    top = tmp;
}

char pop(){

    char t;
    if(top!=NULL){
        t = top->data;
        top = top->next;
        return t;
    }
    return '\0';
}

char getTop(){
    char t='\0';
    if(top!=NULL)
        t = top->data;
    return t;
}

