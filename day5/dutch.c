#include <stdio.h>

// Function to swap two elements in the array
void swap(int arr[], int pos1, int pos2)
{
    int temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

// Function to sort the array of 0, 1 and 2
void sortColors(int* nums, int numsSize) {
    int start = 0;             // index where next 0 should go
    int mid = 0;               // current index being checked
    int end = numsSize - 1;    // index where next 2 should go

    while (mid <= end) {       // keep going while mid has not passed end
        switch (nums[mid]) {
            case 0:
                // Swap current 0 with the value at start and move both pointers forward
                swap(nums, start, mid);
                mid++;
                start++;
                break;
            
            case 1:
                // If it's a 1 it's already in the correct position just move mid forward
                mid++;
                break;

            case 2:
                // Swap current 2 with the value at end and move end pointer backward
                // Don't move mid because the swapped value needs to be checked
                swap(nums, mid, end);
                end--;
                break;
        }
    }
}

// Function to print the array
void printArray(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int size = 6;

    printf("Before sorting: ");
    printArray(nums, size);

    sortColors(nums, size);

    printf("After sorting: ");
    printArray(nums, size);

    return 0;
}
