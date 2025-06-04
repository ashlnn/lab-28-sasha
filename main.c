#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 20
typedef struct {
    int data[SIZE];
    int front, rear;
} Queue;
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear < SIZE - 1)
        q->data[++(q->rear)] = value;
}
int dequeue(Queue *q) {
    if (q->front <= q->rear)
        return q->data[(q->front)++];
    return 0;
}
int isQueueEmpty(Queue *q) {
    return q->front > q->rear;
}
void printQueue(Queue *q, const char *name) {
    printf("%s: ", name);
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->data[i]);
    printf("\n");
}
int main() {
    Queue q, evenQ, oddQ;
    initQueue(&q);
    initQueue(&evenQ);
    initQueue(&oddQ);

    int n, x;
    printf("Скільки чисел у черзі? ");
    scanf("%d", &n);
    printf("Введіть %d чисел:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    while (!isQueueEmpty(&q)) {
        x = dequeue(&q);
        if (x % 2 == 0)
            enqueue(&evenQ, x);
        else
            enqueue(&oddQ, x);
    }

    printQueue(&evenQ, "Парні числа");
    printQueue(&oddQ, "Непарні числа");

    getch();
    return 0;
}
