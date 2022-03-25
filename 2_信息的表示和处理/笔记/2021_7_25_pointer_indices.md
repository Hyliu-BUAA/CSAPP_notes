<!--
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2021-07-25 10:35:55
 * @LastEditors: sch
 * @LastEditTime: 2021-07-25 11:03:33
-->
# 1. Pointer Indices（指针索引）
## 1.1 Keypoints
If `p` is a pointer pointing to a int64_t.
- `p[1]` <--> `*(p+1)`: int, %PRId64
- `&p[1]` <--> `p+1`: int, %p
```c++
// Initialize a int type variable
int a;
// Initialize a pointer pointing to int type variable
int *p = &a;

// p[2] is equal to *(p + 2) -- is a int 
p[2]

// &p[2] is a pointer
&p[2]
```
## 1.2 程序演示
```c++
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>


int main(){
    int64_t a = 1;
    int64_t *p = &a;
    printf("a的地址为%p,\t", &a);
    printf("a的值为%"PRId64"\n", a);
    printf("p[0]的地址为%p,\t", &p[0]);
    printf("p[0]的值为%"PRId64"\n", p[0]);
    printf("p[1]的地址为%p,\t", &p[1]);
    printf("p[1]的值为%"PRId64"\n", p[1]);
    printf("p++的地址为%p,\t", p+1);
    printf("p的值为%"PRId64"\n", *(p+1));
    return 0;
}
```


## 1.3 Graphic
To help you better understand, lets try and make it more "graphical"...

Memory is a series of consecutive locations where values can be stored. After your assignment ip = (int*)p you can look at ip like this:
```shell
ip
|
v
+-------+-------+-------+----
| ip[0] | ip[1] | ip[2] | ...
+-------+-------+-------+----
^       ^       ^       ^
|       |       |       |
100     104     108     112
```
Since ip is a pointer, there is really no specific end to the "array" it points to, the end you have to keep track of yourself.

Now when it comes to addressing, for simplicity's sake lets say that ip points to the address 100, that means that the contents of the variable ip is 100. Lets also say that sizeof(int) == 4.

Then when you do ip[2] it's the same thing as doing *(ip + 2), then you are adding 2 * sizeof(int) (i.e. 8) as byte offset to the pointer, and get address 108 which is then dereferenced giving you the contents of ip[2] (whatever that might be).


## 1.4 指针索引的交换律
因为 <font color="red" size="3">*(p+1) <--> *(1+p)</font>
所以 <font color="red" size="3">p[1] <--> 1[p]</font>