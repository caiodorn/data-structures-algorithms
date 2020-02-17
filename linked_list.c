#include <stdio.h>
#include <stdlib.h>

struct node_st {
    int val;
    struct node_st *next;
};

typedef struct node_st node;

void printNodes(node *head);
void addNode(node *new, node **head);
node * createNode(int val);
void removeNode(int index, node **head);

int main() {
    node *head = NULL;

    int i = 5;
    while (i > 0) {
        addNode(createNode(i), &head);
        i--;
    }

    printNodes(head);

    removeNode(2, &head);
    removeNode(1, &head);
    removeNode(4, &head);
    removeNode(3, &head);

    printNodes(head);
}

void printNodes(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->next);
        current = current->next;
    }
}

node * createNode(int val) {
    node *new = (node *) malloc(sizeof(node *));
    new->val = val;
    new->next = NULL;
    return new;
}

void addNode(node *new, node **head) {
    node *current = *head;
    if (current == NULL) {
        *head = new;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void removeNode(int index, node **head) {
    if (*head != NULL) {
        node *current = *head;
        node *previous = NULL;
        int i = 1;
        for (; i < index && current != NULL; i++) {
            previous = current;
            current = current->next;
        }
        if (i == index && current != NULL) { //if index found (thus valid)
            if (current == *head) { //first node
                if (current->next != NULL) {
                    printf("Removing first node!\n\n");
                    *head = current->next;
                } else {
                    *head = NULL;
                }
            } else if (current->next != NULL) { //intermediate node
                printf("Removing intermediate node!\n\n");
                previous->next = current->next;
            } else { //last node
                printf("Removing last node!\n\n");
                previous->next = NULL;
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

