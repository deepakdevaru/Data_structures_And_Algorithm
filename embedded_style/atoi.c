//IMPLEMENT ASCII TO INTEGER

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "strings.h"


#define MAX_SIZE 0xffffffffU

uint32_t atoi_internal(char* input, uint32_t base){
  if(input == NULL) return 0;
  if(input[0] == '-') return 0;

  char c;
  uint32_t ans = 0;;

  while(input != NULL && *input != '\0'){
 
    c = *input;
    if((ans * base) >= MAX_SIZE) return MAX_SIZE;

    ans *= base;

    if((c >= '0' && c <='9') ||
        c>='A' && c <= 'z'){

      if(c >= 'A' && c <='Z'){
        c ^= 32;
      }  
      if(c >= 'a'){
        c = (c - 'a')+10;
      }
      else{
        c = c - '0';
      }

      if((ans + (uint32_t)c) >= MAX_SIZE) return MAX_SIZE;

      ans+= (uint32_t)c;
    }
    else{
        return 0;
    }

    input++;
  }

  return ans;
}

int main(){

    char *arr = "00ABCDef";
    printf("atoi is %d \n", atoi_internal(arr, 16));

    return 0;
}