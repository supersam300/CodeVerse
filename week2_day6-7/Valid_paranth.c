#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0'; 
}


// Function to check matching brackets
int isPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int isValid(char *expr) {
    top = -1; // reset stack

    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (top == -1 || !isPair(pop(), c)) {
                return 0;  
            }
        }
    }

    return top == -1;
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    scanf("%s", expr);

    if (isValid(expr))
        printf("Valid parentheses.\n");
    else
        printf("Invalid parentheses.\n");

    return 0;
}
