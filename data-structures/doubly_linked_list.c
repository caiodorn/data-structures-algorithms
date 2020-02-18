#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node_st {
    int val;
    struct node_st *previous;
    struct node_st *next;
} node;

void printNodes(node *ref, bool isBackwards);
void addNode(node *new, node **head, node **tail);
node * createNode(int val);
void removeNode(int index, node **head);

int main() {
    node *head = NULL;
    node *tail = NULL; //keeping this reference for traversing backwards

    //creates and inserts 5 nodes
    int i = 1;
    while (i < 6) {
        addNode(createNode(i), &head, &tail);
        i++;
    }

    printNodes(head, false);
    printNodes(tail, true);

    return 0;
}

void printNodes(node *ref, bool isBackwards) {
    node *current = ref;

    if (isBackwards) {
        while (current != NULL) {
            printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->previous);
            current = current->previous;
        }
    } else {
        printf("Printing backwards... \n\n");
        while (current != NULL) {
            printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->next);
            current = current->next;
        }
    }
}

node * createNode(int val) {
    node *new = (node *) malloc(sizeof(node *));
    new->val = val;
    new->previous = NULL;
    new->next = NULL;
    return new;
}

void addNode(node *new, node **head, node **tail) {
    *tail = new;
    node *current = *head;
    if (current == NULL) {
        *head = new;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        new->previous = current;
    }
}