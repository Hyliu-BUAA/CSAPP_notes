<!--
 * @Descripttion: 
 * @version: 
 * @Author: sch
 * @Date: 2021-07-24 17:06:04
 * @LastEditors: sch
 * @LastEditTime: 2021-07-24 17:31:27
-->
# int类型的可移植性
# 1. `<stdint.h>`文件
- `int64_t`：64位的有符号数（8个字节，16个16进制数表示）
- `uint64_t`：64位的无符号数
```c++
#include <stdio.h>
#include <stdint.h>


int main(){
    int64_t a;
    uint64_t b;
    printf("int64_t占字节数：%d\n", sizeof(int64_t));
    printf("uint64_t占字节数：%d\n", sizeof(uint64_t));
    return 0;
}
```
Output:
```shell
int64_t占字节数：8
uint64_t占字节数：8
```

# 2. `limits.h`文件
- `INT_MAX`
- `INT_MIN`


# 3. `inttypes.h`格式化输出整型
## 宏
- `PRId32`: 用于`<stdint.h>`中的`int32_t`占位。扩展成字符`“d”`或者`“ld”`
- `PRIu64`: 用于`<stdint.h>`中的`uint64_t`占位。扩展成字符`“lu”`
## 3.1 问题描述:如何选取格式描述符（format specifiers）
In some platform, `int32_t (from stdint.h)` is `long int`, but in other platform, it could be `int`. When I want to use `printf` how can I determine which format, `"%ld"` or `"%d"`, should be used?
## 3.2 问题解决示例
Apparently, some C++ implementations require the user to write `#define __STDC_FORMAT_MACROS 1` before `#include <inttypes.h>`, even though the C++ Standard specifies that is not required.
```c++
#include <stdio.h>
#include <stdint.h>
#define __STDC_FORMAT_MACROS 1
#include <inttypes.h>


int main(){
    int64_t a=1;
    uint64_t b=2;
    printf("int64_t占字节数：%lu\n", sizeof(int64_t));
    printf("a = %"PRId64"\n", a);
    printf("int64_t占字节数：%lu\n", sizeof(uint64_t));
    printf("b = %"PRIu64"\n", b);
    return 0;
}
```

# 4. `sizeof()`返回变量/类型的字节数
## 4.1 format specifier: `%lu`