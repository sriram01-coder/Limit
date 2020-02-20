#include <string.h>
#include <stdio.h>
#include <math.h>
#include "expression.h"
#define h 3.05902321e-7
#define INF 3269017.372
#define LOW -2147483648

double calcLimit(char *exp, double x, int low, int high, int isInf){
    if(!isInf){
        double a = (evaluateExpression(exp, x+h, low, high));
        printf("RHL = %lf\n", a);
        double b = (evaluateExpression(exp, x-h, low, high));
        printf("LHL = %lf\n", b);
        double nearest_a = roundf(a * 100000)/100000;  
        double nearest_b = roundf(b * 100000)/100000;  
        if(nearest_a == nearest_b)
            return nearest_a;
        else
            return LOW;
    }
    else{
        double a;
        if(isInf == 1)
            a = (evaluateExpression(exp, INF, low, high));
        else
            a = (evaluateExpression(exp, -INF, low, high));
            
        if(a >= INF || a <= -INF)
            return LOW;
        else
            return roundf(a * 100000)/100000;
    }
}

