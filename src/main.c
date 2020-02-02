#include <stdio.h>
#include <stdlib.h>
#include "expression.h"

int main(){
    char infix[100], y[50];
    printf("Enter function: ");
    scanf("%s", infix);
    printf("Find the limit at: ");
    scanf("%s", y);
    double x = evaluateExpression(y, -1);
    printf("Ans = %f\n", evaluateExpression(infix, x));
}
