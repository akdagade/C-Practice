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
struct Node* deleteAt(struct Node* head, int pos);
struct Node* revList(struct Node* head);

int main(){

    struct Node* head = NULL;

    int n,ele,p;
    /*
    head = insertStart(head,1);
    head = insertStart(head,2);
    head = insertStart(head,3);
    head = insertStart(head,4);
    head = insertStart(head,5);
    head = insertStart(head,6);
    printList(head);*/

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

    printf("\n~~~~~Delete~~~~~\n");
    for (int i = 0; i < 2; ++i) {

        printf("Enter the position to delete : ");
        scanf("%d",&p);
        head = deleteAt(head,p);
        printList(head);
    }

    printf("\n~~~~~Reverse~~~~~\n");
    head = revList(head);
    printList(head);

    return 0;
}//main


void printList(struct Node* head){

    if(head == NULL) {
        printf("\n No elements in the List!!\n");
    }else {

        while (head != NULL) {
            printf("%d\t", head->data);
            head = head->next;
        }

        printf("\n");

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
    if(pos==1){
        return insertStart(hd,num);
    }

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=num;
    tmp->next=NULL;
    int counter=1;

    while (head!=NULL){
            if(pos-1==counter){
                tmp->next= head->next;
                head->next = tmp;
                return hd;
            }
            head=head->next;
            counter++;
        }

    printf("\nYou have entered invalid no of elements!!\n");
    return hd;
}//insertAt


struct Node* deleteAt(struct Node* head, int pos){

    if(head==NULL){
        printf("No elements to delete!!");
        return head;
    }

    struct Node* prv=NULL;
    if(pos==1){
        prv=head->next;
        free(head);
        return prv;
    }

    int counter=1;
    struct Node* hd=head;
    while (head->next!=NULL){
        if(pos-1==counter){
            prv = head->next->next;
            free(head->next);
            head->next = prv;
            return hd;
        }
        prv=head;
        head=head->next;
        counter++;
    }

    printf("\nYou have entered invalid no of elements!!\n");
    return hd;

}//deleteAt

struct Node* revList(struct Node* head){

    struct Node* tmp=NULL;
    struct Node* prv=NULL;
    int counter=1;

    if(counter=1 && head->next==NULL){
        return head;
    }

    while (head!=NULL){

        tmp= head->next;
        if(counter==1){
            head->next=NULL;
        }
        else{
            head->next=prv;
        }
        prv = head;
        head = tmp;
    }

    return prv;
}//revList