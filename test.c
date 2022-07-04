#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
int check1(){
    int input, x, i;
    char tmp1[8];
    read(0, &input, 4);
    x=0;
    for (i = 0; i < 32; i++){
        if (input & (1 << i)){
            x |= 1 << i;
        }
    }
    read(0, tmp1, x);
    return 0;
}
int check2(void){
    char input[4];
    char x[4];
    char c=0;
    int check1, check2=0;
    
    read(0, &check1, 4);
    read(0, input, 4);
    memset(x, 0, 4);
    while(c<32){
        if(check1 & (1<<c)){
            check2 |= (1<<c);
        }
        c++;
    }
    if(check2==0xdeadbeaf){
        c=0;
        while(c<32){
            if((*(int*)input) & (1<<c)){
                *(int*)x |= (1<<c);
            }
            c++;
        }
        // printf("%x\n", *(int*)x);
        if(*(int*)x == 0xdeadbeaf){
            memcpy(input, input + 10, 60);
        }
    }
    return 0;
}
void check3(){
    int input;
    char tmp[8];
    read(0, &input, 4);
    read(0, tmp, input);
}
int main(void){
    check1();
    check2();
    check3();
    return 0;
}