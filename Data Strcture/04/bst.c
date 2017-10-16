//
// Created by akshay on 17/10/17.
//

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node treenode;

treenode* newNode(int data);
treenode* insertNode(treenode* root, int data);
int searchNode(treenode* root, int data);

int main(){

    treenode* root=NULL;

    root = insertNode(root,10);
    root = insertNode(root,8);
    root = insertNode(root,15);
    root = insertNode(root,12);
    root = insertNode(root,9);
    root = insertNode(root,6);
    root = insertNode(root,20);

    int n=13;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=25;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=15;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=12;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=14;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=6;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));
    n=56;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n));

    return 0;
}//main

treenode* newNode(int data){
    treenode *tmp = (treenode*) malloc(sizeof(treenode));
    tmp->data=data;
    tmp->left=tmp->right=NULL;
    return tmp;
}

treenode* insertNode(treenode* root, int data){
    if(root==NULL){
        return newNode(data);
    } else if( data <= root->data ){
         root->left = insertNode(root->left,data);
    } else{
        root->right = insertNode(root->right,data);
    }
    return root;
}

int searchNode(treenode* root, int data){
    int flag = 0;

    if(root == NULL)
        return 0;
    printf(" %d -> ", root->data);
    if(root->data==data)
        return 1;
    else if( data  < root->data )
        flag = searchNode(root->left,data);
    else
        flag = searchNode(root->right,data);

    return flag;

}