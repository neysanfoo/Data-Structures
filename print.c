#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
    }
    else{
        printf("(%p, %p) --> ", &head, head);
        while (head->next != NULL)
        {
            printf("(%p, %d, %p) --> ", head, head->data, head->next);
            head = head -> next;
        }
        printf("(%p, %d, %p)", head, head->data, head->next);
        printf("\n");
    }
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
