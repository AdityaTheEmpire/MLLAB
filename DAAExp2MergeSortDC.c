#include <stdio.h> 
void merge(int arr[], int l, int m, int r){ 
    int i, j, k; 
    int n1 = m - l + 1;  
    int n2 = r - m;  
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) R[j] = arr[m + 1+ j]; 
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray  
    while (i < n1 && j < n2){  
        if (L[i] <= R[j]) 
            arr[k] = L[i]; i++; 
        else 
            arr[k] = R[j]; j++; 
        k++;  
    } 
    while (i < n1){  
        arr[k] = L[i];  
        i++;k++;  
    } 
    while (j < n2){  
        arr[k] = R[j];  
        j++;k++;  
    } 
} 
void mergeSort(int arr[], int l, int r){ 
    if (l < r) { 
        int m = l+(r-l)/2;  
        mergeSort(arr, l, m);  
        mergeSort(arr, m+1, r);  
        merge(arr, l, m, r);  
    }  
} 
void printArray(int A[], int size){ 
    int i; 
    for (i=0; i < size; i++)  
        printf("%d ", A[i]); 
    printf("\n");  
}  
void main(){ 
    int arr[] = {70, 50, 30, 10, 20, 40,60}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]);  
    printf("Given array is \n");  
    printArray(arr, arr_size);  
    mergeSort(arr, 0, arr_size - 1);  
    printf("\nSorted array is \n");  
    printArray(arr, arr_size);} 
/*
Output
Given array is 
70 50 30 10 20 40 60 

Sorted array is 
10 20 30 40 50 60 70
*/
