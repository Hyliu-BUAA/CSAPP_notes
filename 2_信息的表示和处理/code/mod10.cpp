/*
 * @Descripttion: 编写函数查看 Unsigned Addition (unsigned short) 是否溢出
 * @version: 
 * @Author: sch
 * @Date: 2021-07-27 11:34:41
 * @LastEditors: sch
 * @LastEditTime: 2021-07-27 11:36:06
 */
#include <stdio.h>
#include <math.h>
int uadd_ok(unsigned short x, unsigned short y);


int main(){
    unsigned short x = 6 * pow(10, 4);
    unsigned short y = 5 * pow(10, 4);
    unsigned short sum = x + y;
    printf("%d\n", x);
    printf("%d\n", y);
    printf("%d\n", sum);
    printf("%d\n", uadd_ok(x, y));
    return 0;
}


int uadd_ok(unsigned short x, unsigned short y){
    // 查看Unsigned Addition（针对unsign short是否溢出）
    unsigned short sum = x + y;
    if (sum < x || sum < y)
        return 0;
    return 1;
}