// Binary Tree Implementation

#include <stdio.h>
#include <stdlib.h>
#include "print.h"

NodeT *root;

int main(void)
{
  root = NULL;
  NodeT *temp = malloc(sizeof(NodeT));
  temp -> data = 1;
  temp -> left = NULL;
  temp -> right = NULL;
  root = temp;

  temp = malloc(sizeof(NodeT));
  temp -> data = 2;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> left = temp;
  
  temp = malloc(sizeof(NodeT));
  temp -> data = 3;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> right = temp;

  temp = malloc(sizeof(NodeT));
  temp -> data = 4;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> left -> left = temp;

  temp = malloc(sizeof(NodeT));
  temp -> data = 5;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> left -> right = temp;

  temp = malloc(sizeof(NodeT));
  temp -> data = 6;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> right -> left = temp;

  temp = malloc(sizeof(NodeT));
  temp -> data = 7;
  temp -> left = NULL;
  temp -> right = NULL;
  root -> right -> right = temp;

  printTree(root,0);

  return 0;

}
