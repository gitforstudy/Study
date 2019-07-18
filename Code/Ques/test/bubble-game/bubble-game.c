#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int sn;
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node head;
static int cnt = 1;

void print_list(void)
{
    struct Node *loop = head.next;

    printf("\n========list========\n");
    while (loop != &head) {
        printf("sn: %d Data: %d\n", loop->sn, loop->data);
        loop = loop->next;
    }
    printf("=====================\n\n");
}

void add_node(struct Node *hd)
{
	int bval;
	struct Node *new;

	printf("balloon value: ");
	scanf("%d", &bval);

	new = malloc(sizeof(struct Node));
	new->sn = cnt++;
	new->data = bval;
	new->next = hd->next;
	new->prev = hd;
	hd->next->prev = new;
	hd->next = new;
}

void add_balloon(void)
{
	add_node(head.prev);
}

void feed_balloon_value(int bn)
{
	int i;

	/* loop1: balloons */
	for (i = 0; i < bn; i++) {
		add_balloon();
	}
}

int shoot_balloon(struct Node *dn)
{
	struct Node *local = dn->prev;
	int bval = dn->data;

	local->next = dn->next;
	dn->next->prev = dn->prev;
	free(dn);

	return bval;
}


struct Node *get_target_balloon(int st)
{
	struct Node *loop = head.next;

	while (loop != &head) {
		if (loop->sn == st) {
			return loop;
		}
		loop = loop->next;
	}

	return &head;
}

int get_score(int st)
{
	int score, bval;
	struct Node *bl;

	bl = get_target_balloon(st);

	/* I think this case should never come */
	if (bl == &head) {
		return 0;
	}
	/* case 1: There is only one balloon */
	if ((bl->prev == &head) && (bl->next == &head)) {
		bval = shoot_balloon(bl);
	} else if (bl->prev == &head) { /* case 2: No balloons left on left side of target balloon */
		bval = bl->next->data;
		shoot_balloon(bl);
	} else if (bl->next == &head) {
		bval = bl->prev->data;
		shoot_balloon(bl);
	} else {
		bval = (bl->prev->data * bl->next->data);
		shoot_balloon(bl);
	}

	return bval;
}

int main(void)
{
	int bal, st, i, sc;

	head.prev = &head;
	head.next = &head;

	printf("Enter no. of balloon: ");
	scanf("%d", &bal);

	feed_balloon_value(bal);
	print_list();
	sc = 0;
	/* loop2: Shoot balloons */
	for (i = 0; i < bal; i++) {
		printf("Shoot balloon: ");
		fflush(stdin);
		scanf("%d", &st);
		print_list();
		sc += get_score(st);
	}

	printf("Score: %d\n", sc);
	return 0;
}
