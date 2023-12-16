//   INTERGER TO STRING

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "strings.h"

#define MAX_BUFFER_SIZE 33
int itoa_internal(uint32_t num , uint32_t base , char* ans){
   ans [MAX_BUFFER_SIZE-1] = '\0';
   int size = MAX_BUFFER_SIZE-1-1;

   
   if(num == 0) {
    return 1;
   }
   while(size >=0 && num != 0){
    uint32_t rem = num % base;
    char c = ' ';

    if(base == 16){
      if(rem >= 10 && rem <=15){
        c = (char)((char)(rem - 10) + 'a');
      }
      else{
        c = (char)((char)rem + '0');
      }
    }
    else{
        c = (char)((char)rem + '0');
    }
    ans[size--] = c;
    num = num / base;
   }
   return 1;
}

int main(){

    char ans[MAX_BUFFER_SIZE];
    memset(ans, '0', sizeof(char)*MAX_BUFFER_SIZE);

    if(0 == itoa_internal(10, 2 , ans)){
        printf("error %s\n" , ans);
        return 0;
    }
    printf("itoa is %s \n", ans);
    return 0;
}