#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "strings.h"

typedef struct linkedlist {
   int data;
   struct linkedlist * next;
   struct linkedlist *prev;
}linkedlist;

typedef enum drirection {
    FRONT = 0,
    BACK = 1
}direction;

void push(linkedlist **head, linkedlist **tail,int data);
void printlist(linkedlist *head, linkedlist *tail, direction dir);
void reverselist(linkedlist **head, linkedlist **tail);


void push(linkedlist **head, linkedlist **tail , int data){
    if(head == NULL || tail == NULL) return;

    linkedlist *node = (linkedlist*)malloc(sizeof(linkedlist));
    node ->data = data;
    node->next = *head;
    node->prev = NULL;

    if(*head != NULL){
      (*head)->prev = node;
    }
    *head = node;

    if(*tail == NULL){
        *tail = node;
    }

    return;
}

void printlist(linkedlist *head , linkedlist *tail, direction dir){

    if(head == NULL || tail == NULL) return;

    switch(dir){
       case FRONT:
        printf(" Reading in front direction : ");
         while(head != NULL){
            printf(" %d ->", head->data);
            head = head->next;
         }
         printf("\n");
         break;
        case BACK:
          printf(" Reading in back direction : ");
         while(tail != NULL){
            printf(" %d ->", tail->data);
            tail = tail->prev;
         }
         printf("\n");
         break;

         default:
            printf("invalid ARG \n");
            break;

    }
    return;
    
}

void reverselist(linkedlist **head, linkedlist ** tail){

    if(head == NULL || tail == NULL) return;
    if(*head == NULL || *tail == NULL)return;

    *tail = *head;
    linkedlist *cur = *head;
    linkedlist *prev = NULL;
    linkedlist *next = (*head)->next;

    while(next != NULL){
        cur -> prev = next;
        cur ->next = prev;
        if(prev != NULL)
        prev->prev = cur;

        prev = cur;
        cur = next;
        next = next->next;
    }

    cur -> prev = next;
    cur ->next = prev;
    prev->prev = cur;
 
    *tail = *head;
    *head = cur;

    return; 

}


int main(){

   linkedlist *head = NULL , *tail = NULL;

   push(&head, &tail , 5);
   push(&head, &tail , 6);
   push(&head, &tail , 7);
   push(&head, &tail , 8);
   push(&head, &tail , 9);
   push(&head, &tail , 10);
   push(&head, &tail , 11);
   push(&head, &tail , 12);

   printlist(head, tail , FRONT);
   printlist(head, tail , BACK);

   reverselist(&head, &tail);

   printlist(head, tail , FRONT);
   printlist(head, tail , BACK);

   free(head);
   head = NULL;
   tail = NULL;

    return 0;
}