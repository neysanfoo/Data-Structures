// Reverse a Linked List Using an Iterative Method
// Globally defined head

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#include "print.h"

Node *head;

void Reverse();


int main(void)
{
    head = NULL;
    Node *temp = malloc(sizeof(Node));
    temp -> data = 1;
    temp -> next = NULL;
    head = temp;

    temp = malloc(sizeof(Node));
    temp -> data = 2;
    temp -> next = NULL;
    head -> next = temp;

    temp = malloc(sizeof(Node));
    temp -> data = 3;
    temp -> next = NULL;
    head -> next -> next = temp;

    printListRecursively(head);
    Reverse();
    printReverseListRevursively(head);
}

void Reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}