// Array implementation of a queue

#include <stdio.h>
#include <stdbool.h>

int front = -1;
int rear = -1;
int A_SIZE = 10;
int A[10];

bool IsEmpty();
void Enqueue(int x);
void Dequeue();


int main(void)
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(5);
    Dequeue();
    Enqueue(9);
    for (int i = front; i <= rear ; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(int x)
{
    if (rear == A_SIZE -1)
    {
        printf("Queue is full");
        return;
    }
    else if (IsEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    A[rear] = x;
}

void Dequeue()
{
    if (IsEmpty())
    {
        return;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}