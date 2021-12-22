// A linked list is a dynamic list.
// In memory, it is stored as non contiguous nodes connected to each other with
// pointers.
// The first node is called the head node.
// The only information we keep about the list is the address of the head node.
// So, access of the head node gives us access of the complete list.
// The last node has a pointer NULL or 0, which means it does not point to any
// other node.


// If we want to traverse a linked list, the only way to do start at the head
// and follow the path of pointers.

// If we want to insert a node at the end of the linked list, we first need to
// create a node seperately and set the pointer to the last node to the address
// of the new node, then set the pointer of the new node to NULL.

// Inserting Into a Linked List at nth Position
// If we want to insert a node somewhere within a list, lets say at index 2,
// then we first need to create a node seperately and set the pointer of the new node to
// the address of the previous node at index 2. Then we set the pointer of the node at
// index 1 to the address of the new node. The time complexity will be O(n).

// Inserting Into a Linked List at the Start
// If we want to insert a node at the start of a link list, we first create a new node
// and set the pointer of that node to the address of head. Then we make the new node 
// our head. The time complexity is O(1).

// Accessing a Linked List:
// Unlike arrays, we cannot access(read/write) any of the elements in constant time.
// Worst case scenario, we have to traverse all the elements to find the
// element we want, so the time complexity is O(n).


// Ideas:
// Linked list CLI
// Store Data in a Data Structure CLI (Future Idea)