#include <stdio.h>

int lcs(int arr[], int n) {
    int longest = 1;  // Minimum streak is 1 
    int current = 1;

    for (int i = 1; i < n; i++) {
        // Check if the current element is consecutive ( if prev=1,current=2 then increment current streak by 1)to the previous element
        if (arr[i] == arr[i - 1] + 1) {
            current++;  // Increase the streak
        }
        // If the current element is not the same as the previous one and not consecutive
        else if (arr[i] != arr[i - 1]) {
            // Compare and update the longest streak
            if (current > longest) {
                longest = current;
            }
            current = 1;  // Reset the streak to 1 and start a new sequence with the current element
        }
        // If the current element is the same as the previous one (its a duplicate) then do nothing
        else {
            continue;
        }
    }

    // Final check after the loop to ensure the longest streak is returned
    if (current > longest) {
        longest = current;
    }

    return longest;
}

int main() {
    // Assume the array is already sorted
    int arr[] = {1, 2, 3, 4, 5, 10, 11, 12, 20};
    int n = 9;

    int result = lcs(arr, n);

    printf("Longest Consecutive Sequence Length: %d\n", result);

    return 0;
}
