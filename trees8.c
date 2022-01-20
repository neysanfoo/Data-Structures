// Level-Order Traversal (Breadth-first)
// Time complexity = O(n)
// Space complexity = O(n) 

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "print.h"

typedef struct QueueNode
{
    BstNode *data;
    struct QueueNode *next;
} QueueNode;


BstNode *Insert(BstNode *root, int data);
BstNode *GetNewNode(int data);

QueueNode *queueFront;
QueueNode *queueRear;

void Enqueue(BstNode *x)
{
    QueueNode *temp = malloc(sizeof(QueueNode));
    temp -> data = x;
    temp -> next = NULL;
    if (queueFront==NULL) 
    {
        queueFront = temp;
        queueRear = temp;
        return;
    }
    queueRear -> next = temp;
    queueRear = queueRear -> next;
}

void Dequeue()
{
    QueueNode *temp = queueFront;
    queueFront = queueFront -> next;
    free(temp);
}

void LevelOrder(BstNode *root)
{
    if (root == NULL) return;
    Enqueue(root);
    while (queueFront != NULL)
    {
        BstNode *temp = queueFront -> data;
        printf("%d ", temp ->data);
        if (temp -> left != NULL)
            Enqueue(temp -> left);
        if (temp -> right != NULL)
            Enqueue(temp -> right);
        Dequeue();
    }
    printf("\n");
}

int main(void)
{
    queueFront = NULL;
    queueRear = NULL;
    BstNode *root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 11);
    root = Insert(root, 12);
    printBST(root,0);
    LevelOrder(root);
    return 0;
}


BstNode *Insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(data <= root -> data)
    {
        root -> left = Insert(root -> left, data);
    }
    else
    {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

BstNode *GetNewNode(int data)
{
    BstNode *newNode = malloc(sizeof(BstNode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}