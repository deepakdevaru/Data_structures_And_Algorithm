/**
 * 
 * 
 * Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season. 
 

Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation: 

*/

#include "stdlib.h"
#include "stdio.h"

#define max(a,b)((a) > (b)? (a) : (b))
#define min(a,b)((a)<(b)? (a):(b))


int TappinRainWater(int arr[], int size){

    if(size == 0) return 0;

    int leftmax[size];
    int leftval = 0;
    int rightval = 0;
    int rightmax[size];
    int ans = 0;
    for (int i = 0; i< size; i++){
      leftval = max(leftval, arr[i]);
      leftmax[i] = leftval;
    }
    for (int i = size-1; i >=0; i--){
      rightval = max(rightval, arr[i]);
      rightmax[i] = rightval;
    }

    for(int i = 0 ; i< size ; i++){

        ans += min(rightmax[i], leftmax[i])-arr[i];

    }

    return ans;

}

int main(){
    int arr[] = {3,0,0,2,0,4};

    printf("arr1 result %d \n", TappinRainWater(arr, sizeof(arr)/sizeof(arr[0])));



    return 0;
}