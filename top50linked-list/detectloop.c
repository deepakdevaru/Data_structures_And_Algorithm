
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

void makeloop(linkedlist *head , int k){
    if(head == NULL)return;
    
    int count = 0;
    linkedlist *traverse = head;

    while(traverse ->next != NULL){
        traverse = traverse->next;
    }

    while(count < k-1){
        head = head->next;
        count++;
    }

    traverse->next = head;

    return;
}

int detectloop(linkedlist *head, linkedlist **node){
    if(head == NULL) return 0;
    if(head -> next == NULL)return 0;

    linkedlist *slow = head->next , *fast = head->next->next;

    while(fast!= NULL && fast->next != NULL){
        if(slow == fast){
            if(node != NULL){
            *node = slow;
            }
            return 1;
        }
        slow = slow -> next;
        fast = fast->next->next;
    }
 

    if(node != NULL){
    *node = NULL;
    }
    return 0;
}

int returnLoopnode(linkedlist *head, linkedlist **node){
    if(head == NULL)return 0;
    if(head->next == NULL)return 0;

    if(detectloop(head, node) == 1){
        linkedlist *slow = head;
        linkedlist *fast = *node;

        while(slow != fast){
            slow = slow->next;
            fast = fast ->next;
        }
        if(node != NULL){
        *node = slow;
        }
        return 1;
    }

    if(node != NULL){
    *node = NULL;
    }
    return 0;
}

void removeloop(linkedlist* node){
    linkedlist *temp = node;
    while(temp->next != node){
        temp = temp->next;
    }
    temp->next = NULL;
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

int main(){

linkedlist *head = NULL;
linkedlist *node = NULL;

    push(&head,60);
     push(&head,50);
      push(&head,40);
       push(&head,30);
        push(&head,20);
        push(&head , 10);

    printlist(head);
 
    makeloop(head, 4);


    printf("loop detected : %d \n", detectloop(head,NULL));

    int found = returnLoopnode(head, &node);
    printf("returned loop node : %d \n ", ((node != NULL)? (node)->data : 0));

    removeloop(node);
    printlist(head);

    free(head);

    return 0;
}