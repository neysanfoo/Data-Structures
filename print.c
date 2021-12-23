#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("(%p, %p) --> ", &head, head);
    while (head->next != NULL)
    {
        printf("(%p, %d, %p) --> ", head, head->data, head->next);
        head = head -> next;
    }
    printf("(%p, %d, %p)", head, head->data, head->next);
    printf("\n");
}

// Print Linked List Using Recursion
void printListRecursively(Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    } 
    printf("(%p, %d, %p) --> ", head, head->data, head->next);
    printListRecursively( head -> next);
}

// Print Reverse of Linked List Using Recursion
void printReverseListRevursively(Node *head)
{
    if (head == NULL)
    {
        return;
    } 
    printReverseListRevursively( head -> next);
    printf("(%p, %d, %p) --> ", head, head->data, head->next);
}

// Print Doubly Linked List
void printDouble(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (head -> next != NULL)
    {
        printf("(%p, %d, %p) <--> ", head->prev, head->data, head->next);
        head = head -> next;
    }
    printf("(%p, %d, %p)", head->prev, head->data, head->next);
    printf("\n");
}

// Print Reverse of Doubly Linked List
void printReverseDouble(Node *head)
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }
    while (head ->next != NULL)
    {
        head = head -> next;
    }
    // Traversing backwards
    while (head -> prev != NULL)
    {
        printf("(%p, %d, %p) <--> ", head->next, head->data, head->prev);
        head = head -> prev;
    }
    printf("(%p, %d, %p)", head->next, head->data, head->prev);
    printf("\n");
}