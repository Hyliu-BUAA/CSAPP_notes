/*
 * @Descripttion: Bit-level operation in C/C++。本程序用16进制表示(两个16进制数字代表一个字节)，因为字节是最小寻址单位
 * @version: 
 * @Author: sch
 * @Date: 2021-07-23 15:03:17
 * @LastEditors: sch
 * @LastEditTime: 2021-07-23 15:31:38
 */
#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(unsigned char x);

int main(){
    // 布尔值的位运算：16进制 -> 二进制表示 -> 二进制运算 -> 16进制
    // binary: a=0101, b=0x1001
    unsigned char a=5, b=9;
    show_int(a);
    show_int(b);
    // binary: a & b = 0001
    printf("a & b = %.2x\n", a & b);
    // binary: a | b = 1101
    printf("a | b = %.2x\n", a | b);
    // binary: a ^ b = 1100
    printf("a ^ b = %.2x\n", a ^ b);
    return 0;
}


void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i=0; i<len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(unsigned char x){
    show_bytes((byte_pointer) &x, sizeof(unsigned char));
}