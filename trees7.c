// Binary Tree Traversal
// Tree Traversal: The process of visiting each node in the tree exactly
// once in some order
// 
// Visit: Reading/Processing/Printing data in a node
// 
// Tree Traversal
// |-> Breadth-first (Level-order Traversal)
// |-> Depth-first
// 
//        F
//      /   \
//     D     J
//    / \   / \
//   B   E G   K
//  / \     \
// A   C     I
//          /
//         H 
//
// Breadth-first:
// F D J B E G K A C I H
//
// Depth-first: (3 types)
// <root><left><right> - Preorder
// <left><root><right> - Indorder
// <left><right><root> - Postorder
// 
// Preorder: F D B A C E J G I H K
// Inorder: A B C D E F G H I J K -- Inorder traversal of a BST will give a sorted list
// Postorder: A C B E D H I G K J F