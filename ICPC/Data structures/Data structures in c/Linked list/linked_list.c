#include<stdio.h>
#include<stdlib.h>
 
typedef struct student{             //Typedef makes it easy to initialize structure...
    int roll;                       //i won't have to write "struct student " only student works
    char* name;
    const int* course;
    const int* marks;
    struct student* link;
}student; 

student* create_list(int n){
    int i;
    student *p,*head;
    for(i=0;i<n;i++){
        if(i==0){
            head=(student*)malloc(sizeof(student));         //creating a head pointer pointing to starting node
            p=head;
        }
        else{
            p->link=(student*)malloc(sizeof(student));          //creating nodes and linking to previous
            p=p->link;
        }
        printf("Enter the details of student- %d:\n",i+1);
        printf("\tEnter roll no > ");
        scanf("%d",&(p->roll));                             // p is a pointer to structure so we are using -> operator to access element
        p->name=(char*)malloc(20*sizeof(char)); 
        printf("\tEnter name > ");
        scanf("%s",p->name);
        p->course=(const int*)malloc(4*sizeof(int));     //course is const int* pointer allocated array of required size
        const int* new=p->course;                           
        for(int j=0;j<4;j++){                           
            printf("\tCourse_id %d: ",j+1);
            scanf("%d",&new[j]);                        //Taking inputs for array of course
        }
        p->marks=(const int*)malloc(4*sizeof(int));      //similarly marks is an array of requeired size
        for(int j=0;j<4;j++){
            printf("\tMarks for course %d: ",j);
            scanf("%d",&(p->marks[j]));                 //taking inputs for array of marks        
        }
    }
    p->link=NULL;                       //The last node link should be NULL
    return head;                        //Return the head of the list
}

void display(student* head){                        
    student* p=head;                    //p is a pointer which would transverse...we are keeping head safe
    int length=1;
    while(p!=NULL){                         // since the last element link is NULL
        printf("\nRoll no. > %d",p->roll);
        printf("\tName: %s\n",p->name);
        const int* new=p->course;           
        const int* new1=p->marks;
        for(int i=0;i<4;i++){
            printf("\tCourse_id: %d has marks %d\n",new[i],new1[i]);       //accessing the array course and marks
        }
        p=p->link;
        length++;                                       //Length of array
    }
    printf("The length of list is %d\n",length-1);
}

student* insert_at_begin(student* head,student* new_node){      //Think how can we do this by "pass by refrence"??
    new_node->link=head;                        //link of new_node to head
    head=new_node;                              //and now head should point to new node
    return head;
}

student* insert_at_end(student* head,student* new_node){
    student* p=head;
    while(p->link!=NULL){               //transversing unitil last element whose link is NULL....THink why not "(p != NULL)"
        p=p->link;
    }
    p->link=new_node;               //the link of last element is updated to join new_node
    new_node->link=NULL;            //link of new_node is set NULL
    return head;    
}

void display_k_node(student* head,int k){
    student* p=head;
    for(int i=0;i<k-1;i++){                   //just transverse till kth node and print information
        p=p->link;
    }
    printf("\nDisplaying %d node:",k);
    printf("\nRoll no. > %d",p->roll);
    printf("\tName: %s\n",p->name);
    const int* new=p->course;
    const int* new1=p->marks;
    for(int i=0;i<4;i++){
        printf("\tCourse_id: %d has marks %d\n",new[i],new1[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the no. of students: ");
    scanf("%d",&n);
    student* head=create_list(n);
    printf("Enter the details for node at begining:\n ");
    student* node_for_begin=create_list(1);
    head=insert_at_begin(head,node_for_begin);
    printf("Enter the details for node at end:\n ");
    student* node_for_end=create_list(1);
    head=insert_at_end(head,node_for_end);
    display_k_node(head,3);                     //instead of 3 input for kth node can be taken
    display(head);
    return 0;
}