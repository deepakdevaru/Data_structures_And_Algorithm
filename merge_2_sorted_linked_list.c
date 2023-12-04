#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "limits.h"


typedef struct stack{
    int capacity;
    int topIdx;
    int *data;
}stack;

int push(stack * stack_p, int data);
int top(stack * stack_p);
int isEmpty(stack *stack_p);
int isFull(stack *stack_p);
int pop(stack *stack_p);
stack* createStack(int capacity);

stack* createstack(int capacity){
    if(capacity == 0){
        exit(EXIT_FAILURE);
    }

    stack *stack_p = (stack*)malloc(sizeof (stack));
    if(stack_p == NULL){
        exit(EXIT_FAILURE);
    }
    memset (stack_p, 0 , sizeof(stack));
    stack_p -> capacity = capacity;
    stack_p -> topIdx = -1;
    stack_p->data = (int*)calloc(capacity, sizeof(int));

    if(stack_p->data == NULL){
        exit(EXIT_FAILURE);
    }

    return stack_p;
}

int push(stack * stack_p, int data){
    if(isFull(stack_p)){
        exit(EXIT_FAILURE);
    }
    stack_p->data[++(stack_p->topIdx)] = data;

    return 1;
}

int top(stack * stack_p){
    if(isEmpty(stack_p)){
        exit(EXIT_FAILURE);
    }
    return stack_p->data[stack_p->topIdx];
}

int pop(stack *stack_p){
    if(isEmpty(stack_p)){
        exit(EXIT_FAILURE);
    }
    return stack_p->data[stack_p->topIdx--];
}
int isFull(stack *stack_p){
    if(stack_p->topIdx >= stack_p->capacity-1)return 1;
    return 0;
}
int isEmpty(stack *stack_p){
    if(stack_p->topIdx == -1)return 1;
    return 0;
}

int main(){

    stack * stack_p = createstack(10);
    push(stack_p,20);
    push(stack_p,30);
    push(stack_p,40);

    printf("top %d \n", pop(stack_p));
    printf("top %d \n", pop(stack_p));
    printf("top %d \n", pop(stack_p));
    printf("top %d \n", pop(stack_p));

    free (stack_p);

    return 1;



}



