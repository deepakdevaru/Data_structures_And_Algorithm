/**
 * 
 *  Longest Substring Without Repeating Characters
 * 
 * Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

#include "stdlib.h"
#include "stdio.h"
#include"strings.h"
#include "limits.h"


#define max(a,b)((a)>(b) ? (a):(b))

int lengthOfLongestSubsString(char *arr , int size){

    if(arr == NULL) return 0;

    char *alpha['z'-'a'+ 1];

    int i = 0 , j = 0 , ans = -1;

    while(i < size -1){ //-1 inorder to consider the nULL character of the string
        
        alpha[arr[i] -'a']++;  

        if(alpha[arr[i] - 'a'] > 1){
             //elements are repeating

             while(alpha[arr[i]-'a'] > 1){

                //start removing elements
                alpha[arr[j] -'a']--;
                j++;
             } 
        }
        ans = max(ans , i-j+1);
        i++;
    }

    return ans;
}


int main(){

    char input[] = {"abcabcbb"};
    //char input[] = "bbbbbb";

    printf("length of longest subsstring %d , \n", lengthOfLongestSubsString(input , sizeof(input)/sizeof(input[0])));

    return 0;

}
