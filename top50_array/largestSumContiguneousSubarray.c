/**
 * 
 * Given an array arr[] of size N. The task is to find the sum of the contiguous subarray within a arr[] with the largest sum. 
 * 
*/
#include "stdio.h"
#include"stdlib.h"
#include "strings.h"
#include "limits.h"


int SumOfContiguousSubArray(int arr[], int size){
    if(size == 0)return 0;

    int current_max_sum = 0;
    int max_sum = INT_MIN;

    int i = 0;

    while(i < size){
      current_max_sum = current_max_sum + arr[i];
      if(max_sum < current_max_sum){
        max_sum = current_max_sum;
      }
      if(current_max_sum < 0){
        current_max_sum = 0;
      }
      i++;

    }

    return max_sum;

}
int main(){

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    printf("sum of subarray %d \n", SumOfContiguousSubArray(arr, sizeof(arr)/sizeof(arr[0])));

    return 0;
}