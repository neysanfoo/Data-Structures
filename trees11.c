// Check if a given Binary Tree is BST
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print.h"


BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);


bool IsBinarySearchTree(BstNode *root)
{
    static int prev = 0; // Only works for BST with positive values
    if (root == NULL) return true;
    IsBinarySearchTree(root -> left);
    if (root -> data < prev)
    {
        return false;
    }
    prev = root -> data;
    IsBinarySearchTree(root -> right);
    return true;
}

int main(void)
{
    BstNode *root = NULL;
    BstNode *temp = malloc(sizeof(BstNode));
    temp -> data = 4;
    temp -> left = NULL;
    temp -> right = NULL;
    root = temp;

    temp = malloc(sizeof(BstNode));
    temp -> data = 3;
    temp -> left = NULL;
    temp -> right = NULL;
    root -> left = temp;

    temp = malloc(sizeof(BstNode));
    temp -> data = 5;
    temp -> left = NULL;
    temp -> right = NULL;
    root -> right = temp;

    temp = malloc(sizeof(BstNode));
    temp -> data = 1;
    temp -> left = NULL;
    temp -> right = NULL;
    root -> left -> left = temp;


    temp = malloc(sizeof(BstNode));
    temp -> data = 4;
    temp -> left = NULL;
    temp -> right = NULL;
    root -> right -> left = temp;

    temp = malloc(sizeof(BstNode));
    temp -> data = 7;
    temp -> left = NULL;
    temp -> right = NULL;
    root -> right -> right = temp;
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
