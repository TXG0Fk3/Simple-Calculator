#include "calculate.h"

double calculate(char *expression){
    long double stack[512];
    int top = 0;
    char *postfix = malloc(sizeof(char) * strlen(expression)), *p = postfix;

    for (char *s = expression; *s; s++){
        if (isdigit(*s)) {
            while (isdigit(*s)) *p++ = *s++;
            *p++ = ' ';
        }

        if (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
            while (top && (stack[top-1] == '*' || stack[top-1] == '/')){
                *p++ = stack[--top];
                *p++ = ' ';
            }
            stack[top++] = *s;
        }
    }

    while(top){
      *p++ = stack[--top];
      *p++ = ' ';
    }

    *p = 0;

    for (char *s = postfix; *s; s++) {
        if (isdigit(*s)) {
            double value = 0;
            while (isdigit(*s)) value = 10 * value + *s++ - '0';
            stack[top++] = value;
        }

        if (*s == '+' || *s == '-' || *s == '*' || *s == '/') {
            double b = stack[--top], a = stack[--top];
            if (*s == '+') stack[top++] = a + b;
            if (*s == '-') stack[top++] = a - b;
            if (*s == '*') stack[top++] = a * b;
            if (*s == '/') stack[top++] = a / b;
        }
    }

    free(postfix);
    return stack[0];
}
