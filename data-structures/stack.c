#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} stack;

void initialize(stack *s);
bool isEmpty(stack *s);
int pop(stack *s);
bool isFull(stack *s);
void push(int item, stack *s);

int main() {
    stack *s;
    initialize(s);

    int item = 10;

    //fill stack
    while (!isFull(s)) {
        push(item, s);
        item++;
    }

    //empty stack
    while (!isEmpty(s)) {
        pop(s);
    }

    return 0;
}

void initialize(stack *s) {
    s->top = -1;
}

bool isEmpty(stack *s) {
    return s->top == -1;
}

int pop(stack *s) {
    if (!isEmpty(s)) {
        printf("Removing item {%d} from stack at index {%d}!\n", s->items[s->top], s->top);
        s->top--;
    } else {
        puts("Stack is empty!");
    }
}

bool isFull(stack *s) {
    return s->top == MAX - 1;
}

void push(int item, stack *s) {
    if (!isFull(s)) {
        s->top++;
        printf("Adding item {%d} at index {%d} of the stack!\n", item, s->top);
        s->items[s->top] = item;
    } else {
        puts("Stack is full!");
    }
}

