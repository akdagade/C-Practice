//
// Created by akshay on 17/10/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node treenode;

struct Qnode{
    treenode* data;
    struct Qnode* next;
};

typedef struct Qnode queue;

void enqueue(treenode* node);
treenode* dequeue();
int isempty();

queue* front;
queue* end;

treenode* newNode(int data);
treenode* insertNode(treenode* root, int data);
treenode* searchNode(treenode* root, int data);
treenode* maxNode(treenode* root);
treenode* minNode(treenode* root);
int bstHeight(treenode* root);
treenode* deleteNode(treenode* root, int data);

void bft(treenode* root);
void dft_preorder(treenode* root);
void dft_inorder(treenode* root);
void dft_postorder(treenode* root);


int main(){

    treenode* root=NULL;
    treenode* tmp;

    //insert node
    root = insertNode(root,10);
    root = insertNode(root,8);
    root = insertNode(root,15);
    root = insertNode(root,23);
    root = insertNode(root,12);
    root = insertNode(root,9);
    root = insertNode(root,1);
    root = insertNode(root,6);
    root = insertNode(root,20);

    //Search
    int n=13;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=25;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=15;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=12;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=14;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=6;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);
    n=56;
    printf("Status of the node %d is : %d\n", n, searchNode(root,n)==NULL?0:1);

    //maxNode
    tmp = maxNode(root);
    if(tmp!=NULL)
        printf("\nThe max node is : %d\n", tmp->data);
    else
        printf("\nThe root is null\n");

    tmp = minNode(root);
    if(tmp!=NULL)
        printf("The min node is : %d\n", tmp->data);
    else
        printf("The root is null\n");

    printf("\nThe height of the Tree is : %d\n", bstHeight(root));

    printf("\nThe breadth first traversal : \n");
    bft(root);
    printf("\nThe depth first traversal (preorder) : \n");
    dft_preorder(root);
    printf("\nThe depth first traversal (inorder) : \n");
    dft_inorder(root);
    printf("\nThe depth first traversal (postorder) : \n");
    dft_postorder(root);

    n=12;
    printf("\n\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=6;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=10;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=13;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=15;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=12;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    n=10;
    printf("\nDeleting node %d : \n",n);
    root = deleteNode(root,n);
    dft_inorder(root);
    printf("\n %d \n",root->data);

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

treenode* searchNode(treenode* root, int data){
    treenode* flag = NULL;

    if(root == NULL)
        return root;
    //printf(" %d -> ", root->data);
    if(root->data==data)
        return root;
    else if( data  < root->data )
        flag = searchNode(root->left,data);
    else
        flag = searchNode(root->right,data);

    return flag;

}


treenode* maxNode(treenode* root){

    if(root == NULL)
        return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}//maxNode

treenode* minNode(treenode* root){

    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}//minNode


int bstHeight(treenode* root){

    if(root == NULL)
        return -1;
    int a,b;
    a = bstHeight(root->left);
    b = bstHeight(root->right);
    if(a >= b)
        return a + 1;
    return b+1;

}//bstHeight

void bft(treenode* root){
    front=NULL;
    end=NULL;
    treenode* tmp;
    enqueue(root);
    //printf("%d ", isempty());
    while(isempty()==0){
        tmp = dequeue();
        if(tmp->left!=NULL) enqueue(tmp->left);
        if(tmp->right!=NULL) enqueue(tmp->right);

        printf("%d ", tmp->data);
    }

}//bft

void dft_preorder(treenode* root){
    if(root == NULL)
        return;

    printf("%d ", root->data);
    dft_preorder(root->left);
    dft_preorder(root->right);
}

void dft_inorder(treenode* root){

    if(root == NULL)
        return;

    dft_inorder(root->left);
    printf("%d ", root->data);
    dft_inorder(root->right);
}

void dft_postorder(treenode* root){

    if(root == NULL)
        return;

    dft_postorder(root->left);
    dft_postorder(root->right);
    printf("%d ", root->data);
}


void enqueue(treenode* node){
    queue* tmp = (queue*) malloc(sizeof(queue));
    tmp->data = node;
    tmp->next=NULL;
    if(isempty()==1){
        front=tmp;
        end=tmp;
        return;
    }

    end->next=tmp;
    end=tmp;

}

treenode* dequeue(){
    if (isempty()==1)
        return NULL;
    treenode* tmp;
    tmp = front->data;
    if(front==end){
        front=NULL;
        end=NULL;
        return tmp;
    }

    front= front->next;
    return tmp;
}

int isempty(){
    if(front== NULL && end==NULL)
        return 1;
    return 0;
}


treenode* deleteNode(treenode* root, int data){

    if(root == NULL)
        return root;

    treenode* tmp;
    if(data < root->data) root->left = deleteNode(root->left,data);
    else if(data > root->data) root->right = deleteNode(root->right,data);
    else if(data == root->data ){
        if(root->right == NULL && root->left == NULL){
            free(root);
            return NULL;
        }
        if(root->right == NULL && root->left != NULL){
            tmp=root->left;
            free(root);
            return tmp;
        }
        if(root->right != NULL && root->left == NULL){
            tmp=root->right;
            free(root);
            return tmp;
        }

        if(root->right != NULL && root->left != NULL){
            tmp = minNode(root->right);
            root->data=tmp->data;
            root->right = deleteNode(root->right,root->data);
            return root;
        }

    }
    return root;
}