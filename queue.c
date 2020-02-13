#include <stdbool.h>
#include <stdio.h>

#define MAX 5

typedef struct {
    int elems[MAX];
    int front;
    int back;
} queue;

void initialize(queue *q);
void enqueue(int elem, queue *q);
bool isFull(queue *q);
void dequeue(queue *q);
bool isEmpty(queue *q);
bool hasOneLeft(queue *q);

int main() {
    queue *q;

    initialize(q);

    int i = 0;

    //add
    while (i < MAX) {
        enqueue(i, q);
        i++;
    }

    //remove
    while (i % MAX != 5) {
        dequeue(q);
    }

    return 0;
}

void initialize(queue *q) {
    q->back = -1;
    q->front = -1;
}

void enqueue(int elem, queue *q) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front = 0;
        }
        printf("Enqueuing element {%d} at position {%d}\n", elem, q->back + 1);
        q->elems[++q->back] = elem;
    }
}

bool isFull(queue *q) {
    return q->back == MAX - 1;
}

void dequeue(queue *q) {
    if (!isEmpty(q)) {
        printf("Dequeuing element {%d} from position {%d}\n", q->elems[q->front], q->front);
        if (hasOneLeft(q)) {
            initialize(q);
        } else {
            q->front++;
        }
    }
}


bool isEmpty(queue *q) {
    return q->back == -1;
}

bool hasOneLeft(queue *q) { return q->front == q->back; }
