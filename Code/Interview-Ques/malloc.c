/*
 * File   : malloc.c
 * Desc   : Implementation of malloc
 * Author : Prabhat Tamrakar (mail2prbt@gmail.com)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mdata {
	void *saddr;
	int size;
	struct mdata *next;
};

struct mdata *mtable;
void *buff;

void init_malloc(void)
{
	buff = calloc(1000, 10);
}

void * add_entry(struct mdata *node, int size)
{
	struct mdata *new;

	new = malloc(sizeof(struct mdata));
	new->size  = size;
	if (node == NULL) {
		new->saddr = buff;
		new->next  = NULL;
		mtable     = new;
	} else {
		//printf("node->saddr : %d, node->size : %d\n", node->saddr, node->size);
		new->saddr = node->saddr + node->size;
		//printf("new->saddr : %d\n", new->saddr);
		new->next  = node->next;
		node->next = new;
	}

	return new->saddr;
}

void * mymalloc(int size)
{
	struct mdata *loop = mtable;
	int offset, cnt;

	if (size < 0) {
		return NULL;
	}

	cnt = 1;
	while (loop) {
		//printf("Iteration: %d\n", cnt++);
		if (loop->next) {
			offset = loop->next->saddr - loop->saddr;
			printf("offset = %d\n", offset);
			if (offset != loop->size) {
				if (size <= offset) {
					break;
				}
			}
		} else {
			break;
		}

		loop = loop->next;
	}

	return add_entry(loop, size);
}

void update_mtable(struct mdata *node)
{
	struct mdata *temp = node->next;

	node->next = temp->next;
	free(temp);
}

void myfree(void *saddr)
{
	struct mdata *temp = mtable;
	struct mdata *loop;

	if (temp->saddr == saddr) {
		temp->size = 0;
		return;
	}

	loop = temp->next;
	while (loop) {
		if (loop->saddr == saddr) {
			update_mtable(temp);
			break;
		}
		temp = loop;
		loop = loop->next;
	}
}

int main(int argc, char *argv[])
{
	char *p, *q, *s, *t;
	int *i;

	init_malloc();
	//printf("Allocating 10 bytes\n");
	p = (char *) mymalloc(10);
	printf("p = %d\n", p);
	printf("\nAllocating 5 x 4 = 20 bytes\n");
	i = (int *) mymalloc(sizeof(int) * 5);
	printf("i = %d\n", i);
	printf("\nAllocating 8 bytes\n");
	q = (char *) mymalloc(8);
	printf("q = %d\n", q);
	printf("\nFree i, 20 bytes\n");
	myfree(i);
	printf("\nAllocating 3 x 4 = 15 bytes\n");
	i = (int *) mymalloc(sizeof(int) * 3);
	printf("i = %d\n", i);
	printf("\nAllocating 30 bytes\n");
	s = (char *) mymalloc(30);
	printf("s = %d\n", s);
	printf("\nAllocating 5 bytes\n");
	t = (char *) mymalloc(5);
	printf("t = %d\n", t);
	printf("\nFree p, 10 bytes\n");
	myfree(p);
	printf("\nAllocating 6 bytes\n");
	p = (char *) mymalloc(6);
	printf("p = %d\n", p);

	return 0;
}
