/**
 * Given an array arr of n elements that is first strictly increasing and then maybe strictly decreasing, find the maximum element in the array.

Note: If the array is increasing then just print the last element will be the maximum value.

Example:

Input: array[]= {5, 10, 20, 15}
Output: 20
Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20.

Input: array[] = {10, 20, 15, 2, 23, 90, 67}
Output: 20 or 90
Explanation: The element 20 has neighbors 10 and 15, both of them are less than 20, similarly 90 has neighbors 23 and 67.
 * 
 * 
*/
#include "stdlib.h"
#include "stdio.h"

int findMaximumElement(int arr[], int size){

    if(size == 0 ) return 0;

    if (size == 1) return arr[0];

    if(size == 2){
        return (arr[0] < arr[1])? arr[1] : 0;
    }

    int i = 1;
    int max = 0;
    while (i < size-1){
         if(arr[i] > arr[i-1] && arr[i] >= arr[i+1] ){
            max = (max > arr[i])? max:arr[i];
         }
         i++;
    }
    if(i == size-1 && arr[i] >= arr[i-1]){
        max = (max > arr[i])? max:arr[i];
    }
    return max;
}

int main(){


    int arr1[] = {5, 10, 20, 15};
    int arr2[] = {2,1};
    int arr3[] = {1,2};
    int arr4[] = {1,2,3,4};
    int arr5[] = {1,2,3,4,3,6};

    printf("arr1 max %d \n", findMaximumElement(arr1 , (sizeof(arr1)/ sizeof(arr1[0]))));
    printf("arr2 max %d \n", findMaximumElement(arr2 , (sizeof(arr2)/ sizeof(arr2[0]))));
    printf("arr3 max %d \n", findMaximumElement(arr3 , (sizeof(arr3)/ sizeof(arr3[0]))));
    printf("arr4 max %d \n", findMaximumElement(arr4 , (sizeof(arr4)/ sizeof(arr4[0]))));
    printf("arr4 max %d \n", findMaximumElement(arr5 , (sizeof(arr5)/ sizeof(arr5[0]))));
    return 0;
}