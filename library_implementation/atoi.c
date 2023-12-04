#include "stdio.h"
#include "string.h"

int atoi_i(char *word , int base ){
    
    if(base == 0 != word == NULL) return 0;
    int neg = 0;
    int ans = 0;
    int size = strlen(word);
    int i = 0;
    
    if(word[0] == "-"){
       neg = 1;
       i++;
     }
     
     while (i< size){
        ans = (ans * base);
        if(base != 16){
            int temp = (word[i] -'0');
            ans = ans+temp;
        }
        else{
            if(word[i]>='a' && word[i]<='f'){
                ans+=(word[i]-'a' +10);
            }
            else if(word[i]>='A' && word[i]<='F'){
                ans+=(word[i]-'A' +10);
            }
            else if(word[i]>='0' && word[i] <= '9'){
                ans+=word[i]-'0';
            }
        }

        i++;

     }
     return (neg == 1)? -ans:ans;
    
}




int main(){

    char *test_1base10 = "123456";
    printf("test_1base10 %d \n" , atoi_i(test_1base10,10));

    char *test_2base10 = "-123456";
    printf("test_2base10 %d \n" , atoi_i(test_2base10,10));

    char *test_3base2 = "123456";
    printf("test_3base2 %d \n" , atoi_i(test_3base2,2));

    char *test_4base16 = "1abcf23";
    printf("test_4base16 %d \n" , atoi_i(test_4base16,16));

    char *test_5base16 = "1A";
    printf("test_1base10 %d \n" , atoi_i(test_5base16,16));

    return 1;

}