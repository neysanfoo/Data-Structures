// Check if a given Binary Tree is BST
// Slow solution (Time Complexity O(n^2))
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print.h"


BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);

bool IsSubtreeLesser(BstNode *root, int value)
{
    if (root == NULL) return true;
    if (root -> data <= value 
        && IsSubtreeLesser(root -> left, value)
        && IsSubtreeLesser(root -> right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(BstNode *root, int value)
{
    if (root == NULL) return true;
    if (root -> data > value 
        && IsSubtreeGreater(root -> left, value)
        && IsSubtreeGreater(root -> right, value))
        return true;
    else
        return false;
}


bool IsBinarySearchTree(BstNode *root)
{
    if (root == NULL) return true;
    if (IsSubtreeLesser(root -> left, root -> data)
        && IsSubtreeGreater(root->right, root->data)
        && IsBinarySearchTree(root->left)
        && IsBinarySearchTree(root->right))
        return true;
    else
        return false;
}

int main(void)
{
    BstNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,20);
    root = Insert(root,20);
    root = Insert(root,12);
    root = Insert(root,55);
    printBST(root,0);
    printf("%s\n", IsBinarySearchTree(root) ? "true" : "false");
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
