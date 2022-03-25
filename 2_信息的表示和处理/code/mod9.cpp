/*
 * @Descripttion: Why shoud i use Unsigned
 * @version: 
 * @Author: sch
 * @Date: 2021-07-27 10:17:00
 * @LastEditors: sch
 * @LastEditTime: 2021-07-27 10:17:24
 */
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);


int main(){
    int x = 0;
    printf("%d:\t", x);
    show_bytes((byte_pointer) &x, sizeof(int));
    unsigned int ux = x;
    printf("%u:\t", ux);
    show_bytes((byte_pointer) &ux, sizeof(unsigned int));
    int y = x - 1;
    printf("%d:\t", y);
    show_bytes((byte_pointer) &y, sizeof(int));
    unsigned int uy = y;
    printf("%u:\t", uy);
    show_bytes((byte_pointer) &uy, sizeof(unsigned int));
    return 0; 
}


void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i=0; i<len; i++){
        printf("%.2x ", start[i]);
    }
    printf("\n");
}