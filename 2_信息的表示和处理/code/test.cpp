# include <stdio.h>
# include <limits.h>

int main(){
	int max = INT_MAX;
	int min = INT_MIN;
	unsigned umax = (unsigned int) max;
	unsigned umin = (unsigned int) min;
	printf("max = %d\n", max);
	printf("umax = %u\n", max);

	printf("max + 1 = %d\n", max + 1);
	printf("umax +1 = %u\n", umax + 1);

	printf("max + 1 = %d = %u", max+1, max+1);
	return 0;
}
