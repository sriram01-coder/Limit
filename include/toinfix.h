#ifndef TOINFIX_H
#define TOINFIX_H

int isInt(char c);
int isOperator(char c);
int cmp(char *exp, int i, int len, char *str);
char * toInfix(char *exp, char var);

#endif
