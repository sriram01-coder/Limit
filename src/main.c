#include <stdio.h>
#include <stdlib.h>
#include "expression.h"

int main(){
    char infix[100];
    printf("Enter function: ");
    scanf("%s", infix);
    double x;
    printf("Find the limit at: ");
    scanf("%lf", &x);
    printf("Ans = %f\n", evaluateExpression(infix, x));
}
