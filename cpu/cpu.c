#include <stdio.h>
#include <string.h>
#include "cpu.h"

void stack_push (struct stack* stack){
    if (stack == NULL){
        fprintf(stderr, "hodnota argumentu stack je NULL\n");
        return;
    }
    if (stack->stack_top == 20){
        fprintf(stderr, "stack plny\n");
        return;
    }
    stack->stack_values[stack->stack_top] = mem_register;
    stack->stack_top ++;
}
void stack_pop (struct stack* stack){
    if (stack == NULL){
        fprintf(stderr, "hodnota argumentu stack je NULL\n");
        return;
    }
    if (stack->stack_top == 0){
        fprintf(stderr, "stack prazdny\n");
        return;
    }
    stack->stack_values[stack->stack_top] = 0;
    stack->stack_top --;
}
void print (const struct stack* stack){
    if (stack == NULL){
        fprintf(stderr, "hodnota argumentu stack je NULL\n");
        return;
    }
    printf("# Register %d | Stack ", mem_register);
    for(unsigned int i = 0; i < stack->stack_top; i ++){
        printf("%d ", stack->stack_values[i]);
    }
    printf("\n");
}
