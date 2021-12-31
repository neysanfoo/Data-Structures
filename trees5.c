// Implement FindMin and FindMax using Recursion
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "print.h"

BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);


int FindMin(BstNode *root)
{
    if (root -> left == NULL)
    {
        return root -> data;
    }
    return FindMin(root -> left);
}

int FindMax(BstNode *root)
{
    if (root -> right == NULL)
    {
        return root -> data;
    }
    return FindMax(root -> right);
}

int main(void)
{
    BstNode *root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 8);
    root = Insert(root, 9);
    root = Insert(root, 7);
    root = Insert(root, 11);
    root = Insert(root, 12);
    printBST(root,0);
    printf("%d\n", FindMin(root));
    printf("%d\n", FindMax(root));
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