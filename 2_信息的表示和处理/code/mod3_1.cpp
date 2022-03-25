/*
 * @Descripttion: 在不设立temp的情况下，交换a、b的值。利用位级运算实现
 * @version: 
 * @Author: sch
 * @Date: 2021-07-23 15:47:14
 * @LastEditors: sch
 * @LastEditTime: 2021-07-23 16:20:50
 */
#include <stdio.h>
void swap(int a, int b);


int main(){
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    swap(a, b);
    // 注意函数内的值交换，并没有改变函数外边的值交换
    printf("After exchange: a=%d, b=%d\n", a, b);
    return 0;
}


void swap(int a, int b){
    // 原理：a ^ a = 0。在异或运算中，a是a的逆元。
    b = a ^ b;
    printf("Step one:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    a = a ^ b;
    printf("Step one:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    b = a ^ b;
    printf("Step one:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
}