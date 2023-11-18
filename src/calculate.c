#include "calculate.h"

double calculate(char *expression){
  double stack[512];
  int top = 0;
  char *postfix = malloc(sizeof(char) * (strlen(expression) * 1.5)), *p = postfix;

  for (char *s = expression; *s; s++){
    if (isdigit(*s) || *s == '.'){
      while (isdigit(*s) || *s == '.') *p++ = *s++;
      *p++ = ' ';
    }
    if (*s == '+' || *s == '-' || *s == '*' || *s == '/'){
      if (top && (stack[top-1] == '*' || stack[top-1] == '/')){
        *p++ = stack[--top];
        *p++ = ' ';
      }
      stack[top++] = *s;
    }

    if (*s == '('){
      stack[top++] = *s;
    }

    if (*s == ')'){
      while (top && stack[top-1] != '('){
        *p++ = stack[--top];
        *p++ = ' ';
      }
      top--;
    }
  }

  while (top){
    *p++ = stack[--top];
    *p++ = ' ';
  }

  for (char *s = postfix; *s; s++){
    if (isdigit(*s) || *s == '.'){
      double value = 0, factor = 1;
      while (isdigit(*s)){
        value = 10 * value + *s++ - '0';
      }
      if (*s == '.'){
        s++;
        while(isdigit(*s)){
          factor /= 10;
          value += (*s++ - '0') * factor;
        }
      }
      stack[top++] = value;
    }

    if (*s == '+' || *s == '-' || *s == '*' || *s == '/'){
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
