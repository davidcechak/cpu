#ifndef CPU_H
#define CPU_H

struct stack{
    unsigned int stack_top;
    int stack_values[20];
};

int mem_register; //jeho počiatočná hodnota je 0

void stack_push (struct stack* stack);
void stack_pop (struct stack* stack) ;
void print (const struct stack* stack);

#endif // CPU_H

