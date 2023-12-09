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

void reverse(linkedlist **Node){
    
    linkedlist *cur = *Node;
    linkedlist *prev = NULL;
    linkedlist *next = (*Node)->next;

    while(next != NULL){
        cur->next = prev;
        prev = cur;
        cur = next;
        next = next->next;
    }
    cur ->next = prev;
    *Node = cur;
    return;
}

int isPalindrome(linkedlist *head){
    if(head == NULL) return 0;

    linkedlist * reversed = NULL;

    linkedlist *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    reversed = slow ->next;

    reverse(&reversed);

    fast = head;
    while(fast != NULL && reversed != NULL){
        if(fast -> data != reversed->data) return 0;
        fast = fast->next;
        reversed = reversed->next;
    }

    return 1;

}

int main(){

    linkedlist *head = NULL;

    push(&head , 10);
    push(&head, 9);
    push(&head, 8);
    push(&head,8);
    push(&head, 9);
    push(&head, 10);

    printlist(head);

    printf("is palindrome %d", isPalindrome(head));

    free(head);
    return 0;

}