#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "queue.h"
#include "cpu.h"

void run(int numberArg, struct queue *containerP, const struct stack *zasobnik);
void executeIns(struct instruction *insP);
void vytvoreniIns(struct instruction *insP, struct queue *containerP,enum instruction_type typ);


void vytvoreniIns(struct instruction *insP, struct queue *containerP,enum instruction_type typ){
    insP = malloc(sizeof(struct instruction));
    insP->next = NULL;
    insP->type = typ;
    if ((typ == INST_ADD) || (typ == INST_SUB) || (typ == INST_MUL) || (typ == INST_DIV))
        scanf(" %d", &(insP->arg));
    queue_push(containerP, insP);
}

void executeIns(struct instruction *insP){
    if (insP->type == INST_ADD){
        mem_register += insP->arg;
    }
    if (insP->type == INST_SUB){
        mem_register -= insP->arg;
    }
    if (insP->type == INST_INC){
        mem_register++;
    }
    if (insP->type == INST_DEC){
        mem_register--;
    }
    if (insP->type == INST_MUL){
        mem_register *= insP->arg;
    }
    if (insP->type == INST_DIV){
        mem_register /= insP->arg;
    }
    return;
}

void run(int numberArg, struct queue *containerP, const struct stack *zasobnik){
    struct instruction *poppedIns;
    if (numberArg > 0){
        for (int i = 0; i < numberArg; i++){
            if (queue_empty(containerP) == 1) break;
            poppedIns = queue_pop(containerP);
            executeIns(poppedIns);
            free(poppedIns);
        }
    }
    else{
        while (queue_empty(containerP) != 1){
            poppedIns = queue_pop(containerP);
            executeIns(poppedIns);
            free(poppedIns);
        }
    }
    print(zasobnik);
    return;
}


int main(int argc, char **argv){
    (void) argc;
    int numberArg = 0;
    struct stack zasobnik;
    struct queue container;
    struct instruction *ins = NULL;
    char vstup[15];
    mem_register = 0;
    my_assert( (strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "-r") == 0) || (strcmp(argv[1], "-R") == 0) );
    if (strcmp(argv[1], "-r") == 0){
        numberArg = atoi(argv[2]);
        my_assert(numberArg > 0);
    }
    if (strcmp(argv[1], "-h") == 0){
        printf("Povolené inštrukcie (na tyto se vztahuje argument programu -r): \n add <numberArg> - pripočíta hodnotu <numberArg> k registru. \n sub <numberArg> - odpočíta hodnotu <numberArg> od registru. \n inc - pripočíta k registru 1. \n dec - odpočíta od registru 1. \n mul <numberArg> - vynásobí register hodnotou <numberArg>. \n div <numberArg> - vydelí register hodnotou <numberArg>.");
        return 0;
    }

    queue_create(&container);
    zasobnik.stack_top = 0;

    do {
        printf("> ");
        scanf(" %s", vstup);
        // Instrukce:
        if (strcmp(vstup, "add") == 0){
            vytvoreniIns(ins, &container, INST_ADD); // &ins ?
        }
        if (strcmp(vstup, "sub") == 0){
            vytvoreniIns(ins, &container, INST_SUB);
        }
        if (strcmp(vstup, "inc") == 0){
            vytvoreniIns(ins, &container, INST_INC);
        }
        if (strcmp(vstup, "dec") == 0){
            vytvoreniIns(ins, &container, INST_DEC);
        }
        if (strcmp(vstup, "mul") == 0){
            vytvoreniIns(ins, &container, INST_MUL);
        }
        if (strcmp(vstup, "div") == 0){
            vytvoreniIns(ins, &container, INST_DIV);
        }
        // Pokyny:
        if (strcmp(vstup, "run") == 0) run(numberArg, &container, &zasobnik);
        if (strcmp(vstup, "reset") == 0) queue_clear(&container);
        if (strcmp(vstup, "push") == 0) stack_push(&zasobnik);
        if (strcmp(vstup, "pop") == 0) stack_pop(&zasobnik);

    }while(strcmp(vstup, "quit") != 0);

    queue_clear(&container);

    return 0;
}
