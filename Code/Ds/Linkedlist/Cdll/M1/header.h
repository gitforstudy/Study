/*
 * Prog   : Circuler linked list
 * Author : Prabhat Tamrakar (mail2prbt@gmail.com)
 *
 */

#ifndef  __HEADER__
#define __HEADER__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void menu(struct Node *head);
int get_data(void);
struct Node *get_node(void);

void add_front(struct Node *head);
void add_last(struct Node *head);
struct Node *add_mid(struct Node *head);
struct Node *add_last2(struct Node *head);
struct Node *add_sel(struct Node *head);
struct Node *del_front(struct Node *head);
struct Node *del_last(struct Node *head);
struct Node *del_mid(struct Node *head);
struct Node *del_last2(struct Node *head);
struct Node *del_sel(struct Node *head);
struct Node *update_front(struct Node *head);
struct Node *update_last(struct Node *head);
struct Node *update_mid(struct Node *head);
struct Node *update_last2(struct Node *head);
struct Node *update_sel(struct Node *head);
struct Node *reverse_list(struct Node *head);
struct Node *sort_list(struct Node *head);
void print_list(struct Node *head);

#endif
