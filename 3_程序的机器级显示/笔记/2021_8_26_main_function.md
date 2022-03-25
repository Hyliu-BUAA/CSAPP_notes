# 1. 生成汇编代码：`gcc -Og -S mod.c`
- `S`：Stop，仅仅做一部分事情
- `-Og`:希望编译器所做优化的规范，名为`g`的调试级别     
<font size="4" color="red"><b>虽然C编译器在把程序表达的计算转换为机器代码方面很出色，但仍然有一些机器特性是C程序访问不到的</b></font>
## 1.1. 汇编格式的代码：
- `ATT`: AT&T格式的汇编代码。这是GCC、objdump、和一些我们使用的工具的默认格式。命令：`gcc -Og -S -masm=att main.cpp mstore.cpp`
- `intel`: Intel格式的汇编代码。这是Micrisoft的工具，以及来自Intel的文档。命令：`gcc -Og -S -masm=intel main.cpp mstore.cpp` 

## 1.2. Intel和AT&T在表述方面有很大的区别
我们一般常用的是`AT&T`风格的汇编代码


## 本章学完之后，在运行程序时，可以往程序中传递参数

# 1. 问题描述
In many C++ IDE's and compilers, when it generates the main function for you, it looks like this:
```c++
int main(int argc, int *argv[])
```
When I code C++ without an IDE, just with a command line compiler, I type:
```c++
int main()
```
without any parameters. What does this mean, and is it vital to my program?

<font size="5" color="red">Of course they have</font>

# 2. 问题解决
Suppose you run your program thus (using sh syntax): 
```shell
./myprog "arg1" "arg2" "arg3" 
```

If you declared your main as `int main(int argc, char *argv[])`, then (in most environments), your `main()` will be called as if like:
```shell
p = { "myprog", "arg1", "arg2", "arg3", NULL };
exit(main(4, p));
```

However, if you declared your main as int main(), it will be called something like
```shell
exit(main())    // and you don't get the arguments passed.
```

## Two additional things to note:
### (1) 仅有两种可移植`main()`的定义方法
以上两种定义`main()`函数的方法是仅有的正确的。如果特定平台(platform)接受额外的参数或者返回其他类型，都是特殊的扩展，不应出现在可移植程序中。

### (2) `*argv[]` == `**argv`
1. `*argv[]` == `**argv` 
2.`int main(int argc, char *argv[])` == `int main(int argc, char **argv)`.


# 3. 代码演示以及解析
- `argc`: argument count
- `argv`: argument vector
```c++
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
        printf("%d\n", argc);
        // 当命令行不输入参数时，argc=1。argv[0]是可执行程序的文件名
        for (size_t i=0; i<argc; i++){
                int *tmp;
                tmp = (int *)malloc(sizeof(int));
                // atoi(地址)
                *tmp = atoi(argv[i]);
                printf("%d\n", *tmp);
                // free释放malloc()分配的内存空间，free(地址)
                free(tmp);
        }
        return 0;
}
```
<font size="5">Output:</font>
```shell
> g++ test.cpp -o test
> ./test "101" "202"
3
0
101
202
```

## 4. `atoi()`函数：将char转换为int
需要包含的头文件：`#include <stdlib.h>`

e.g. 
1. "202" --> 202
2. 字符串值 = 98993489, 整型值 = 98993489
3. 字符串值 = runoob.com, 整型值 = 0

```c++
#include <stdio.h>
#include <stdlib.h>

int main(){
        char x[] = "liu";
        char y[] = "h";
        char z[] = "101";
        int xi = atoi(x);
        int yi = atoi(y);
        int zi = atoi(z);
        printf("liu:\t%d\n", xi);
        printf("h:\t%d\n", yi);
        printf("101:\t%d\n", zi);
        return 0;
}
```
<font size="4">Output:</font>
```
liu:	0
h:	0
101:	101
```



<font size="5" color="red">以下演示程序有问题</font>
```c++
#include <stdlib.h>


int main(){
        char *x;
        char *y;
        char *z;
        x = (char *)malloc(sizeof(char) * 3);
        y = (char *)malloc(sizeof(char));
        z = (char *)malloc(sizeof(char) * 3);
        *x = "liu";
        *y = "h";
        *z = "101";
        int xi = atoi(x);
        int yi = atoi(y);
        int zi = atoi(z);
        printf("liu:\t%d\n", xi);
        printf("h:\t%d\n", yi);
        printf("101:\t%d\n", zi);
        return 0;
}

```