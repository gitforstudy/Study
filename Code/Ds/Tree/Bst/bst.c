#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *delete_tree(struct Node *root)
{
    if (root == NULL) {
        return root;
    }

    delete_tree(root->left);
    delete_tree(root->right);
    printf("Deleting node: %d\n", root->data);
    free(root);
    root = NULL;

    return root;
}

/* Preorder traversal is used to create a copy of the tree. Preorder
 * traversal is also used to get prefix expression on of an expression tree.
 */
void preorder(struct Node *root)
{
    if (root != NULL) {
        printf("val = %d\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Inorder traversal gives nodes in non-decreasing order. */
void inorder(struct Node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("val = %d\n", root->data);
        inorder(root->right);
    }
}

/* Postorder traversal is used to delete the tree. Postorder traversal is
 * also useful to get the postfix expression of an expression tree.
 */
void postorder(struct Node *root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("val = %d\n", root->data);
    }
}

void print_tree(struct Node *root)
{
    printf("1. PreorderInorder traverse---------------\n");
    preorder(root);
    printf("2. Inorder traverse---------------\n");
    inorder(root);
    printf("3. Postorder traverse---------------\n");
    postorder(root);
}

struct Node* new_node(int data)
{
    struct Node *node;

    node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->right = node->left = NULL;

    return node;
}

struct Node* insert_node(struct Node *root, int data)
{
    if (root == NULL) {
        return new_node(data);
    }

    if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }

    return root;
}

int main(void)
{
    struct Node *root = NULL;
    int i, data;

    i = 10;
    srand(time(NULL));
    while (i--) {
        data = rand() %50 + 1;
        root = insert_node(root, data);
    }

    print_tree(root);
    root = delete_tree(root);
    print_tree(root);
    return 0;
}
