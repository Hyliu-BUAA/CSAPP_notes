/*
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2021-07-22 21:42:47
 * @LastEditors: sch
 * @LastEditTime: 2021-07-23 14:28:33
 */
#include <stdio.h>

// 旨在分裂int的4个字节，让byte_pointer指向int的第一个字节，int成了一个字节序列（包含四个字节）
// byte_pointer: 指向unsigned char的指针
// byte_pointer p; 等效于 unsigned char *p;
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);


int main(){
    int ival = 12345;
    float fval = (float) ival; 
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);

    // 字符串
    char sval[] = "12345";
    show_bytes((byte_pointer) sval, sizeof(sval));

    char *s = "abcdef";
    show_bytes((byte_pointer) s, sizeof("abcdef"));
    return 0;
}


void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for (i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}


void show_int(int x){
    // &x -- 指向变量x的指针
    // sizeof(): return 字节数
    // 强制类型转换：int型指针（4个字节） --> unsigned char型指针（1个字节）
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}