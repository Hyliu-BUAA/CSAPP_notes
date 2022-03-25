<!--
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2021-07-27 16:55:29
 * @LastEditors: sch
 * @LastEditTime: 2021-07-27 17:06:17
-->
# 1. 加法溢出 
## 1.1 判断`Unsigned Addition`是否溢出
- `溢出`：num > pow(2, w)
```c++
int uadd_ok(unsigned short x, unsigned short y){
    // 溢出：return 0;
    // 不溢出：return 1;
    unsigned short sum = x + y;
    if (sum < x || sum < y)
        return 0
    return 1
}
```

## 1.2 判断`Two's complement Addition`是否溢出
- `正溢出`：num > pow(2, w-1)
- `负溢出`：num < -pow(2, w-1)
```c++
int tadd_ok(short int x, short int y){
    short int sum = x + y;
    if (x > 0 && y > 0 && sum <=0)
        return 1;
    else if (x < 0 && y < 0 && sum >= 0)
        return 1;
    return 0;
}
```