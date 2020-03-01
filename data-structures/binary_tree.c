#include <stdlib.h>
#include <stdio.h>

struct node_st {
    int data;
    struct node_st *left;
    struct node_st *right;
};

typedef struct node_st node;

node * createNode(int data);
void insertNode(node *new, node **root);

void insertLeft(node *new, node *const *root);

void insertRight(node *new, node *const *root);

int main() {
    node *root = NULL;

    insertNode(createNode(5), &root);
    insertNode(createNode(10), &root);
    insertNode(createNode(3), &root);
    insertNode(createNode(4), &root);
    insertNode(createNode(1), &root);
    insertNode(createNode(4), &root); // should result in error msg

    return 0;
}

node * createNode(int data) {
    node *n = (node *) malloc(sizeof(node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void insertNode(node *new, node **root) {
    if (*root == NULL) {
        *root = new;
        printf("Inserted node %d in root position\n\n", new->data);
    } else {
        if (new->data < (*root)->data) {
            insertLeft(new, root);
        } else if (new->data > (*root)->data) {
            insertRight(new, root);
        } else {
            printf("Data must be unique, try again with different data\n\n");
        }
    }
}

void insertRight(node *new, node *const *root) {
    if ((*root)->right == NULL) {
        (*root)->right = new;
        printf("Inserted node %d to the right of node %d\n\n", new->data, (*root)->data);
    } else {
        printf("Traversing to the right of node %d\n\n", (*root)->data);
        insertNode(new, &(*root)->right);
    }
}

void insertLeft(node *new, node *const *root) {
    if ((*root)->left == NULL) {
        (*root)->left = new;
        printf("Inserted node %d to the left of node %d\n\n", new->data, (*root)->data);
    } else {
        printf("Traversing to the left of node %d\n\n", (*root)->data);
        insertNode(new, &(*root)->left);
    }
}