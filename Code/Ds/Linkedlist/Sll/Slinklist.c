/*
 * File   : Slinklist.c
 * Desc   : Linkedlist APIs, Adding(fron, end, ascending, descending) delete
 * Author : Prabhat Tamrakar (mail2prbt@gmail.com)
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 5

int NodeCnt;

struct Node {
	int data;
	struct Node *next;
};

void print_list(struct Node *head)
{
	struct Node *loop = head;

	printf("\n===> List <===\n");
	while (loop) {
		printf("Data: %d\n", loop->data);
		loop = loop->next;
	}
}

void add_node(struct Node **head)
{
	struct Node *new;
	struct Node *hd = *head;

	new = malloc(sizeof(struct Node));
	new->data = ++NodeCnt;
	if (!hd) {
		new->next = NULL;
		hd = new;
	} else {
		new->next = hd;
		hd        = new;
	}
	*head = hd;
}

void create_list(struct Node **head)
{
	int i;

	for (i = 0; i < MAX_NODE; i++) {
		add_node(head);
	}
}

void reverse_list(struct Node **head)
{
	struct Node *prev, *next, *current = *head;

	prev = next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

int main(void)
{
	struct Node *head = NULL;

	create_list(&head);
	printf("------> Created list <------\n\n");
	print_list(head);
	printf("\n------> After Reverse <------\n\n");
	reverse_list(&head);
	print_list(head);

	return 0;
}
