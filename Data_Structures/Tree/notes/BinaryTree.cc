// ========================== BINARY TREE ==========================
// A binary tree is a special type of tree in which each node has at most two children: 
// left child and right child.
// Each node can have 0, 1, or 2 children.

// -------------------------- TERMINOLOGY --------------------------

// Node: Basic element of a tree containing data and pointers to left and right children.
// Edge: Connection between a parent and a child node.

// Root:
// Topmost node of the tree with no parent.
// Example:
//        A  <- Root
//       / \
//      B   C

// Parent:
// Node with at least one child.
// Example: A is the parent of B and C

// Child:
// Node with a parent.
// Example: B and C are children of A

// Left Child / Right Child:
// In a binary tree, children are explicitly left or right.
// Example: In the above tree:
// Left child of A = B, Right child of A = C

// Siblings:
// Nodes sharing the same parent.
// Example: B and C are siblings

// Leaf Node (External / Terminal):
// Node with no children (degree 0)
// Example: B, C if they have no children

// Internal Node:
// Node with at least one child
// Example: A (because it has B and C)

// Level of a Node:
// Distance from the root node (root is level 1, children are level 2, etc.)
// Example:
// Level 1: A
// Level 2: B, C

// Height of a Tree:
// Maximum number of edges from the root to a leaf node
// Example: Height of the above tree = 2

// Degree of a Node:
// Number of children of that node (0, 1, or 2 in binary tree)
// Example:
// Degree of A = 2 (B and C)
// Degree of B = 0 (leaf node)

// Maximum Nodes at Level l:
// 2^(l-1)
// Example: Level 1: 1 node, Level 2: 2 nodes, Level 3: 4 nodes

// Maximum Nodes in a Tree of Height h:
// 2^h - 1
// Example: If height = 3, maximum nodes = 2^3 - 1 = 7

// -------------------------- TYPES OF BINARY TREE --------------------------

// *1. Full Binary Tree:
// Every node has 0 or 2 children
// Example:
//        A
//       / \
//      B   C
//     / \
//    D   E

// *2. Complete Binary Tree:
// All levels are fully filled except possibly last, filled from left to right
// Example:
//        A
//       / \
//      B   C
//     / \  /
//    D   E F

// *3. Perfect Binary Tree:
// All internal nodes have 2 children, all leaf nodes at same level
// Example:
//        A
//       / \
//      B   C
//     / \ / \
//    D  E F  G

// *4. Degenerate / Pathological Tree:
// Each parent has only one child (resembles linked list)
// Example:
// A
//  \
//   B
//    \
//     C
//      \
//       D

// -------------------------- EXAMPLE BINARY TREE --------------------------
// Visual Representation:
//
//        A       <- Root (Level 1)
//       / \
//      B   C     <- Level 2
//     / \    \
//    D   E    F <- Level 3
//
//* Concepts applied:
// Root: A
// Internal nodes: A, B, C
// Leaf nodes: D, E, F
// Left child of B: D
// Right child of C: F
// Height: 3
// Levels: A(1), B/C(2), D/E/F(3)
// Degree of nodes: A=2, B=2, C=1, D/E/F=0
