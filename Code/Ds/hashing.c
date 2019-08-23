/*
 * File   : hashing.c
 * Desc   : Find a unique no. from given array. Hashing mechanism used here
 *          so the complexity will be
 * Author : Prabhat Tamrakar (mail2prbt@gmail.com)
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE(a) sizeof(a)/sizeof(a[0])

struct st {
	int data;
	int key;
	struct st *next;
};

struct st *hash, *tail;

void insert(int data)
{
	struct st *new, *loop = hash;

	while (loop) {
		if (loop->data == data) {
			loop->key ++;
			return;
		} else if (loop->data > data) {
		}
		tail = loop;
		loop = loop->next;
	}

	new = malloc(sizeof(struct st));
	new->data = data;
	new->key  = 1;

	if (tail) {
		new->next  = NULL;
		tail->next = new;
		return;
	} else {
		new->next = hash;
		hash = new;
		tail = new;
	}
}

void display_hashtable(void)
{
	struct st *loop = hash;
	int key;

	printf("\n===> Hash table data <===\n");
	while (loop) {
		key = loop->key;
		while (key--)
			printf("Data: %d\n", loop->data);
		loop = loop->next;
	}
}

int find_unique_num(void)
{
	struct st *loop = hash;

	if (loop && loop->key == 1) {
		return loop->data;
	}

	return -1;
}

int main(void)
{
	int i, unum;
	char arr[10] = {3, 3, 3, 1, 2, 2, 6, 6, 6, 6};

	for (i = 0; i < SIZE(arr); i++) {
		insert(arr[i]);
	}

	display_hashtable();
	unum = find_unique_num();
	printf("Unique Number : %d\n", unum);
}
