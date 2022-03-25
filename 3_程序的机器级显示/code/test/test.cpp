#include <stdio.h>
#include <stdlib.h>
int tadd_ok ( int x, int y );


int main(){
	int a=1, b=2;
	printf("%d\n", tadd_ok(a, b));
	return 0;
}


int tadd_ok ( int x, int y ) {
    int sum = x + y;
    return ( sum - x == y ) && ( sum - y == x );
}
