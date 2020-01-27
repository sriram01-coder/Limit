#include <stdlib.h>
#include <math.h>
#include "stack.h"

int iPre(char symbol){
    if(symbol == '+' || symbol == '-')
        return 2;
    else if(symbol == '*' || symbol == '/')
       return 4; 
    else if(symbol == '^')
        return 5;
    else if(symbol == '(')
        return 0;
    else
        //head is NULL
        return -1;
}

int oPre(char symbol){
    if(symbol == '+' || symbol == '-')
        return 1;
    else if(symbol == '*' || symbol == '/')
       return 3; 
    else if(symbol == '^')
        return 6;
    else if(symbol == '(')
        return 7;
    else
        //symbol == '('
        return 0;
}

int isOperand(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
        return 0;
    else
        return 1;
}

double operation(double a, double b, char c){
    if(c == '+')
        return a+b;
    else if(c == '-')
        return a-b;
    else if(c == '*')
        return a*b;
    else if(c == '/')
        return a/b;
    else
        return pow(a, b);
}

double evaluateExpression(char *exp){
    struct Node *operand = NULL, *operator = NULL;
    for(int i = 0; exp[i] != '\0'; ){
        if(isOperand(exp[i])){
            int sum = 0;
            while(exp[i] != '\0' && isOperand(exp[i])){
                sum = sum*10 + exp[i] - '0';
                i++;
            }
            push(&operand, sum);
        }
        else{
            if(oPre(exp[i]) < iPre(stackTop(operator))){
                while(oPre(exp[i]) < iPre(stackTop(operator))){
                    double b = pop(&operand);
                    double a = pop(&operand);
                    double c = operation(a, b, pop(&operator));
                    push(&operand, c);
                }
            }
            else if(oPre(exp[i]) == iPre(stackTop(operator))){
                pop(&operator);
                i++;
            }
            else{
                push(&operator, exp[i]);
                i++;
            }
        }
    }
    while(!isEmpty(operator)){
        double b = pop(&operand);
        double a = pop(&operand);
        double c = operation(a, b, pop(&operator));
        push(&operand, c);
    }
    double x = stackTop(operand);
    freeList(operand);
    freeList(operator);
    return x;
}

