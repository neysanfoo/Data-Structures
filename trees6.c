// Find Height of a BST
// Height of Tree = Number of edges in longest path from root to a leaf node
// Implement FindHeight
#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "print.h"

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
    __typeof__ (b) _b = (b); \
    _a > _b ? _a : _b; })

BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);

int FindHeight(BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int leftHeight = FindHeight(root -> left);
    int rightHeight = FindHeight(root -> right);
    return max(leftHeight, rightHeight) + 1;
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
    printf("%d\n",FindHeight(root));
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