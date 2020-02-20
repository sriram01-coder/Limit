#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expression.h"
#include "toinfix.h"
#include "limit.h"
#define LOW -2147483648

int main(){
    char infix[100], val[50], var[2];
    printf("Enter function: ");
    scanf("%s", infix);
    printf("Find the limit at: ");
    scanf("%s", val);
    printf("Variable: ");
    scanf("%s", var);

    char * infixFunction = toInfix(infix, var[0]);

    int isInf = 0;
    if(strcmp("infinity", val) == 0)
        isInf = 1;
    else if(strcmp("-infinity", val) == 0)
        isInf = 2;

    if(!isInf){
        char * infixVal = toInfix(val, '#');
        double x = evaluateExpression(infixVal, -1, 0, strlen(infixVal)-1);
        double limit = calcLimit(infixFunction, x, 0, strlen(infixFunction)-1, 0);
        if(limit != LOW)
            printf("Limit = %lf\n", limit);
        else
            printf("Limit does not exist\n");

        free(infixVal);
    }
    else{
        double limit;
        if(isInf == 1)
            limit = calcLimit(infixFunction, -1, 0, strlen(infixFunction)-1, 1);
        else
            limit = calcLimit(infixFunction, -1, 0, strlen(infixFunction)-1, 2);

        if(limit != LOW)
            printf("Limit = %lf\n", limit);
        else
            printf("Limit does not exist\n");
    }
    free(infixFunction);
}
