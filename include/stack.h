#ifndef STACK_H
#define STACK_H

struct Node{
    double data;
    struct Node *next;
};

void push(struct Node **head, double value);
double pop(struct Node **head);
int isEmpty(struct Node *head);
double stackTop(struct Node *head);
void freeList(struct Node *p);

#endif
