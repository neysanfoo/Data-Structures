// Delete Node from BST
// Case 1: No Child
// Case 2: One Child
// Case 3: 2 Children

// Case 1: Just delete node
// Case 2: Connect parent to its only child and delete
// Case 3: - Find min in right subtree
//         - Copy the value in targetted node
//         - Delete duplicate from right subtree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print.h"


BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);

BstNode *FindMin(BstNode *root)
{
    if (root -> left == NULL)
    {
        return root;
    }
    return FindMin(root -> left);
}

BstNode *Delete(BstNode *root, int data)
{
    if (root == NULL) return root;
    else if (data < root -> data) root -> left = Delete(root -> left, data);
    else if (data > root -> data) root -> right = Delete(root ->right,data);
    else 
    {
        if (root -> left == NULL && root -> right == NULL) // Case 1
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root -> left == NULL) // Case 2
        { 
            BstNode *temp = root;
            root = root -> right;
            free(temp);
            return root;
        }
        else if (root -> right == NULL) // Case 2
        { 
            BstNode *temp = root;
            root = root -> left;
            free(temp);
            return root;
        }
        else // Case 3
        {
            BstNode *temp = FindMin(root -> right);
            root -> data = temp -> data;
            root -> right = Delete(root -> right, temp->data);
        }
    }
    return root;
}

int main(void)
{
    BstNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,20);
    root = Insert(root,12);
    root = Insert(root,11);
    root = Insert(root,55);
    root = Delete(root, 11);
    root = Insert(root,11);
    printBST(root,0);
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
