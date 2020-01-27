#ifndef EXPRESSION_H
#define EXPRESSION_H

int iPre(char symbol);
int oPre(char symbol);
int isOperand(char c);
double operation(double a, double b, char c);
double evaluateExpression(char *exp);

#endif
