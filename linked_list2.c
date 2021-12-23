// Linked list implementation with locally defined head
// Inserting at the start, end and nth position
// The information of a linked list that we must keep is the address of the head node, or reference to head node.
// Node *head is NOT the head node, it is the address of the head node, i.e. a pointer to the head node.
// A more appropriate name might be Node *head_pointer.
// The head in a linked list is the first node in the list.
#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#include "print.h"


void insert_at_end(Node *head, int x); // Will not work on empty list (as currently implemented)
Node *insert_at_start(Node *head, int x); // Returns type Node* because we need to return the pointer of the new starting Node and assign it to head
void insert_at_n(Node *head, int n, int x); // Assume we get a valid position, does not handle error condition in case of invalid position

int main(void)
{
    Node *head = NULL;
    head = insert_at_start(head,1);
    insert_at_end(head,2);
    insert_at_end(head,3);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_n(head,2, -10);
    printList(head);
}

void insert_at_end(Node *head, int x) // Time complexity: O(n)
{
    Node *n = malloc(sizeof(Node));
    Node *temp = head;
    n -> data = x;
    n -> next = NULL;
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = n;
}

Node *insert_at_start(Node *head, int x) // Time complexity: O(1)
{
    Node *temp = malloc(sizeof(Node));
    temp -> data = x;
    temp -> next = head;
    return temp;
}

void insert_at_n(Node *head, int n, int x)
{
    Node *temp = malloc(sizeof(Node));

    for (int i = 0; i < n-1; i++)
    {
        head = head -> next;
    }
    temp -> data = x;
    temp -> next = head->next;
    head -> next = temp;
}
