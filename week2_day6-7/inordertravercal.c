#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Stack structur
struct Stack {
    struct Node* arr[MAX];
    int top;
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, struct Node* node) {
    if (s->top < MAX - 1)
        s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    if (!isEmpty(s))
        return s->arr[s->top--];
    return NULL;
}

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

//  inorder traversal
void inorderTraversal(struct Node* root) {
    struct Stack stack;
    initStack(&stack);

    struct Node* current = root;

    while (current != NULL || !isEmpty(&stack)) {
        while (current != NULL) {
            push(&stack, current);
            current = current->left;
        }
        current = pop(&stack);
        printf("%d ", current->data);

        current = current->right;
    }
}

// Driver code
int main() {

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Inorder Traversal: ");
    inorderTraversal(root);

    return 0;
}
