#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* create_node(int data){
    node* newNode=(node*)malloc(sizeof(node));
    if(!newNode){
        printf("Memory Error!!\n");
        return NULL;
    }
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}

node* Insert_node(node* root,int data){
    if(root==NULL){
        root=create_node(data);
        return root;
    }

}
 
int main(){

    return 0;
}