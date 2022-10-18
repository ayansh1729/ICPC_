#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* link;
    int data;
};

struct node* create_list(){
    int k,n;
    struct node *p,*head;
    printf("How many elements you want to enter: ");
    scanf("%d",&n);
    for(k=0;k<n;k++){
        if(k==0){
            head = (struct node*)malloc(sizeof(struct node));
            p=head;
        }
        else{
            p->link=(struct node*)malloc(sizeof(struct node));
            p=p->link;
        }
        printf("Enter the data ");
        scanf("%d",&p->data);
    }
    p->link=NULL;
    return head;
}

void display(struct node* head){
    int count =1;
    struct node* p;
    p=head;
    while(p != NULL){
        printf("\nNode %d: %d \n",count,p->data);
        count++;
        p=p->link;
    }
}

void insert_node(struct node* head, int pos, struct node* new){
    int count=1;
    struct node* p=head;
    while(count != pos-1){
        p=p->link;
        count++;
    }
    struct node* temp=p->link;
    p->link=new;
    p->link->link=temp;
}
int main(){
   struct node* head=create_list();
//    display(head);
   struct node node1;
   node1.data=50;
   insert_node(head,3,&node1);
   display(head);
}