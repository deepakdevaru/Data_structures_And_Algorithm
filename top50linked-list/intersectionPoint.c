/**
 * Write a function to get the intersection point of two Linked Lists
*/

#include"stdio.h"
#include"stdlib.h"
#include"strings.h"
#include"limits.h"


typedef struct node{
    int data;
    struct node *next;
}node;

typedef enum whichnode{
    HEAD1 = 0,
    HEAD2 = 1
}whichnode;

void push(node **head , int data){
    if(head == NULL)return; 

    node *temp = (node*)malloc(sizeof(node));
    temp -> data = data;
    temp->next = NULL;

    if(*head != NULL){
    temp->next = *head;
    }
    *head = temp;
    return;
}

void printlist(node *head){
    if(head == NULL) return;

    printf("the elements are: ");
    while(head != NULL){
        printf(" %d ->", head->data);
        head = head->next;
    }
    printf("\n");
    return;
}

void createintersection(node* head1 , node* head2 , whichnode _whichnode , int place){

    if(head1 == NULL || head2 == NULL || place < 1)return;

    int count = 0;
    switch(_whichnode){
        case HEAD1:
          while(head2 != NULL && count < place-1){
            head2 = head2->next;
            count++;
          }
          while(head1->next != NULL){
            head1 = head1->next;
          }
          head1->next = head2;
          break;
        
        case HEAD2:
          while(head1 != NULL && count < place-1){
            head1 = head1->next;
            count++;
          }
          while(head2->next != NULL){
            head2 = head2->next;
          }
          head2->next = head1;
          break; 
        
        default:
          printf("invalid ARG \n");
          break;
    }
    return;
}

node* detectintersection(node *head1 , node* head2){
    if(head1 == NULL || head2 == NULL)return NULL;

    int count1 = 0 , count2 = 0;

    node  *traverse1 = head1 , *traverse2 = head2;
    while(traverse1 != NULL){
        traverse1 = traverse1->next;
        count1++;
    }
    while(traverse2 != NULL){
        traverse2 = traverse2->next;
        count2++;
    }

    int tempcnt = 0;
    traverse2 = head2;
    traverse1 = head1;

    if(count1 < count2){
        //head 1 this is the smaller element
        /**traverse head 2 till it reaches the */
        while(tempcnt < (count2-count1) -1){
            traverse2 = traverse2->next;
            tempcnt++;
        }
    }
    else{
        while(tempcnt < (count1-count2)){
            traverse1 = traverse1->next;
            tempcnt++;
        }
    }

    while(traverse1 != NULL && traverse2 != NULL && traverse1 != traverse2){
            traverse1 = traverse1->next;
            traverse2 = traverse2->next;
    }

    if(traverse1 != NULL && traverse2!= NULL && traverse1 == traverse2){
            return traverse1;
    }

    else{
        return NULL;
    }
        
}

int main(){

    node *head1 = NULL;
    push(&head1, 10);
    push(&head1, 9);
    push(&head1 , 8);
    push(&head1, 7);
    push(&head1 , 6);
    push(&head1 , 5);
    push(&head1 , 50);
    push(&head1 , 90);

    node *head2 = NULL;
    push(&head2 , 2);
    push(&head2 , 20);


    printlist(head1);
    printlist(head2);

    createintersection(head1 , head2 , HEAD2 , 7);
    printlist(head2);

    node *intersection_node = detectintersection(head1 , head2);
    printf("intersection node %d \n", (intersection_node!= NULL)? intersection_node ->data : 0);

    free(head1);
    free(head2);

    head1 = NULL;
    head2 = NULL;

    return 0;
}

