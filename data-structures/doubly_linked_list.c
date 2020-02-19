#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_st {
    int val;
    struct node_st *previous;
    struct node_st *next;
};

typedef struct node_st node;

void printNodes(node *ref, bool isBackwards);
void addNode(node *new, node **head, node **tail);
node * createNode(int val);
void removeNode(int index, node **head, node **tail);

int main() {
    node *head = NULL;
    node *tail = NULL; //for traversing backwards

    //creates and inserts 5 nodes
    int i = 1;
    while (i < 6) {
        addNode(createNode(i), &head, &tail);
        i++;
    }

    printNodes(head, false);
    printNodes(tail, true);

    removeNode(1, &head, &tail);
    removeNode(4, &head, &tail);
    removeNode(2, &head, &tail);
    printNodes(head, false);

    return 0;
}

void printNodes(node *ref, bool isBackwards) {
    node *current = ref;

    if (isBackwards) {
        printf("Printing backwards... \n\n");
        while (current != NULL) {
            printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->previous);
            current = current->previous;
        }
    } else {
        while (current != NULL) {
            printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->next);
            current = current->next;
        }
    }
}

node * createNode(int val) {
    node *new = (node *) malloc(sizeof(node));
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

void removeNode(int index, node **head, node **tail) {
    if (*head != NULL) {
        node *current = *head;
        int i = 1;
        for (; i < index && current != NULL; i++) {
            current = current->next;
        }
        if (i == index && current != NULL) { //if index found (thus valid)
            if (current == *head) { //first node
                printf("Removing first node!\n\n");
                if (current->next != NULL) {
                    current->previous = NULL;
                    *head = current->next;
                    *tail = *head;
                } else {
                    *head = NULL;
                    *tail = NULL;
                    printf("List is now empty!\n\n");
                }
            } else if (current->next != NULL) { //intermediate node
                printf("Removing intermediate node!\n\n");
                current->previous->next = current->next;
                current->next->previous = current->previous;
                *tail = current->next;
            } else { //last node
                printf("Removing last node!\n\n");
                current->previous->next = NULL;
                *tail = current->previous;
            }
            free(current);
            printf("Removed Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->next);
        } else {
            printf("Index not found!\n\n");
        }
    } else {
        printf("List has no nodes!\n\n");
    }
}