// Linear data structures:
// - Array
// - Linked List
// - Stack
// - Queue
//
// Our choice of data structure depends on a number of factors
// - What needs to be stored?
// - Cost of operations? (How to minimize)
// - Memory Usage
// - Ease of implementation 
//
// Tree Terminology
// - Root
// - Children
// - Parent
// - Sibling
// - Leaf
// - Ancestor
// - Descendent
//
// Introduction to Trees
//
//       1      <--- root
//     /   \
//    2     3   <--- 2 and 3 are children of 1 and are also siblings
//   / \   / \
//  4   5 6   7 <--- 3 is the parent of 6 and 7
//        |
//        8     <--- Leaf node (Has no child)
//
//  Trees as an ADT:
//  A collection of entities called nodes linked together to simulate
//  a hierarchy. The topmost node in a tree is called the root of the tree.
//  Each node will contain some data of any type, and may contain link or
//  reference(address) to some other nodes that can be called its children.
//  
// Tree is a recursive data structure.
// Tree
//  |
//  |--> N nodes
//  |--> N-1 edges
//
//  Depth of x = Length of parth from root to x OR no. or edges from root to x
//  Height of x = No. of edges in longest path from x to a leaf node
//
//  Binary Tree: A tree in which each node can have at most 2 children
//
//  Applications:
//  1) Storing naturally hierarchical data, e.g. file system
//  2) Organize data for quick search, insertion, deletion, e.g. binary search
//     tree.
//  3) Trie -> dictionary
//  4) Network routing algorithm
//
// Strict/Proper Binary Tree: Each node can have either 0 or 2 chidlren
// Complete Binary Tree: All levels except possibly the last level are 
// are completely filed and all nodes are as left as possible.
// Perfect Binary Tree: All nodes are completely filled.
//
// Balanced Binary Tree: Difference between height of left and right subtree
// or every node is not more than k (generally k=1).
// We try to keep a tree balanced to minimize cost of operations.
//
// Max no. of nodes at level i = 2^i
// Max no. of nodes in a binary tree with height h = 2^0 + 2^1 + 2^2 + ... + 2^h
//                                                 = 2^(h+1) - 1
// Height of empty tree = -1
// Height of tree with 1 node = 0
//
// We can implement binary tree using:
// a) Dynamically created nodes
// b) Arrays