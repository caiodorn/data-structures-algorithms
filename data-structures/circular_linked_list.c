#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
    int val;
    struct node_st *next;
} node;

void printNodes(node *head);
void addNode(node *new, node **head);
node * createNode(int val);
void removeNode(int index, node **head);
void removeFirst(node *current, node **head);

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

    removeNode(3, &head);
    removeNode(2, &head);
    removeNode(1, &head);

    printNodes(head);
}

void printNodes(node *head) {
    if (head == NULL) {
        printf("List is empty!\n\n");
    } else {
        node *current = head;
        while (current != NULL) {
            printf("Addr: %p\nVal: %d\nNext: %p\n\n", current, current->val, current->next);
            if (current->next == head) {
                break;
            }
            current = current->next;
        }
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
        new->next = new;
        *head = new;
    } else {
        while (current->next != *head) {
            current = current->next;
        }
        new->next = *head;
        current->next = new;
    }
}

void removeNode(int index, node **head) {
    if (*head != NULL) {
        node *current = *head;
        node *previous = NULL;
        int i = 1;
        for (; i < index && current->next != *head; i++) {
            previous = current;
            current = current->next;
        }
        if (i == index) {                        //if index found (thus valid)
            if (current == *head) {              //if first node
                removeFirst(current, head);
            } else if (current->next != *head) { //if intermediate node
                printf("Removing intermediate node!\n\n");
                previous->next = current->next;
            } else {                             //if last node
                printf("Removing last node!\n\n");
                previous->next = *head;
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

void removeFirst(node *current, node **head) {
    if (current->next != *head) {
        printf("Removing first node!\n\n");
        node *last = current;
        while (last->next != *head) { //navigate to last node...
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;           //make it point to the updated head ref
    } else {                          //is last remaining node
        *head = NULL;
        printf("List is now empty!\n\n");
    }
}
