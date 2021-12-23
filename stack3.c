// Implementation of stack using a linked list
// We will insert and delete from beginning of the linked list rather than the end
// Insert / Delete from linked list
// 1) At end: O(n) ✗
// 2) At beginning: O(1) ✓

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

#include "print.h"

Node *top;
void Push(int x);
void Pop();

int main(void)
{
    top = NULL;
    Push(2);
    Push(5);
    Push(-2);
    Push(10);
    Push(15);
    Pop();

    printList(top);
}

void Push(int x)
{
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = top;
    top = temp;
}

void Pop()
{
    if (top == NULL) return;
    Node *temp = top;
    top = top -> next;
    free(temp);
}