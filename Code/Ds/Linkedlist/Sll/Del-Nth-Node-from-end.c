/* Prog: Delete nth node from end */

#include <stdio.h>
#include <stdlib.h>

struct st {
	int data;
	struct st *next;
};

static int NodeCnt = 1;

void PrintNode(struct st *node)
{
	int cnt;

	printf("\n---------------------------\n");
	if (node == NULL) {
		printf("No records available\n");
		printf("---------------------------\n");
		return;
	}
	cnt = 1;
	while (node) {
		printf("%2d. Data: %d\n", cnt ++, node->data);
		node = node->next;
	}
	printf("---------------------------\n");
}

struct st *AddNode(struct st *head)
{
	struct st *temp;
	struct st *node = head;

	if (!node) {
		node = malloc(sizeof(struct st));
		node->data = NodeCnt ++;
		node->next = NULL;
		return node;
	}

	while (node->next) {
		node = node->next;
	}

	temp = malloc(sizeof(struct st));
	temp->data = NodeCnt ++;
	temp->next = NULL;
	node->next = temp;

	return head;
}

struct st *DeleteNode(struct st *head, int delnode)
{
	struct st *node = head;
	struct st *temp;

	delnode --;
	while (node->next && --delnode) {
		node = node->next;
	}

	temp = node->next;
	node->next = temp->next;
	free(temp);
	NodeCnt --;

	return head;
}

struct st *DeleteLastNthNode(struct st *head, int n)
{
	struct st *loop = head;
	struct st *node;

	node = head;
	while (loop) {
		if (n + 1) {
			loop = loop->next;
			n --;
			continue;
		}
		loop = loop->next;
		node = node->next;
	}

	/* Invalid node requested for deletion */
	if (n > 0) {
		printf("\nInvalid input\n");
		return head;
	}

	/* Delete last node from end */
	if (node == head && (n + 1)) {
		head = node->next;
		free(node);
	} else {
		/* Delete nth node from end */
		loop = node->next;
		node->next = loop->next;
		free(loop);
	}

	NodeCnt --;

	return head;
}

int main(void)
{
	struct st *head = NULL;
	int c, n;

	while (1) {
		printf("0. Print node(s)\n1. Add node\n2. Delete node\n3. Delete last but nth node\n");
		printf("Select any one option: ");
		scanf("%d", &c);
		fflush(stdin);

		switch (c) {
			case 0:
				PrintNode(head);
				break;
			case 1:
				head = AddNode(head);
				break;
			case 2:
				printf("Enter node no. to be deleted: ");
				scanf("%d", &n);
				head = DeleteNode(head, n);
				break;
			case 3:
				printf("Enter node no. to be deleted from last: ");
				scanf("%d", &n);
				head = DeleteLastNthNode(head, n);
				break;
			default:
				printf("Invalid option\n");
		}
	}

	return 0;
}
