#include <stdio.h>

#define SIZE(x) sizeof(a)/sizeof(x[0])

void main(void)
{
	int i, j, temp;
	int a[] = {1, 1, 2, 2, 3, 4, 4};

	//temp = a[0] ^ a[1] ^ a[2] ^ a[3] ^ a[4] ^ a[5] ^ a[6] ^ a[7];
	temp = a[0] ^ a[1] ^ a[2] ^ a[3] ^ a[4] ^ a[5] ^ a[6];

	temp = a[0];
	for (i = 0, j = SIZE(a) - 1; i < j; i++, j--) {
		temp = temp ^ a[j];
	}

	printf("Unique no is : %d\n", temp);
}
