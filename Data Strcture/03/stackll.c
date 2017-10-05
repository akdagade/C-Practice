//
// Created by akshay on 5/10/17.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

struct Node* top=NULL;

void printStack();
void push();
int pop();
int getTop();

int main(){

    int n,ele;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {

        printf("Enter the element : ");
        scanf("%d",&ele);
        push(ele);
        printStack();
    }

    printf("\n~~~~~~~~ Pop ~~~~~~~~\n\n");
    for (int i = 0; i < n; ++i) {
        printStack();
        pop();
    }

}

void printStack() {

    struct Node* tmp=top;
    if(top == NULL) {
        printf("\n No elements in the Stack!!\n");
    }else {

        while (tmp != NULL) {
            printf("%d\t", tmp->data);
            tmp = tmp->next;
        }

        printf("\n");
    }
}

void push(int n){

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=n;
    tmp->next=top;
    top = tmp;
}

int pop(int n){

    int t;
    if(top!=NULL){
        t = top->data;
        top = top->next;
        return t;
    }
    return -1;
}

int getTop(){
    int t=-1;
    if(top!=NULL)
        t = top->data;
    return t;
}