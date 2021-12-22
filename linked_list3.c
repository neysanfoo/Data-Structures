// Linked list implementation with globally defined head
// Inserting at nth position and deleting at nth postion (starting from 0).

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#include "print.h"

Node *head;

void insert_at_n(int n, int x);
void delete_at_n(int n);

int main(void)
{
    head = NULL;
    insert_at_n(0,2);  // List: 2
    insert_at_n(1,3);  // List: 2, 3
    insert_at_n(1,4);  // List: 2, 4, 3
    insert_at_n(2,5);  // List: 2, 4, 5, 3
    delete_at_n(0);    // List: 4, 5, 3
    delete_at_n(2);    // List: 4, 5
    printList(head);
    
}

void insert_at_n(int n, int x)
{
    Node *new_node = malloc(sizeof(Node));
    new_node -> data = x;
    new_node -> next = NULL;
    if (n == 0)
    {
        new_node -> next = head;
        head = new_node;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < n-1; i++)
    {
        temp = temp -> next;
    }
    new_node -> next = temp -> next;
    temp -> next = new_node;
}

void delete_at_n(int n)
{
    if (n==0)
    {
        head = head -> next;
        return;
    }
    Node *temp = head;
    for (int i = 0; i < n-1; i++)
    {
        temp = temp -> next;
    }
    // temp points to (n-1)th node
    Node *temp2 = temp -> next; // we make temp2 to clear memory in heap of the deleted node
    temp -> next = temp2 -> next;
    free(temp2);
}