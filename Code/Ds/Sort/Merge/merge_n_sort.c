#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

void print_list(struct Node* head)
{
    struct Node* d = head;

    if (d == NULL) {
        printf("\nList is empty!\n");
        return;
    }

    int i = 1;
    while (d) {
        printf("%2d. val = %d\n", i++, d->data);
        d = d->next;
    }
}

void add_node(struct Node** head, int val)
{
    struct Node* new;

    new = malloc(sizeof(struct Node));
    new->data = val;
    new->next = *head;
    *head = new;
}

void prepare_list(struct Node** head, int cnt)
{
    int val;

    srand(time(NULL));
    while (cnt--) {
        val = rand() %100 + 1;
        add_node(head, val);
    }
}

struct Node* sort_merge(struct Node* a, struct Node* b)
{
    struct Node* res = NULL;

    if (a == NULL) {
        return b;
    } else if (b == NULL) {
        return a;
    }

    if (a->data <= b->data) {
        res = a;
        res->next = sort_merge(a->next, b);
    } else {
        res = b;
        res->next = sort_merge(a, b->next);
    }

    return (res);
}

void split_list(struct Node* hd, struct Node** b)
//void split_list(struct Node* hd, struct Node** a, struct Node** b)
{
    struct Node* fast, *slow;

    fast = hd->next; slow = hd;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }

//    *a = hd;
    *b = slow->next;
    slow->next = NULL;
}

void mergesort(struct Node** list)
{
    struct Node* hr = *list;
    struct Node* a, *b;

    if (hr == NULL || hr->next == NULL) {
        return;
    }

    a = hr;
    split_list(*list, &b);
//    split_list(hr, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *list = sort_merge(a, b);
}

int main(void)
{
    /* head pointer initialize with NULL is mandatory other wise add new node
     * will through segfault */
    struct Node* h1 = NULL;
    struct Node* h2 = NULL;
    struct Node* res;

    prepare_list(&h1, 10);
    prepare_list(&h2, 15);
    printf("-------------List 1-------------\n");
    print_list(h1);
    printf("-------------List 2-------------\n");
    print_list(h2);
    mergesort(&h1);
    mergesort(&h2);
    res = sort_merge(h1, h2);
    printf("-------------After sorting-------------\n");
    print_list(res);
    return 0;
}
