//
// Created by akshay on 3/10/17.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{

    struct Node* prv;
    int data;
    struct Node* next;

}; //node

struct Node* insertAt(struct Node* head, int n, int pos);
struct Node* deleteAt(struct Node* head, int pos);
void printList(struct Node* head);

int main(){

    int p,count,n;
    struct Node* head=NULL;
    printf("Enter the number of nodes : ");
    scanf("%d",&count);

    printf("~~~~~~~~ Insert At ~~~~~~~~\n");
    for (int i = 0; i < count; ++i) {
        printf("Enter the number : ");
        scanf("%d",&n);
        printf("Enter the position : ");
        scanf("%d",&p);
        head=insertAt(head,n,p);
        printList(head);
    }

    printf("~~~~~~~~ Delete At ~~~~~~~~\n");
    for (int i = 0; i < count; ++i) {

        printf("Enter the position : ");
        scanf("%d",&p);
    }

    return 0;
}//main


struct Node* insertAt(struct Node* head, int n, int pos){

    struct Node* tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->data=n;
    tmp->next=NULL;
    tmp->prv=NULL;

    if(head == NULL && pos==1){
        return tmp;
    }else if(head!=NULL && pos==1){
        head->prv=tmp;
        tmp->next=head;
        return tmp;
    }

    struct Node* hd=head;
    int count=1;
    while (head!=NULL){
        if(pos-1==count){
            tmp->next=head->next;
            tmp->prv=head;
            if(head->next!=NULL)
                head->next->prv=tmp;
            head->next=tmp;
            return hd;
        }
        count ++;
        head=head->next;
    }

    printf("Entered an invalid position!!\n");
    return hd;

}//InsertAt


void printList(struct Node* head){

    if(head == NULL) {
        printf("\n No elements in the List!!\n");
        return;
    }
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }

    printf("\n");
}//print List