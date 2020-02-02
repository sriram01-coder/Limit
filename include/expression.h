#ifndef EXPRESSION_H
#define EXPRESSION_H

int iPre(char symbol);
int oPre(char symbol);
int isOperand(char c);
int isFunction(char c);
double operation(double a, double b, char c);
int fact(double a);
double fun(double a, char c);
double evaluateExpression(char *exp, double x);

#endif
