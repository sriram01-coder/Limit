#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expression.h"
#include "toinfix.h"
#include "limit.h"

int main(){
    char function[100], val[50], var[2];
    printf("Enter function: ");
    scanf("%s", function);
    printf("Find the limit at: ");
    scanf("%s", val);
    printf("Variable: ");
    scanf("%s", var);

    char * infixFunction = toInfix(function, var[0]);
    char * infixVal = toInfix(val, '`');
    
    double x = evaluateExpression(infixVal, -1, 0, strlen(infixVal)-1);
    printf("Ans = %f\n", limitOfFunction(infixFunction, x));

    free(infixFunction);
    free(infixVal);
}
