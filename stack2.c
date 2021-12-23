// Implementation of stack using an array

#include <stdio.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x);
void Pop();
int Top();
int isEmpty();
void Print();

int main(void)
{
    Push(1);
    Push(2);
    Push(3);
    Pop();
    Pop();
    Pop();

    Print();
}

void Push(int x)
{
    if (top == MAX_SIZE -1)
    {
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void Pop()
{
    if (top == -1)
    {
        printf("Error: No element to Pop\n");
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

int isEmpty()
{
    return (top == -1) ? 1 : 0;
}

void Print()
{
    printf("Stack: ");
    for (int i = 0; i<=top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}