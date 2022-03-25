/*
 * @Descripttion: 扩展一个数字的位表示。无符号数扩展是在前面填充0，有符号数扩展是在前面填充最高有效位
 * @version: 
 * @Author: sch
 * @Date: 2021-07-25 15:30:49
 * @LastEditors: sch
 * @LastEditTime: 2021-07-25 16:07:25
 */
#include <stdio.h>
typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer p, size_t len);


int main(){
    short sx = -12345;
    // 隐式强制类型转换
    unsigned usx = sx;
    int x = sx;
    unsigned ux = sx;
    printf("sx = %d:\t", sx);
    show_bytes((byte_pointer)&sx, sizeof(short));
    printf("usx = %u:\t", usx);
    show_bytes((byte_pointer)&usx, sizeof(unsigned short));
    printf("x = %d\t", x);
    show_bytes((byte_pointer)&x, sizeof(int));
    printf("ux = %u\t", ux);
    show_bytes((byte_pointer)&ux, sizeof(unsigned int));
    return 0;
}   
                           

void show_bytes(byte_pointer p, size_t len){
    size_t i;
    for (i=0; i<len; i++){
        printf("%.2x", p[i]);
    }
    printf("\n");
}