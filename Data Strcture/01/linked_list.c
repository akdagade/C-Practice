//
// Created by akshay on 1/10/17.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
} node;

void printList(struct Node* head);
struct Node*  insertStart(struct Node* head, int num);
struct Node* insertAt(struct Node* head, int num, int pos);

int main(){

    struct Node* head = NULL;

    int n,ele,p;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {

        printf("Enter the element : ");
        scanf("%d",&ele);
        printf("Enter the position : ");
        scanf("%d",&p);
        head = insertAt(head,ele,p);
        printList(head);
    }

    return 0;
}//main


void printList(struct Node* head){

    if(head == NULL) {
        printf("\n No elements in the List!!\n");
    }else {

        while (head->next != NULL) {
            printf("%d\t", head->data);
            head = head->next;
        }

        printf("%d\n", head->data);
    }
}//printList

struct Node* insertStart(struct Node* head, int num){

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=num;
    tmp->next=NULL;

    if(head==NULL)
        head=tmp;
    else
        tmp->next = head;
    return tmp;
}//insertStart

struct Node* insertAt(struct Node* head, int num, int pos){

    if(head==NULL && pos!=1){
        printf("\nHead is not initialized, insert at position 1!!\n");
        return head;
    }
    struct Node* hd=head;
    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=num;
    tmp->next=NULL;
    int counter=1;


    if(pos==1){
        return insertStart(hd,num);
    }

    while (head->next!=NULL){
            if(pos-1==counter){
                tmp->next= head->next;
                head->next = tmp;
                return hd;
            }
            head=head->next;
            counter++;
        }

    if(counter==pos-1){
        head->next=tmp;
    } else {
        printf("\nYou have entered invalid no of elements!!\n");
    }
    return hd;
}//insertAt

