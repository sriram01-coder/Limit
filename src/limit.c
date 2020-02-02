#include <string.h>
#include <stdio.h>
#include "stack.h"
#include "expression.h"
#define h 1e-8

double firstDerivative(char *exp, double x, int low, int high){
    double a = (evaluateExpression(exp, x+h, low, high));
    double b = (evaluateExpression(exp, x, low, high));
    return (a-b)/(h);
}

double secondDerivative(char *exp, double x, int low, int high){
    double a = (evaluateExpression(exp, x+h, low, high));
    double b = (evaluateExpression(exp, x-h, low, high));
    double c = (evaluateExpression(exp, x, low, high));
    return (a-2*c+b)/(h*h);
}

double limitOfFunction(char *exp, double x){
    printf("First Derivative Test\n");
    int len = strlen(exp);
    double first = firstDerivative(exp, x, 0, len-1);
    return first;
}
