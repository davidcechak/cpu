#ifndef QUEUE_H
#define QUEUE_H

#ifndef my_assert
#include <assert.h>
#define my_assert(x) assert(x)
#endif // my_assert

enum instruction_type{INST_ADD, INST_SUB, INST_INC, INST_DEC, INST_MUL, INST_DIV};

struct instruction {
   struct instruction *next;
   enum instruction_type type;
   int arg; // V prípade, že inštrukcia argumente nemá,
   //ostáva hodnota argumentu buď neinicializovaná alebo si ju môžete ľubovoľne inicializovať.
 };

struct queue {
    struct instruction *first, *last;
 };

void queue_create (struct queue* container);
void queue_push (struct queue* container, struct instruction* item);
struct instruction* queue_pop (struct queue* container);
unsigned int queue_empty (const struct queue* container);
unsigned int queue_size (const struct queue* container);
unsigned int queue_clear (struct queue* container);

#endif // QUEUE_H

