/**
 * 
 * Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every 
 * character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "limits.h"

#define min(a,b)((a) <(b)? (a): (b))

int minwindowsubs(char *s1 , char *s2 , int size1 , int size2){
 
   int left  = 0 , right = 0 , ans = size1;

   int s[256] = {0};
   int t[256] = {0};

   while(left < size2){
    s[s2[left]]++;
    left++;
   }
   left = 0;
   int targetsize = size2;
   int minwindowstart = 0;

   while(right < size1){
     if(s[s1[right]] > 0){
       targetsize --;
     }
     t[s1[right]]++;
     right++;

     if(targetsize ==  0){
       //we have completed all the items from size 2. hence increment left to find min size

       while(targetsize == 0 ){
            if(right - left < ans){
                ans = right-left;
                minwindowstart = left;
            }
            t[s1[left]] --;

            if(s[s1[left]] > 0 && t[s1[left]] < s[s1[left]]){
                targetsize++;
            }
            left++;

       }
     }

   }

   return ans;

}

int main(){

    char * s = "ADBANC";
    char * t = "ABC";

    printf("min windown substring %d \n", minwindowsubs(s , t , strlen(s), strlen(t)));
    return 0;
}

