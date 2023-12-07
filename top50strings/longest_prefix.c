/**
 * 
 * Problem Statement: Given a set of strings, find the longest common prefix.
Examples:

Input: {“geeksforgeeks”, “geeks”, “geek”, “geezer”}
Output: “gee”

Input: {“apple”, “ape”, “april”}
Output: “ap”

The longest common prefix for an array of strings is the common prefix between 2 most dissimilar strings.
 For example, in the given array {“apple”, “ape”, “zebra”}, there is no common prefix because the 2 most
  dissimilar strings of the array “ape” and “zebra” do not share any starting characters. 
*/

#include "stdio.h"
#include "limits.h"
#include "string.h"
#include "stdlib.h"



int longestCommonPrefix(char **inputarr , char** output, int inputsize ){
    if (inputsize == 0) return 0;

    for (int i = 0; i< strlen(inputarr[0]) ; i++){
        char curchar = inputarr[0][i];

        for (int j = 1; j< inputsize ; j++){

            if(curchar != inputarr[j][i] || curchar == '\0'){
                char *ans = (char*)malloc(sizeof(char)*(i+1));
                strncpy(ans , inputarr[0], i);
                ans[i] = '\0';
                *output = ans;
                return i+1;
            }
        }
    }

    *output = inputarr[0];
    return strlen(inputarr[0]);

}
int main(){

    char * arr1[] = {"geekforgeeks", "geekfo", "geekf", "gee"} ;
    int size = sizeof(arr1)/sizeof(arr1[0]);
    char * output = NULL;

    int ansize = longestCommonPrefix(arr1, &output ,size);

    printf(" the longest common prefix is %s\n",output);




    return 0;
}