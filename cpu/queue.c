#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "queue.h"

void queue_create (struct queue* container){
    my_assert(container != NULL);
    container->first = NULL;
    container->last = NULL;
}

void queue_push (struct queue* container, struct instruction* item)
{
    my_assert(container != NULL);
    if (item == NULL){
        fprintf(stderr, "hodnota argumentu item je NULL\n");
        return;
    }
    if (container->last == NULL){
        container->first = item;
        container->last = item;
    }
    else {
        container->last->next = item;
        container->last = item;
    }
    item->next = NULL;
}

struct instruction* queue_pop (struct queue* container){
    struct instruction *popedInstruction;

    my_assert(container != NULL);
    if (container->last == NULL){
        fprintf(stderr, "pop z prazdne fronty\n");
        return NULL;
    }
    popedInstruction = container->first;
    if (container->first == container->last){
        container->first = NULL;
        container->last = NULL;
    }
    else container->first = container->first->next;
    return popedInstruction;
}

unsigned int queue_empty (const struct queue* container){
    my_assert(container != NULL);
    if (container->first == NULL)
        return 1;
    else return 0;
}

unsigned int queue_size (const struct queue* container){
    my_assert(container != NULL);
    struct instruction *dalsiIns = container->first;
    int pocet = 0;

    while (dalsiIns != NULL)
    {
        dalsiIns = dalsiIns->next;
        pocet += 1;
    }
    return pocet;
}

unsigned int queue_clear (struct queue* container){
    my_assert(container != NULL);
    struct instruction *dalsiIns = container->first;
    int pocet = 0;

    while (container->first != NULL){
        container->first = container->first->next;
        free(dalsiIns);
        dalsiIns = container->first;
        pocet++;
    }

    container->first = NULL;
    container->last = NULL;
    return pocet;
}
