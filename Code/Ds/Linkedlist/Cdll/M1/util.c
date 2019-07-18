#include "header.h"

static int cnt = 1;

int get_data(void)
{
	return cnt++;
	srand(time(NULL));
	return (rand() %100 + 1);

}

struct Node *get_node(void)
{
	struct Node *new;

	new = malloc(sizeof(struct Node));
    new->data = get_data();
    printf("\nAdding new data at front: %d\n\n", new->data);

	return new;
}
