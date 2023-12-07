
#include "stdio.h"
#include "stdlib.h"
#include"strings.h"

typedef struct {
    int *arr;
    int top1,top2;
    int capacity;
}twostacks_s;

#define NULL 0
void init2stacks(twostacks_s *stack , int size){
      if(stack == NULL || size == 0)return;

      stack->capacity = size;
      stack->arr = (int*)malloc(sizeof(int)*size);

      stack->top1 = 0;
      stack->top2 = size-1;

      return;
}

void push1(twostacks_s *stack , int data){
    if(stack->top1 >= stack->top2) return;

    stack->arr[stack->top1++] = data;
    return;
}

void push2(twostacks_s *stack, int data){
    if(stack->top1 >= stack->top2) return;

    stack->arr[stack->top2--]= data;
    return;
}

int pop1(twostacks_s *stack){
    if(stack->top1 == 0) return 0;
    int ans = stack->arr[stack->top1 -1];
    stack->top1--;
    return ans;
}
int pop2(twostacks_s *stack){
    if(stack->top2 == stack->capacity) return 0;
    int ans = stack->arr[stack->top2 +1];
    stack->top2++;
    return ans;
}

int main(){

    twostacks_s  stacks;
    init2stacks(&stacks, 10);
    push1(&stacks , 1);
    push1(&stacks , 2);
    push1(&stacks , 3);
    push1(&stacks , 4);

    push2(&stacks , 10);
    push2(&stacks , 9);
    push2(&stacks , 8);
    push2(&stacks , 7);


    printf("top1 %d \n", pop1(&stacks));
    printf("top1 %d \n", pop1(&stacks));
    printf("top1 %d \n", pop1(&stacks));
    printf("top1 %d \n", pop1(&stacks));
    printf("top1 %d \n", pop1(&stacks));
    printf("**************************\n");
    printf("top2 %d \n", pop2(&stacks));
    printf("top2 %d \n", pop2(&stacks));
    printf("top2 %d \n", pop2(&stacks));
    printf("top2 %d \n", pop2(&stacks));
    


    return 0;
}