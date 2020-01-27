#include <stdio.h>
#include <stdlib.h>

int isInt(char c){
    if(c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int cmp(char *exp, int i, int len, char *str){
    int j = i;
    for(int k = 0; exp[j] != '\0' && k < len; j++, k++)
        if(str[k] != exp[j])
            return 0;
    if(exp[j] == '\0')
        return 0;
    else
        return 1;
}

char * toInfix(char *exp, char var){
    char * infix = (char *) malloc(sizeof(exp));
    for(int i = 0, j = 0; exp[i] != '\0';){
        if(isInt(exp[i])){ 
            infix[j] = exp[i];
            if(!isInt(exp[i+1]) && exp[i+1] != ')')
                infix[++j] = '*';
            j++;
            i++;
        }
        else{
            if(cmp(exp, i, 3, "sin")){
                infix[j] = 's';
                i += 3;
                j++;
            }
            else if(cmp(exp, i, 3, "cos")){
                infix[j] = 'c';
                i += 3;
                j++;
            }
            else if(cmp(exp, i, 3, "tan")){
                infix[j] = 't';
                i += 3;
                j++;
            }
            else if(cmp(exp, i, 6, "arcsin")){
                infix[j] = 'S';
                i += 6;
                j++;
            }
            else if(cmp(exp, i, 6, "arccos")){
                infix[j] = 'C';
                i += 6;
                j++;
            }
            else if(cmp(exp, i, 6, "arctan")){
                infix[j] = 'T';
                i += 6;
                j++;
            }
            else if(cmp(exp, i, 5, "floor")){
                infix[j] = 'F';
                i += 5;
                j++;
            }
            else if(cmp(exp, i, 4, "frac")){
                infix[j] = 'f';
                i += 4;
                j++;
            }
            else if(cmp(exp, i, 3, "log")){
                infix[j] = 'L';
                i += 3;
                j++;
            }
            else if(cmp(exp, i, 2, "ln")){
                infix[j] = 'l';
                i += 2;
                j++;
            }
            else if(cmp(exp, i, 3, "abs")){
                infix[j] = 'a';
                i += 3;
                j++;
            }
            else if(cmp(exp, i, 4, "sqrt")){
                infix[j] = 'q';
                i += 4;
                j++;
            }
            else if(cmp(exp, i, 2, "pi")){
                infix[j] = 'p';
                i += 2;
                j++;
            }
            else if(exp[i] == var){
                infix[j] = 'x';
                i++;
                j++;
            }
            else{
                infix[j] = exp[i];
                i++;
                j++;
            }
        }
    }
    return infix;
}

int main(){
    char exp[100];
    scanf("%s", exp);
    char *infix = toInfix(exp, 's');
    printf("%s\n", infix);
    free(infix);
}
