1. Find uniques no. in a given integer array elemets: arr[] = {111, 2, 3, 3, 4, 4, 4, 5, 5, 5}; Time complexity should be O(N) and
   space complexity should be O(1).

/* 2. Take a 4 integer input and add them with using only one variable. */
int main(void)
{
	int a;

	/* solution 1 */
	printf(" a =%d\n",scanf("%d",&a) + a + scanf("%d",&a) + a + scanf("%d",&a) + a + scanf("%d",&a) + a - 4);
	/* solution 2 */
	a = ((scanf("%d",&a) ? a : 0) + (scanf("%d",&a) ? a : 0) + (scanf("%d",&a) ? a : 0) + (scanf("%d",&a) ?a : 0));
	printf("%d\n",a);

	return 0;
}

3. Implement malloc
5. offsetof/container_of Macro

