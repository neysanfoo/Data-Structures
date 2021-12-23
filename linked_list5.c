// Reverse a Linked List Using a Recursive Method
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

void ReverseRecursion(Node *p);

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

    printList(head);
    ReverseRecursion(head);
    printList(head);
}

void ReverseRecursion(Node *p)
{
    if (p -> next == NULL)
    {
        head = p;
        return;
    }
    ReverseRecursion(p -> next);
    Node *q = p->next;
    q -> next = p;
    p -> next = NULL;
}