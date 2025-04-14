#include <stdio.h>

int findMajorityElement(int arr[], int n) {
    for (int i = 0; i < n; i++) {//Picks each element arr[i] one by one.
        int count = 0;
        for (int j = 0; j < n; j++)
            if (arr[i] == arr[j])
                count++;  //Counts how many times arr[i] appears in the whole array.

        if (count > n / 2)//If the count is more than half the array's size, return it as the majority element.
            return arr[i];
    }
    return -1;//if no such element is found in the loop return -1
}

int main() {
    int arr[] = {2, 2, 1, 1, 2, 2, 2};
    int n = 7;
    
    int majority = findMajorityElement(arr, n);
    
    if (majority != -1)
        printf("The Majority Element is %d\n", majority);
    else
        printf("No Majority Element found\n");
        
    return 0;
}