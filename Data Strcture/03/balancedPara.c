//
// Created by akshay on 6/10/17.
//

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

    int n,flag;
    char ele[20],c;
    printf("\nEnter the string : \n");
    gets(ele);
    printf("\nThe string is : %s\n",ele);
    flag=0;
    for (int i = 0; i < strlen(ele); ++i){
        c=ele[i];
        if(c=='[' || c=='(' || c=='{')
            push(c);

        else if(c==']' || c==')' || c=='}'){
            if(getTop()=='\0'){
                flag=1;
            }
            switch(c) {
                case ']':
                    if (pop() != '[')
                        flag = 1;
                    break;
                case ')':
                    if (pop() != '(')
                        flag = 1;
                    break;
                case '}':
                    if (pop() != '{')
                        flag = 1;
                    break;
            }
        }

    }

    if(flag==1 || getTop()!='\0'){
        printf("Its unbalanced!!!\n");
        return -1;
    }else{
        printf("Its balanced!!!\n");
        return -1;
    }

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

