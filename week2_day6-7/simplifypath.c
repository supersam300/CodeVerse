#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define MAX_PARTS 100

char* stack[MAX_PARTS];
int top = -1;

void push(char* dir) {
    if (top < MAX_PARTS - 1)
        stack[++top] = dir;
}

void pop() {
    if (top >= 0)
        top--;
}

void resetStack() {
    top = -1;
}

char* simplifyPath(char* path) {
    resetStack();

    char* pathCopy = strdup(path);
    char* token = strtok(pathCopy, "/");

    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            pop(); // go up
        } else if (strcmp(token, ".") != 0 && strlen(token) > 0) {
            push(token);
        }
        token = strtok(NULL, "/");
    }

    // Construct simplified path
    char* result = (char*)malloc(MAX);
    strcpy(result, "/");

    for (int i = 0; i <= top; i++) {
        strcat(result, stack[i]);
        if (i != top)
            strcat(result, "/");
    }

    free(pathCopy);
    return result;
}


int main() {
    char path[MAX];
    printf("Enter Unix-style path: ");
    scanf("%s", path);

    char* simplified = simplifyPath(path);
    printf("Simplified Path: %s\n", simplified);

    free(simplified);
    return 0;
}
