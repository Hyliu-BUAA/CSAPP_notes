/*
 * @Descripttion: 强制类型转换--保持位值不变，只是改变了解释位的方式
 * @version: 
 * @Author: sch
 * @Date: 2021-07-25 11:20:09
 * @LastEditors: sch
 * @LastEditTime: 2021-07-25 11:25:38
 */
#include <stdio.h>


int main(){
    short int v = -12345;
    // 保持位值不变，改变了解释这些位的方式
    // 补码（two's complement）--> 无符号数的编码方式
    unsigned short uv = (unsigned short) v;
    printf("short int: %d\n", v);
    printf("unsigned short: %u\n", uv);
    return 0;
}