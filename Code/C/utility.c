#include <stdio.h>

/* Functions */

/* 1. Integer to binary */

void int2bin(int data)
{
	int i;

	for (i = 31; i >= 0; i--) {
		printf("%d", (data >> i) & 1);
	}
	puts("");
}

/* 2. Swap the two bits in an integer */

int swap_bits(int num, int b1, int b2)
{
	int x;

	x = ((num >> b1) & 1) ^ ((num >> b2) & 1);

	num = num ^ ((x << b1) | (x << b2));

	return num;
}

void main(void)
{
	int data, b1, b2;

	printf("Enter data: ");
	scanf("%d", &data);
	printf("Enter bit1: ");
	scanf("%d", &b1);
	printf("Enter bit1: ");
	scanf("%d", &b2);

	printf("Input Data: ");
	int2bin(data);
	data = swap_bits(data, b1, b2);
	printf("After swapping: ");
	int2bin(data);
}
