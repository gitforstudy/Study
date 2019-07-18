#include "header.h"

struct Node *add_front(struct Node *hd)
{
	struct Node *new;

	new = get_node();
	if (hd == NULL) {
		new->prev = new;
		new->next = new;
	} else {
		new->prev = hd->prev;
		new->next = hd;
		hd->prev->next = new;
		hd->prev  = new;
	}

	return new;
}

void add_last(struct Node *hd)
{
	struct Node *new;

	new = get_node();
	if (hd == NULL) {
		new->prev = new;
		new->next = new;
	} else {
		hd = hd->prev;
		new->next = hd->next;
		new->prev = hd;
		hd->next->prev = new;
		hd->next = new;
	}
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
	struct Node *loop = head;

	printf("\n========list========\n");
	if (head == NULL) {
		printf("List is empty\n");
		printf("=====================\n\n");
		return;
	}
	do {
		printf("Data: %d\n", loop->data);
		loop = loop->next;
	} while (loop != head);
	printf("=====================\n\n");

	loop = head->prev;
	printf("\n======== Rev list========\n");
	do {
		printf("Data: %d\n", loop->data);
		loop = loop->prev;
	} while (loop->next != head);
	printf("=====================\n\n");
}

int main(void)
{
	struct Node *head = NULL;
	int cnt;

	menu(head);

	return 0;
}
