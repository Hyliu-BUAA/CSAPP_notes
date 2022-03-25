/*
 * @Descripttion: 位表示的扩展 和 有/无符号转换 的相对顺序会影响程序最后结果
 * @version: 
 * @Author: sch
 * @Date: 2021-07-25 16:17:01
 * @LastEditors: sch
 * @LastEditTime: 2021-07-25 16:23:12
 */
#include <stdio.h>


int main(){
    short int sx = -12345;
    // 先 有符号-->无符号
    unsigned short usx = sx;
    unsigned int ux3 = usx;
    printf("%u\n", ux3);
    // 先扩展，再 有符号-->无符号
    int x = sx;
    unsigned int ux1 = x;
    printf("%u\n", ux1);
    // 先扩展，再 有符号-->无符号
    unsigned int ux2 = sx;
    printf("%u\n", ux2);
    return 0;
}