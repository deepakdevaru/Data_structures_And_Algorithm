

/**NETWORK BYTE ORDER TO MACHINE ORDER*/

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "strings.h"

uint32_t nthos_internal(uint32_t nwbyteorder){

    uint32_t ans = 0;
    ans |= (nwbyteorder & 0x000000ffU) << 24;
    ans |= (nwbyteorder & 0x0000ff00U) << 8;
    ans |= (nwbyteorder & 0x00ff0000U) >> 8;
    ans |= (nwbyteorder & 0xff000000U) >> 24;

    return ans;

}

int main(){

    uint32_t num = 0x12345678;
    uint32_t ans = nthos_internal(num);

    printf("ntohl of number 0x%x is 0x%x \n",num , ans);
    return 0;
}