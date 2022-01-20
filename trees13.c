// Inorder Successor in a BST
// Inorder: <left><root><right>
// Case 1: Node has right subtree
// - Find min in right subtree
// Case 2: No right subtree
// - Go to the nearest(deepest) ancestor for which given node would be in left subtree

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "print.h"


BstNode *Insert(BstNode *root, int data);
BstNode* GetNewNode(int data);

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


BstNode *Find(BstNode *root, int data)
{
    if (root == NULL) return NULL;
    else if (root -> data == data) return root;
    else if (data < root -> data) return Find(root->left,data);
    else return Find(root -> right, data);
}

BstNode *FindMin(BstNode *root)
{
    while (root -> left != NULL) root = root -> left;
    return root;
}

BstNode *InorderSucessor(BstNode *root, int data)
{
    // Search the Node -- O(h)
    BstNode *current = Find(root,data);
    if (current == NULL) return NULL;
    if (current -> right != NULL)    // Case 1: Node has right subtree
    {
        BstNode *successor = FindMin(current -> right);
        printf("%d\n", successor -> data);
        return successor;
    }
    else    // Case 2: No right subtree - O(h)
    {
        BstNode *successor = NULL;
        BstNode *ancestor = root;
        while (ancestor != current)
        {
            if (ancestor -> data > current -> data)
            {
                successor = ancestor;
                ancestor = ancestor -> left;
            }
            else 
            {
                ancestor = ancestor -> right;
            }
        }
        printf("%d\n", successor -> data);
        return successor;
    }
    return current;
}

int main(void)
{
    BstNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,10);
    root = Insert(root,6);
    root = Insert(root,20);
    root = Insert(root,19);
    root = Insert(root,12);
    root = Insert(root,11);
    root = Insert(root,55);
    printBST(root,0);
    Inorder(root);
    printf("\n");
    InorderSucessor(root, 6);
    InorderSucessor(root, 10);
    InorderSucessor(root, 11);
    InorderSucessor(root, 12);
    InorderSucessor(root, 15);
    InorderSucessor(root, 19);
    InorderSucessor(root, 20);
    InorderSucessor(root, 55);
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
