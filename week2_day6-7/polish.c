#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int isOperator(char *token) {
    return strcmp(token, "+") == 0 ||
           strcmp(token, "-") == 0 ||
           strcmp(token, "*") == 0 ||
           strcmp(token, "/") == 0;
}

int evalRPN(char **tokens, int tokensSize) {
    int stack[MAX];
    int top = -1;

    for (int i = 0; i < tokensSize; i++) {
        char *token = tokens[i];

        if (isOperator(token)) {
            int b = stack[top--];
            int a = stack[top--];
            int result;

            if (strcmp(token, "+") == 0) result = a + b;
            else if (strcmp(token, "-") == 0) result = a - b;
            else if (strcmp(token, "*") == 0) result = a * b;
            else result = a / b;

            stack[++top] = result;
        } else {
            stack[++top] = atoi(token);
        }
    }

    return stack[top];
}

int main() {
    char *tokens[] = {"2", "1", "+", "3", "*"}; // ((2 + 1) * 3) = 9
    int size = sizeof(tokens) / sizeof(tokens[0]);

    int result = evalRPN(tokens, size);
    printf("Result: %d\n", result);

    return 0;
}
