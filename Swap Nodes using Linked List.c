#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef int BOOl;
#define TRUE 1
#define FALSE 0

BOOl SwapPairs(struct node**);
BOOl InsertLast(struct node **,int);
void Display(struct node*);
int count(struct node*);
int main(){
    struct node *head = NULL;
    InsertLast(&head,11);
    InsertLast(&head,21);
    InsertLast(&head,31);
    InsertLast(&head,41);
    InsertLast(&head,51);
    //printf("No. of Nodes in linked list : %d\n",count(head));
    //printf("Nodes in the Linked List are : ");
    SwapPairs(&head);
    Display(head);
    

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
int count(struct node *first){
    int i=0;
    while(first!=NULL){
        i++;
        first = first->next;
    }
    return i;
}

BOOl SwapPairs(struct node **first){
    struct node *temp = *first;
    int t = 0;

    if(*first == NULL){
        return -1;
    }
    else if(temp->next==NULL){
        printf("%d\t",temp->data);
        return temp->data;
    }
    
    else if(count(*first)%2==1){
        while(temp->next!=NULL){
            int t = temp->data;
            temp->data = temp->next->data;
            temp->next->data = t;
            temp = temp->next->next;
        }
        return TRUE;
    }
    else if(count(*first)%2==0){
        while(temp!=NULL){
            int t = temp->data;
            temp->data = temp->next->data;
            temp->next->data = t;
            temp = temp->next->next;
        }
        return TRUE;
    }
    return FALSE;
}
