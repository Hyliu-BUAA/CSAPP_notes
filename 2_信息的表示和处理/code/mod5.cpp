/*
 * @Descripttion: 字节掩码运算（对int num进行字节掩码运算）
 * @version: 
 * @Author: sch
 * @Date: 2021-07-24 11:25:44
 * @LastEditors: sch
 * @LastEditTime: 2021-07-24 11:37:23
 */
#include <stdio.h>
void show_high_byte(int num);
void show_low_byte(int num);
void show_2_byte(int num);


int main(){
    // int类型有4个字节，由8个16进制数表示
    int num = 0x12345678;
    // 通过掩码运算，显示高位字节
    show_high_byte(num);
    // 通过掩码运算，显示低位字节
    show_low_byte(num);
    // 通过掩码运算，显示第二个字节
    show_2_byte(num);
    return 0;
}


void show_high_byte(int num){
    int mask = 0xFF000000;
    printf("%.8x\n", mask & num);
}

void show_low_byte(int num){
    int mask = 0x000000FF;
    printf("%.8x\n", mask & num);
}

void show_2_byte(int num){
    int mask = 0x00FF0000;
    printf("%.8x\n", mask & num);
}