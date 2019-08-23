/*
 * File   : balloon-game.c
 * Desc   : It's a balloon game, based on balloon we burst in a perticuler
 *          sequence, calculating the score and printing the same.
 *          Here is explanation of game:
 *          Suppose we have 5 balloon with number 1[4], 2[3], 3[2], 4[1].
 *          Where 1, 2, 3, 4 are balloon sequence number and '[x]' is the value
 *          of balloon for score calculation.
 *          If we shoot balloon 2 so score s will be
 *          s1 = left balloon value x right balloon value => s = 4 x 2
 *          s1 = 8;
 *          Now we have balloon 1[4], 3[2], 4[1]
 *          If we shoot balloon 1, score calculation will be
 *          s2 = right balloon value (As we don't have balloon left side)
 *          s2 = 2
 *          Now we have balloon left 3[2], 4[1]
 *          If we shoot balloon 4, score calculation will be
 *          s3 = left balloon value (As we don't have balloon right side)
 *          s3 = 2
 *          Now we have balloon only one balloon left 3[2]
 *          So when we we shoot balloon 3, score calculation will be
 *          s4 = balloon value it self (As we have only one balloon left)
 *          s4 = 2
 *          Final score will be s = s1 + s2 + s3 + s4
 *          s = 8 + 2 + 2 + 2
 *          s = 14
 *
 * Author : Prabhat Tamrakar (mail2prbt@gmail.com)
 */
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
		sc += get_score(st);
		print_list();
	}

	printf("Score: %d\n", sc);
	return 0;
}
