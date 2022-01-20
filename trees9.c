// Depth-first Traversal
// Time Complexity = O(n)
// Space Complexity = O(h), h=height of tree
// h
// |-> worst case: O(n)
// |-> Best/Average: O(log n)

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "print.h"

BstNode *Insert(BstNode *root, int data);
BstNode *GetNewNode(int data);

void Preorder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root -> data);
    Preorder(root -> left);
    Preorder(root -> right);
}

void Inorder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root -> left);
    printf("%d ", root -> data);
    Inorder(root -> right);
}

void Postorder(BstNode *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root -> left);
    Postorder(root -> right);
    printf("%d ", root -> data);
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
    printf("Preorder: ");
    Preorder(root);
    printf("\n");
    printf("Inorder: ");
    Inorder(root);
    printf("\n");
    printf("Postorder: ");
    Postorder(root);
    printf("\n");
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