/**
 * Given an array that contains both positive and negative integers, the task is to find the product of the maximum product subarray. 

Examples:

Input: arr[] = {6, -3, -10, 0, 2}
Output:  180
Explanation: The subarray is {6, -3, -10}

Input: arr[] = {-1, -3, -10, 0, 60}
Output:   60
Explanation: The subarray is {60}
*/

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define max(a,b)((a) > (b)? (a): (b))
#define min(a,b)((a) < (b)? (a): (b))


int MaxProductSubarray(int arr[], int size){
    if (size == 0) return 0;

    int i =1;
    int max_so_far = arr[0];
    int min_so_far = arr[0];
    int max_product = arr[0];

    while(i < size){
      int temp  = max(arr[i], max(min_so_far * arr[i], max_so_far  * arr[i]));
      min_so_far = min(arr[i], min(max_so_far * arr[i], min_so_far * arr[i]));
      max_so_far = temp;

      max_product = max(max_so_far, max_product);
      i++;
    }

    return max_product;

}

int main(){

     int arr[] = {6, -3, -10, 0, 2};
     printf("maximum product %d \n",MaxProductSubarray(arr, sizeof(arr)/ sizeof(arr[0])) );

    return 0;
}
