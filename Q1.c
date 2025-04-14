#include<stdio.h>
#include<stdlib.h>


void msa(int arr1[],int arr2[], int size2, int size1,int merarr[]) {
 
int j=0;
int k=0;
int i=0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) { //compairing the values of elements in arr1 and arr2 so they can be murged in a sorted order 
            merarr[k++] = arr1[i++];//inserting value from arr1
        } else {
            merarr[k++] = arr2[j++];//inserting value form arr2 
        }
        //copy any remaining elements from arr1
        while (i < size1) {
            merarr[k++] = arr1[i++];
        }
    
        // Copy any remaining elements from arr2
        while (j < size2) {
            merarr[k++] = arr2[j++];
        }
}
}
int main() {
    int arr1[] = {1, 3, 5, 7 , 9};//declare arr 1
    int arr2[] = {2, 4, 6, 8, 11};//declare arr 2
    int size1 = 5;//hardcoding their size
    int size2 = 5;
   int merarr [size1 + size2]; //the murged array should hold the combined size of arr1 and 2

    msa(arr1,arr2, size2,size1, merarr);
    printf("Merged Array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", merarr[i]);
    }

    return 0;
}