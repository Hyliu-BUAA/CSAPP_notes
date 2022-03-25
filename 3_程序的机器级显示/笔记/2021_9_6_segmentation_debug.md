# How to find Segmentation fault?
# 1. Steps
If a file named `test1.cpp` collapse since `segmentation error`. We should do as following to debug:
1. Compile（with `-g` option on -- turn on debugger）
```shell
linux > g++ -g test1.cpp -o test1
```
2. Open gdb console ( A debugger ): 
```shell
linux > gdb
```
3. Use `file` command to pass your executable to gdb console
```shell
gdb > file test1
```
4. Use `run` command to start your program
```shell
gdb > run
```
5. Do something to cause a Segmentation Fault.
6. Type `bt` in the gdb console to get a stack trace of the Segmentation Fault.
```shell
gdb > bt
```



# 2. Examples
```c++
// test.cpp 

#include <stdio.h>
#include <stdlib.h>
void change(char *name);

int main(){
        // name是字符串常量的指针，所以不能修改字符串中特定的字符，否则就会发生Segmentation Fault
        char *name = (char *)"CYX";
        change(name);
        name[1] = 'Z';
        return 0;
}


void change(char *name){
        printf("%c\n", name[1]);
        name[1] = 'Z';
        printf("%c\n", name[1]);
}
```
1. 编译，并运行，发现引发了<font color="red">Segmentation Fault</font>
```g++
// 打开 -g 选项，保存debug symbol
linux > g++ -g test.cpp -o test

// 运行
linux > ./test
Y
Segmentation fault (core dumped)
```

2. 打开gdb控制台
```shell
linux > gdb
```

3. 导入executable
```shell
gdb > file test
```

4. 运行executable，并引发segmentation Fault
```shell
gdb > run 
Starting program: /home/hyliu/lhy/Notebook/csapp/3_程序的机器级显示/code/test 
Y

Program received signal SIGSEGV, Segmentation fault.
change (name=0x555555556004 "CYX") at test.cpp:16
16	        name[1] = 'Z';
```

5. 回溯Segmentation Fault
```shell
gdb > bt
#0  change (name=0x555555556004 "CYX") at test.cpp:16
#1  0x000055555555516c in main () at test.cpp:8
```




# 3. Example 修正
## 3.1 方法一
```c++
#include <stdio.h>
#include <stdlib.h>
void change(char *name);

int main(){
        char name[10] = "CYX";
        // change(name);
        name[1] = 'Z';
        return 0;
}


void change(char *name){
        printf("%c\n", name[1]);
        name[1] = 'Z';
        printf("%c\n", name[1]);
}
```
## 3.2 方法二
```c++
#include <stdio.h>
#include <stdlib.h>
void change(char *name);

int main(){
        char _name[10] = "CYX";
        char *name;
        name = _name;
        // change(name);
        name[1] = 'Z';
        printf("%s\n", name);
        return 0;
}


void change(char *name){
        printf("%c\n", name[1]);
        name[1] = 'Z';
        printf("%c\n", name[1]);
}

```