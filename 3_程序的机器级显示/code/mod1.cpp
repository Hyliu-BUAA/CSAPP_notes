#include <stdio.h>
#include <stdlib.h>

long plus(long x, long y){
    return x + y;
}

void sumstore(long x, long y, long *dest){
    long t = plus(x, y);
    // dest是一个地址，（没有分配内存空间），就直接赋值了
    *dest = t;
}


int main(int args, char *argv[]){
    long x = atoi(argv[1]);
    long y = atoi(argv[2]);
    // 定义z的时候，已经为z分配好内存空间了，后传入形参*dest
    long z;
    sumstore(x, y, &z);
    printf("%ld + %ld --> %ld\n", x, y, z);
    return 0;
}