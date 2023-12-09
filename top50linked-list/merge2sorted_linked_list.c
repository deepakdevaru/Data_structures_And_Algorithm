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

void move(linkedlist **dst , linkedlist**src){

    linkedlist *temp = *src;
    *src = (*src)->next;

    (*dst)->next = temp;
    (*dst) = (*dst)->next;
    return;
}

linkedlist*  mergeSortedLinkedList(linkedlist *head1 , linkedlist* head2){
    if (head1 == NULL && head2 == NULL) return NULL;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    linkedlist dummy;
    linkedlist *tail = &dummy;

    while(1){
        if(head1 == NULL){
            tail->next = head2;
            break;
        }
        else if(head2 == NULL){
            tail->next = head1;
            break;
        }

        if(head1 -> data <= head2->data){
          move(&(tail), &head1);
        }

        else if(head1 -> data > head2->data){
            move(&tail , &head2);
        }
    }

    return (dummy.next);
    
}

int main (){
    linkedlist *head1 = NULL;

    push(&head1,9);
     push(&head1,7);
      push(&head1,5);
       push(&head1,3);
        push(&head1,1);
    
    printlist(head1);

    linkedlist *head2 = NULL;

    push(&head2,10);
     push(&head2,8);
      push(&head2,6);
       push(&head2,4);
        push(&head2,2);
    
    printlist(head2);

    linkedlist *merged = mergeSortedLinkedList(head1, head2);
    printlist(merged);

    free(merged);
    merged = NULL;
    head1= NULL;
    head2= NULL;
    return 0;
}  