#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "stack.h"
#define INF 3269017.372

int iPre(char symbol){
    switch(symbol){
        case 's': 
        case 'c':
        case 't':
        case 'S': 
        case 'C':
        case 'T':
        case 'a': 
        case 'q':
        case 'f':
        case 'F':
        case 'l':
        case 'L': return 9;
        case '+':
        case '-': return 2;
        case '*': return 4;
        case '/': return 5;
        case '^': return 7;
        case '!': return 12;
        case '(': return 0;
        default:  // head is null 
                  return -1;
    }
}

int oPre(char symbol){
    switch(symbol){
        case 's': 
        case 'c':
        case 't':
        case 'S': 
        case 'C':
        case 'T':
        case 'a': 
        case 'q':
        case 'f':
        case 'F':
        case 'l':
        case 'L': return 10;
        case '+':
        case '-': return 1;
        case '*': return 3;
        case '/': return 6;
        case '^': return 8;
        case '!': return 11;
        case '(': return 13;
        default:  // symbol is ')'
                  return 0;
    }

}

int isOperand(char c){
    if((c >= '0' && c <= '9') || c == 'p' || c == 'e' || c == 'x' || c == '.')
        return 1;
    else
        return 0;
}

int isUnary(char c){
    switch(c){
        case '+':
        case '*':
        case '/':
        case '(':
        case '^': return 1;
        default: return 0;
    }
}

int isFunction(char c){
    switch(c){
        case 's': //sin 
        case 'c': //cos
        case 't': //tan
        case 'S': //arcsin
        case 'C': //arccos
        case 'T': //arctan
        case 'a': //abs 
        case 'q': //sqrt
        case 'f': //fractional_part
        case 'F': //floor
        case '!': //factorial
        case 'l': //ln
        case 'L': //log
                 return 1;
        default: return 0;
    }
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

int fact(double a){
    if(a == floor(a) && a >= 0){
        int product = 1;
        while(a > 1)
            product *= a--;
        return product;
    }
    else
        return -1;
}

double fun(double a, char c){
    switch(c){
        case 's': return sin(a);
        case 'c': return cos(a);
        case 't': return tan(a);
        case 'S': return asin(a);
        case 'C': return acos(a);
        case 'T': return atan(a);
        case 'a': return fabs(a);
        case 'q': return sqrt(a);
        case 'f': return a - floor(a);
        case 'F': return floor(a);
        case '!': return fact(a);
        case 'l': return log(a);
        case 'L': return log10(a);
        default: return -1;
    }
}

/*void printStack(struct Node *p){
    while(p != NULL){
        printf("%f ", p->data);
        p = p->next;
    }
    printf("\n");
}*/

double evaluateExpression(char *exp, double x, int low, int high){
    //printf("exp = %s\nx = %.6f\nlow = %d and high = %d\n", exp, x, low, high);
    struct Node *operand = NULL, *operator = NULL;
    int isNegative = 0, isDecimal = 0;
    for(int i = low; i <= high; ){
        if(isOperand(exp[i])){
            double sum = 0;
            if(exp[i] == 'p'){
                sum = M_PI;
                i++;
            }
            else if(exp[i] == 'e'){
                sum = M_E;
                i++;
            }
            else if(exp[i] == 'x'){
                sum = x;
                i++;
            }
            else{
                int j = 0;
                while(i <= high && isOperand(exp[i])){
                    if(exp[i] == '.'){
                        isDecimal = 1;
                        j = 1;
                    }
                    else if(isDecimal == 1){
                        sum = sum + pow(10, -j)*(exp[i] - '0');
                        j++;
                    }
                    else
                        sum = sum*10 + exp[i] - '0';
                    i++;
                }
            }
            if(isNegative == 1){
                sum = -sum;
                isNegative = 0;
            }
            push(&operand, sum);
        }
        else{
            if(exp[i] == '-' && (i == 0 || isUnary(exp[i-1]))){
                isNegative = 1;
                i++;
            }
            else{
                if(isNegative == 1 && isFunction(exp[i]))
                    isNegative = 2;
                if(oPre(exp[i]) < iPre(stackTop(operator))){
                    while(oPre(exp[i]) < iPre(stackTop(operator))){
                        if(isFunction(stackTop(operator))){
                            double a = pop(&operand);
                            double b = fun(a, pop(&operator));
                            if(isNegative == 2){
                                push(&operand, -b);
                                isNegative = 0;
                            }
                            else
                                push(&operand, b);
                        }
                        else{
                            double b = pop(&operand);
                            double a = pop(&operand);
                            if(stackTop(operator) == '^'){
                                if(b >= INF)
                                    b = 17;
                                else if(b <= -INF)
                                    b = -17;
                            }
                            double c = operation(a, b, pop(&operator));
                            push(&operand, c);
                        }
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
        /*printf("------------------------\n");
        printf("Printing operator stack\n");
        printStack(operator);
        printf("Printing operand stack\n");
        printStack(operand);
        printf("------------------------\n");*/
    }
    while(!isEmpty(operator)){
        if(isFunction(stackTop(operator))){
            double a = pop(&operand);
            double b = fun(a, pop(&operator));
            if(isNegative == 2){
                push(&operand, -b);
                isNegative = 0;
            }
            else
                push(&operand, b);
        }
        else{
            double b = pop(&operand);
            double a = pop(&operand);
            double c = operation(a, b, pop(&operator));
            push(&operand, c);
        }
    }
    double y = stackTop(operand);
    freeList(operand);
    freeList(operator);
    return y;
}
