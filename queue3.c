// Linked list implementation of a queue
// We must track the address of the tail/rear, so that we can Enqueue/Insert in O(1) time

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head;
Node *tail;


#include "print.h"

void Enqueue(int x);
void Dequeue();
bool IsEmpty();

int main(void)
{
    head = NULL; // Dequeue
    tail = NULL; // Enqueue
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Dequeue();

    printList(head);
    
    return 0;
}

void Enqueue(int x)
{
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = NULL;
    if (IsEmpty())
    {    
        tail = temp;
        head = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
}

void Dequeue()
{
    if (IsEmpty())
    {
        
        return;
    }
    Node *temp = head;
    head = head -> next;
    free(temp);
}


bool IsEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    return false;
}
