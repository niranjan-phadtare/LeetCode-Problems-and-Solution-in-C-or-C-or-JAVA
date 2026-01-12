#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef int BOOl;
#define TRUE 1
#define FALSE 0

BOOl Reverse(struct node**);
BOOl SwapPairs(struct node**);
BOOl InsertLast(struct node **,int);
void Display(struct node*);
void Rd(struct node*);
int count(struct node*);

int main(){
  
    struct node *head = NULL;
  
    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,31);
    InsertLast(&head,41);
    InsertLast(&head,51);
    
    printf("\n");
    
    Display(head);
    printf("\n\n");
    
    Reverse(&head);
    
    

    return 0;
}
BOOl InsertLast(struct node**first,int value){
    struct node *newnode = NULL;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    if(*first == NULL){
        *first = newnode;
    }
    else{
        struct node *temperory = *first;
        while(temperory->next!=NULL){
            temperory = temperory->next;
        }
        temperory->next = newnode;
    }
    return TRUE;
}
void Display(struct node *first){
    while(first !=NULL){
        printf("%d\t",first->data);
        first = first->next;
    }
}


BOOl Reverse(struct node **first){
    struct node *temp = *first;
    struct node *temp2 = NULL;
    struct node *tail = NULL;

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp2 = temp;
    tail = temp->next;
    temp = temp->next;
    while(temp2 != *first){
        temp->next = temp2;
        struct node *demo = *first;
        while(demo->next != temp2){
            demo = demo->next;
        }
        temp2->next = demo;
        temp2 = demo;
        temp = demo->next;
    }
    temp2->next = NULL;
    Rd(tail);
    return TRUE;
}

void Rd(struct node *last){
   
    while((last)->next!=NULL){
        printf("%d\t",(last)->data);
        (last) = (last)->next;
    }
    printf("%d",(last)->data);
}
