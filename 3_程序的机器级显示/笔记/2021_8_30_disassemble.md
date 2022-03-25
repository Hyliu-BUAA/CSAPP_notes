# 1. 反汇编（disassemble）
逆向工程(reverse engineering)的一种
- `objdump -d <executable / object_file>`
- `gdb`
        - `gdb <executable>`
        - `disassemble <executable>`

## 使用文件
```c++
// main.cpp

#include <stdio.h>
#include <stdlib.h>


long mult2(long, long);
void mult2store(long, long, long *);
7
int main(){
        long *result;
        result = (long *)malloc(sizeof(long));
        mult2store(2, 3, result);
        printf("2 * 3 --> %ld\n", *result);
        free(result);
        return 0;
}


long mult2(long a, long b){
        long tmp = a * b;
        return tmp;
}
```

```c++
#include <stdlib.h>7
long mult2(long, long);


void mult2store(long x, long y, long *dest){
        long tmp = mult2(x, y);
        // 指针指向的值发生了改变
        *dest = tmp;
}
```

## 1.1. `objdump -d <object_file / executable>`
```shell
linux > ls
main.cpp  mstore.cpp
linux > g++ -o main main.cpp mstore.cpp
linux > ls
main.cpp  main  mstore.cpp 
linux > objdump -d main
```
<font size="5" color="green">Output:</font>
```shell
...
...

000000000000120a <_Z10mult2storellPl>:
    120a:       f3 0f 1e fa             endbr64 
    120e:       55                      push   %rbp
    120f:       48 89 e5                mov    %rsp,%rbp
    1212:       48 83 ec 30             sub    $0x30,%rsp
    1216:       48 89 7d e8             mov    %rdi,-0x18(%rbp)
    121a:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
    121e:       48 89 55 d8             mov    %rdx,-0x28(%rbp)
    1222:       48 8b 55 e0             mov    -0x20(%rbp),%rdx
    1226:       48 8b 45 e8             mov    -0x18(%rbp),%rax
    122a:       48 89 d6                mov    %rdx,%rsi
    122d:       48 89 c7                mov    %rax,%rdi
    1230:       e8 b2 ff ff ft:f          callq  11e7 <_Z5mult2ll>
    1235:       48 89 45 f8             mov    %rax,-0x8(%rbp)
    1239:       48 8b 45 d8             mov    -0x28(%rbp),%rax
    123d:       48 8b 55 f8             mov    -0x8(%rbp),%rdx
    1241:       48 89 10                mov    %rdx,(%rax)
    1244:       90                      nop
    1245:       c9                      leaveq 
    1246:       c3                      retq   
    1247:       66 0f 1f 84 00 00 00    nopw   0x0(%rax,%rax,1)
    124e:       00 00 

...
...
```

## 1.2. `gdb`调试工具
```shell
linux > ls
main.cpp  mstore.cpp
linux > g++ -o main main.cpp mstore.cpp
linux > ls
main.cpp  main  mstore.cpp 
linux > gdb main

gdb > disassemble main
```
<font size="5" color="green" font-weight="bold">Output:</font>
```shell
Dump of assembler code for function main:
   0x0000000000001189 <+0>:	endbr64 
   0x000000000000118d <+4>:	push   %rbp
   0x000000000000118e <+5>:	mov    %rsp,%rbp
   0x0000000000001191 <+8>:	sub    $0x10,%rsp
   0x0000000000001195 <+12>:	mov    $0x8,%edi
   0x000000000000119a <+17>:	callq  0x1090 <malloc@plt>
   0x000000000000119f <+22>:	mov    %rax,-0x8(%rbp)
   0x00000000000011a3 <+26>:	mov    -0x8(%rbp),%rax
   0x00000000000011a7 <+30>:	mov    %rax,%rdx
   0x00000000000011aa <+33>:	mov    $0x3,%esi
   0x00000000000011af <+38>:	mov    $0x2,%edit:
   0x00000000000011b4 <+43>:	callq  0x120a <_Z10mult2storellPl>
   0x00000000000011b9 <+48>:	mov    -0x8(%rbp),%rax
   0x00000000000011bd <+52>:	mov    (%rax),%rax
   0x00000000000011c0 <+55>:	mov    %rax,%rsi
   0x00000000000011c3 <+58>:	lea    0xe3a(%rip),%rdi        # 0x2004
   0x00000000000011ca <+65>:	mov    $0x0,%eax
   0x00000000000011cf <+70>:	callq  0x1080 <printf@plt>
   0x00000000000011d4 <+75>:	mov    -0x8(%rbp),%rax
   0x00000000000011d8 <+79>:	mov    %rax,%rdi
   0x00000000000011db <+82>:	callq  0x1070 <free@plt>
   0x00000000000011e0 <+87>:	mov    $0x0,%eax
```


# 2. `gdb`：程序的字节表示
## 2.1. 举例`(gdb) x/14xb mult2`
- `x`：这条命令告诉`gdb`显示
- `14xb`：从函数`mult2`所处地址开始的14个16进制格式（也简写为`x`）的字节（简写为`b`）

## 2.2. 使用实例
1. 在`mstore.o`上运行GNU调试工具`gdb`，输入命令：
```shell
linux > gdb mstore.o
```
2. 查看`mstore.cpp`中`mult2store`函数所处地址开始的14个16进制格式。输入下列命令：
```shell
(gdb) > x/14xb mult2store
```