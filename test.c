#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(){
    int input, x, i;
    char tmp1[8];
    char tmp2[8];
    read(0, input, 4);
    memset(x, 0, 4);
    for (i = 0; i < 32; i++){
        if (input & (1 << i)){
            x |= 1 << i;
        }
    }
    memcpy(tmp1,tmp2, x);
    return 0;
}
