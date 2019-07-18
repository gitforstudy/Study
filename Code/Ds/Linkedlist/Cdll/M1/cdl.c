#include "header.h"

void add_front(struct Node *head)
{
	struct Node *new, *fst = head;

	new = get_node();
	new->next = fst->next;
	new->prev = fst;
	fst->next->prev = new;
	fst->next = new;
}

void add_last(struct Node *head)
{
	add_front(head->prev);
}

struct Node *add_mid(struct Node *head)
{

}

struct Node *add_last2(struct Node *head)
{

}

struct Node *add_sel(struct Node *head)
{

}

struct Node *del_front(struct Node *head)
{

}

struct Node *del_last(struct Node *head)
{

}

struct Node *del_mid(struct Node *head)
{

}

struct Node *del_last2(struct Node *head)
{

}

struct Node *del_sel(struct Node *head)
{
/*	struct Node *local = dn->prev;

	local->next = dn->next;
	dn->next->prev = dn->prev;

	free(dn);*/
}

struct Node *update_front(struct Node *head)
{

}

struct Node *update_last(struct Node *head)
{

}

struct Node *update_mid(struct Node *head)
{

}

struct Node *update_last2(struct Node *head)
{

}

struct Node *update_sel(struct Node *head)
{
}

struct Node *reverse_list(struct Node *head)
{
}

struct Node *sort_list(struct Node *head)
{
}

void print_list(struct Node *head)
{
	struct Node *loop = head->next;

	printf("\n========list========\n");
	while (loop != head) {
		printf("Data: %d\n", loop->data);
		loop = loop->next;
	}
	printf("=====================\n\n");

	loop = head->prev;
	printf("\n======== Rev list========\n");
	while (loop != head) {
		printf("Data: %d\n", loop->data);
		loop = loop->prev;
	}
	printf("=====================\n\n");
}

int main(void)
{
	struct Node head;
	int cnt;

	head.next = &head;
	head.prev = &head;
	menu(&head);

	return 0;
}
