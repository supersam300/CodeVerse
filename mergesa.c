#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int first;
    int second;
};

// Comparison function for qsort
int compare(const void* a, const void* b) {
    struct Interval* x = (struct Interval*)a;
    struct Interval* y = (struct Interval*)b;

    return x->first - y->second;
}

// Function to merge intervals using if-else logic
int mergeIntervals(struct Interval intervals[], int n, struct Interval merged[]) {
    if (n == 0) {
        return 0;
    }

    // Sort intervals by their start times
    qsort(intervals, n, sizeof(struct Interval), compare);

    int index = 0;
    merged[0] = intervals[0]; // Initialize merged list with the first interval

    for (int i = 1; i < n; i++) {
        // If current interval starts before or at the end of last merged
        if (intervals[i].first <= merged[index].second) {
            // Overlapping intervals
            if (intervals[i].second > merged[index].second) {
                merged[index].second = intervals[i].second; // Extend the end
            } else {
                // Fully contained, do nothing
                // Can skip updating merged because it's already within bounds
            }
        } else {
            // No overlap, move to next position in merged array
            index++;
            merged[index] = intervals[i];
        }
    }

    return index + 1; // Total number of merged intervals
}

// Main function
int main() {
    struct Interval intervals[] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}, {17, 20}};
    int n = 5;

    struct Interval merged[n];
    int mergedCount = mergeIntervals(intervals, n, merged);

    printf("Merged Intervals:\n");
    for (int i = 0; i < mergedCount; i++) {
        printf("[%d, %d] ", merged[i].first, merged[i].second);
    }

    return 0;
}
