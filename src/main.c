#include <stdio.h>
#include <stdlib.h>
#include "expression.h"

int main(){
    char infix[100];
    printf("Enter expression: ");
    scanf("%s", infix);
    printf("Ans = %f\n", evaluateExpression(infix));
}
