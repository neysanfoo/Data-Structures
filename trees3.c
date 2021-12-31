// Binary Search Tree
// A binary search tree is a binary tree in which
// 1) The left subtree of a node contains only nodes with keys lesser than the node’s key.
// 2) The right subtree of a node contains only nodes with keys greater than the node’s key.
//      4
//     / \
//    /   \
//   2     6
//  / \   / \
// 1   3 5   7
//
// Implementation:
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print.h"


BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);
bool Search(BstNode *root, int data);


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
    int number;
    printf("Enter a number to be searched: ");
    scanf("%d", &number);
    if (Search(root,number))
    {
        printf("Your number has been found!\n");
    }
    else 
    {
        printf("Not found!\n");
    }
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

bool Search(BstNode *root, int data)
{
    if (root == NULL) return false;
    else if (root -> data == data) return true;
    else if(data <= root -> data) return Search(root -> left, data);
    else return Search(root -> right, data);
}