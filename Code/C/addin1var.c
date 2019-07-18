#include <stdio.h>

void main(void)
{
	int var;

	/* M1 */
	printf("Res: %d\n", scanf("%d",&var) + var + scanf("%d",&var) +var + scanf("%d",&var) + var + scanf("%d",&var) + var - 4);
	/* M2 */
	var = ((scanf("%d",&var) ? var : 0) + (scanf("%d",&var) ? var : 0) + (scanf("%d",&var) ? var : 0) + (scanf("%d",&var) ?var : 0));
	printf("Res: %d\n", var);

}
