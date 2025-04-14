#include <stdio.h>
#include <stdlib.h>

// Definition of a singly-linked list node
struct Node {
    int val;              // Value stored in the node
    struct Node* next;    // Pointer to the next node
};

// Merges two sorted linked lists into one sorted list
struct Node* mergeTwoLists(struct Node* l1, struct Node* l2) {
    // If either list is empty, return the other
    if (!l1) return l2;
    if (!l2) return l1;

    // Compare values and recursively merge the rest
    if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

// Merges an array of k sorted linked lists using divide and conquer
struct Node* mergeKLists(struct Node** lists, int listsSize) {
    // If no lists, return NULL
    if (listsSize == 0) return NULL;

    // Keep merging pairs of lists until one remains
    while (listsSize > 1) {
        int i = 0;
        for (; i < listsSize / 2; i++) {
            // Merge the i th and (listsSize - 1 - i)th list
            lists[i] = mergeTwoLists(lists[i], lists[listsSize - 1 - i]);
        }
        // Update size to reflect reduced number of lists
        listsSize = (listsSize + 1) / 2;
    }
    // Return the final merged list
    return lists[0];
}

// Creates a linked list from an array of integers
struct Node* createList(int* arr, int size) {
    if (size == 0) return NULL;

    // Create the head node
    struct Node* head = malloc(sizeof(struct Node));
    head->val = arr[0];
    head->next = NULL;
    struct Node* current = head;

    // Append remaining elements
    for (int i = 1; i < size; i++) {
        current->next = malloc(sizeof(struct Node));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }

    return head;
}

// Prints the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->val);  // Print current node's value
        head = head->next;         // Move to next node
    }
    printf("\n");
}

// Frees memory used by a linked list
void freeList(struct Node* head) {
    while (head) {
        struct Node* temp = head;   // Store current node
        head = head->next;          // Move to next node
        free(temp);                 // Free current node
    }
}


int main() {
  
    int arr1[] = {1, 4, 5};
    int arr2[] = {1, 3, 4};
    int arr3[] = {2, 6};


    struct Node* lists[3];
    lists[0] = createList(arr1, 3);
    lists[1] = createList(arr2, 3);
    lists[2] = createList(arr3, 2);

    printf("Input lists:\n");
    for (int i = 0; i < 3; i++) {
        printList(lists[i]);
    }

    struct Node* result = mergeKLists(lists, 3);
    printf("\nMerged list:\n");
    printList(result);
    freeList(result);
    return 0;
}
