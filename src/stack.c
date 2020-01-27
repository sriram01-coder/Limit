#include <stdlib.h>
#include "stack.h"


void push(struct Node **head, double value){
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

double pop(struct Node **head){
    double c = (*head)->data;
    struct Node *temp = (*head);
    (*head) = (*head)->next;
    free(temp);
    return c;
}

int isEmpty(struct Node *head){
    if(head == NULL)
        return 1;
    else
        return 0;
}

double stackTop(struct Node *head){
    if(head != NULL)
        return head->data;
    else
        return 0;
}

void freeList(struct Node *p){
    while(p != NULL){
        struct Node *temp = p;
        p = p->next;
        free(temp);
    }
}
