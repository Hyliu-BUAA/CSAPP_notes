/*
 * @Descripttion: 使用mod3的swap()函数，颠倒数列的顺序
 * @version: 
 * @Author: sch
 * @Date: 2021-07-23 21:03:24
 * @LastEditors: sch
 * @LastEditTime: 2021-07-24 11:25:36
 */
#include <stdio.h>
#include <stdlib.h>

// 注意函数声明的顺序不会引起报错
// 若报错Undefined symbols for architecture x86_64:，则说明函数声明有问题
void swap(int *a, int *b);
void reverse_array(int a[], int cnt);


int main(){
    int a[] = {1, 2, 3, 4, 5};
    reverse_array(a, 5);
    for (size_t i=0; i<5; i++){
        printf("%3d", a[i]);
    }
    printf("\n");
    return 0;
}


void reverse_array(int a[], int cnt){
    size_t first, last;
    // 行不通: size_t cnt = sizeof(a);
    // cnt等于元素个数，不等于字节个数(分清字节数目、元素数目)
    for (first=0, last=cnt-1; first <= last; first++, last--){
        printf("%lu, %lu\n", first, last);
        swap(&a[first], &a[last]);
    }
}

void swap(int *a, int *b){
    // 原理：a ^ a = 0。在异或运算中，a是a的逆元。
    *b = *a ^ *b;
    *a = *a ^ *b;
    *b = *a ^ *b;
}