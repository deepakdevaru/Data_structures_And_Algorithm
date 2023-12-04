/**
 * 
 * 
 * Given an array, the task is to cyclically rotate the array clockwise by one time. 

Examples:  

Input: arr[] = {1, 2, 3, 4, 5}
Output: arr[] = {5, 1, 2, 3, 4}

Input: arr[] = {2, 3, 4, 5, 1}
Output: {1, 2, 3, 4, 5}

*/

#include "stdlib.h"
#include "stdio.h"

void rotationOfArray(int *arr , int size){

    if (arr == 0) return;

    int i = 0 , j = size-1;
    while(i != j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
    }
    return;
}
int main(){

    int arr[] = {1,2,3,4,5};
    rotationOfArray(arr, (sizeof(arr))/sizeof(arr[0]));
    
    printf("rotated array is: ");

    for(int i = 0; i < ((sizeof(arr))/sizeof(arr[0])); i++){
        printf(" %d,",arr[i]);
    }
    return 0;
}