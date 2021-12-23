// Doubly Linked List
// Globally defined head
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

#include "print.h"

struct Node *head;

Node *getNewNode(int x);
void insertAtHead(int x);

int main(void)
{
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtHead(4);
    printDouble(head);
    printReverseDouble(head);
    return 0;
}

Node *getNewNode(int x)
{
    Node *newNode = malloc(sizeof(Node));
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

void insertAtHead(int x)
{
    Node *newNode = getNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head -> prev = newNode;
    newNode -> next = head;
    head = newNode;
}