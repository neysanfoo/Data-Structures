// Using stack to reverse a linked list

#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

#include "print.h"

Node *head;

void Reverse(Node *p);


int main(void)
{
    head = NULL;
    Node *temp = (Node *) malloc(sizeof(Node));
    temp -> data = 1;
    temp -> next = NULL;
    head = temp;

    temp = (Node *) malloc(sizeof(Node));
    temp -> data = 2;
    temp -> next = NULL;
    head -> next = temp;

    temp = (Node *) malloc(sizeof(Node));
    temp -> data = 3;
    temp -> next = NULL;
    head -> next -> next = temp;

    printList(head);

    Reverse(head);

    printList(head);
}

void Reverse(Node *p)
{
    Node *temp = p;
    stack<Node*> S;
    while (temp != NULL)
    {
        S.push(temp);
        temp = temp -> next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp -> next = S.top();
        S.pop();
        temp = temp -> next;
    }
    temp -> next = NULL;

}