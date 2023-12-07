#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "strings.h"

typedef struct linkedlist {
   int data;
   struct linkedlist * next;
}linkedlist;

void push(linkedlist **head , int data){
    if(head == NULL) return;

    linkedlist *node = (linkedlist*) malloc (sizeof(linkedlist));
    node->data = data;
    node->next = *head;
    *head = node;

    return;

}

void printlist(linkedlist *head){

    printf("printing Nodes : ");
    while(head != NULL){
      printf(" %d ->" , head->data);
      head = head->next;
    }
    printf("\n");
}

void reverse_linked_list(linkedlist **head){
   if(head == NULL)return ;

   linkedlist *traverse = *head;
   linkedlist *back = NULL;
   linkedlist *next = NULL;

   while(traverse ->next != NULL){
      next = traverse->next;
      traverse->next = back;
      back = traverse;
      traverse = next;
   }

   traverse->next = back;

   *head = traverse;
   return;
}


int main(){

    linkedlist *head = NULL;

    push(&head,5);
     push(&head,6);
      push(&head,7);
       push(&head,8);
        push(&head,9);
    
    printlist(head);

    reverse_linked_list(&head);

    printlist(head);

    free(head);

    return 0;
}