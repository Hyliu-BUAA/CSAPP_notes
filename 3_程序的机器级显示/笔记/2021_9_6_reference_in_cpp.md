# 1. Reference Variable
## 1.1 Use
<font color="gree"><b>Reference variable allows two variable names to address the same memory location;</b></font>

```c++
// test.cpp
#include <stdio.h>


int main(){
        int var1 = 10;
        // var2 is a reference variable, holds same value as var1, addresses same memoty location as var1
        int &var2 = var1;

        printf("var1 = %d, address = %p\n", var1, &var1);
        printf("var2 = %d, address = %p\n", var2, &var2);

        var2 = 20;
        printf("var1 = %d, address = %p\n", var1, &var1);
        printf("var2 = %d, address = %p\n", var2, &var2);
        return 0;
}
```
编译：`g++ test.cpp -o test`
<font size="4"><b>Output:</b></font>
```shell
var1 = 10, ad编译dress = 0x7ffcc4d5804c
var2 = 10, address = 0x7ffcc4d5804c
var1 = 20, address = 0x7ffcc4d5804c
var2 = 20, address = 0x7ffcc4d5804c
```

## 1.3 Example 2 ( int pointer )
```c++
// test.cpp

#include <stdio.h>
#include <stdlib.h>


int main(){
        int *var1;
        int *var2;
        var1 = (int *)malloc(sizeof(int));
        var2 = (int *)malloc(sizeof(int));
        *var1 = 10;
        *var2 = 20;
        // var3 is a reference variable.
        int *&var3 = var2;

        printf("var3 reference to var2\n");
        printf("var1 = %d, address = %p\n", *var1, var1);
        printf("var2 = %d, address = %p\n", *var2, var2);
        printf("var3 = %d, address = %p\n", *var3, var3);

        // After this, var1、var2、var3 address the same memory location
        printf("var3 reference to var1\n");
        var3 = var1;
        printf("var1 = %d, address = %p\n", *var1, var1);
        printf("var2 = %d, address = %p\n", *var2, var2);
        printf("var3 = %d, address = %p\n", *var3, var3);

        // Free memory of location that var pointing to.
        // Note not free repeatly the same memory location.
        free(var1);
        return 0;
}
```
编译：`g++ test.cpp -o test.cpp`
<font size="4"><b>Output:</b></font>
```shell
var3 reference to var2
var1 = 10, address = 0x5645b32352a0
var2 = 20, address = 0x5645b32352c0
var3 = 20, address = 0x5645b32352c0

var3 reference to var1
var1 = 10, address = 0x5645b32352a0
var2 = 10, address = 0x5645b32352a0
var3 = 10, address = 0x5645b32352a0
```

## 1.4 Reference Variable as Formal Parameter ( int )
```c++
#include <stdio.h>
#include <stdlib.h>
void add_1(int &x);

int main(){
        int var = 1;
        add_1(var);
        // Your function expects a reference to an actual string pointer in the calling scope, not an anonymous string pointer.
        printf("%d\n", var);
        return 0;
}


void add_1(int &x){
        x += 1;
}
```
编译：`g++ test.cpp -o test`
```shell
2
```

## 1.5 Reference Variable as Formal Parameter ( int pointer )
### 1.5.1 Change the specific char in string array(char array)
```c++
// test.cpp
#include <stdio.h>
#include <stdlib.h>
void change(char *&name);

int main(){
        char _name[10] = "CYX";
        char *name;
        name  = _name;
        printf("Before change, name = %s\n", name);
        change(name);
        printf("After change, name = %s\n", name);
        return 0;
}


void change(char *&name){
        name[1] = 'Z';
}
```
编译：`g++ test.cpp -o test`

<font><b>Output:</b></font>
```shell
Before change, name = CYX
After change, name = CZX
```

### 1.5.2 Change the pointer
略