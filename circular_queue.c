#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int front;
    int back;
    int items[MAX];
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

    int i = 5;
    while (!isFull(q)) {
        enqueue(i, q);
        i--;
    }

    dequeue(q);
    dequeue(q);

    i = 5;
    while (!isFull(q)) {
        enqueue(i, q);
        i--;
    }

    dequeue(q);
    dequeue(q);
    dequeue(q);

    i = 5;
    while (!isFull(q)) {
        enqueue(i, q);
        i--;
    }

    while (!isEmpty(q)) {
        dequeue(q);
    }

    return 0;
}

void initialize(queue *q) {
    q->front = -1;
    q->back = -1;
}

bool isFull(queue *q) {
    bool isFull = (q->back == MAX - 1 && q->front == 0) || q->back == q->front - 1;
    if (isFull) {
        printf("Queue is full!\n");
    }
    return isFull;
}

void enqueue(int item, queue *q) {
    if (!isFull(q)) {
        if (isEmpty(q)) {
            q->front++;
        }
        q->back = (q->back + 1) % MAX;
        q->items[q->back] = item;
        printf("Enqueued element {%d} at index {%d}\n", item, q->back);
    }
}

void dequeue(queue *q) {
    if (!isEmpty(q)) {
        printf("Dequeued element {%d} from index {%d}\n", q->items[q->front], q->front);
        if (hasOneLeft(q)) {
            initialize(q);
        } else {
            q->front = (q->front + 1) % MAX;
        }
    }
    printf("Front index -> %d, Back index -> %d\n", q->front, q->back);
}

bool isEmpty(queue *q) {
    return q->back == -1;
}

bool hasOneLeft(queue *q) {
    return q->front == q->back;
}
