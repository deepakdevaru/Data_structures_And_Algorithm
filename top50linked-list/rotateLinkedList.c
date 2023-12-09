/*

Given a singly linked list, The task is to rotate the linked list counter-clockwise by k nodes.

Examples:

Input: linked list = 10->20->30->40->50->60, k = 4
Output: 50->60->10->20->30->40. 
Explanation: k is smaller than the count of nodes in a linked list so (k+1 )th node i.e. 50 becomes the head node and 60’s next points to 10

Input: linked list = 30->40->50->60, k = 2
Output: 50->60->30->40. 
*/


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


void roatateLinkledList(linkedlist **head , int k ){

    if (k == 0 || head == NULL) return; 

    linkedlist *prev = NULL , *cur = *head , *traverse = *head;
    int count = 0;

     while(traverse->next != NULL){
        while(count < k){
            prev = cur; 
            cur = cur->next;
            count++;
        }
        traverse = traverse->next;
     }

     prev->next = NULL;
     traverse->next = *head;
     *head = cur;
     return;

}

int main(){

linkedlist *head = NULL;

    push(&head,60);
     push(&head,50);
      push(&head,40);
       push(&head,30);
        push(&head,20);
        push(&head , 10);
    
    printlist(head);

    roatateLinkledList(&head, 5);

    printlist(head);

    free(head);
    return 0;
}