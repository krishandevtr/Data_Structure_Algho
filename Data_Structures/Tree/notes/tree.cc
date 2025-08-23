// ========================== TREE DATA STRUCTURE ==========================
// A Tree is a hierarchical data structure consisting of nodes connected by edges.
// It is a non-linear structure (unlike arrays, linked lists).
// If a tree has N nodes, it always has (N - 1) edges.

//* -------------------------- TERMINOLOGY --------------------------

// Node: The basic element that contains data and links to other nodes
// Edge: The connection between two nodes (parent-child relationship)

//* Root:
// - The topmost node in the tree (only one root exists).
// Example:
//        A
//       / \
//      B   C
//* Here, 'A' is the root

//* Parent:
// - A node that has one or more child nodes
//* Example: A is parent of B and C

//* Child:
// - A node that descends from a parent
//* Example: B and C are children of A

//* Siblings:
// - Nodes that share the same parent
// Example: B and C are siblings

//* Descendants:
// - All nodes in the subtree of a given node
// Example:
//        A
//       / \
//      B   C
//     / \
//    D   E
// Descendants of B = {D, E}
// Descendants of A = {B, C, D, E}

//* Ancestors:
// - All nodes on the path from a node up to the root
// Example: Ancestors of E = {B, A}

//* Degree of a Node:
// - Number of direct children of a node
// Example:
//        A
//       /|\
//      B C D
// A has degree 3
// Leaf nodes have degree 0

//* Degree of a Tree:
// - Maximum degree among all nodes in the tree
// Example: If A has 3 children, and all others ≤ 3, degree of tree = 3

//* Internal Node (Non-leaf):
// - A node with at least one child
// Example: A, B (in above tree)

//* Leaf Node (External / Terminal Node):
// - A node with no children (degree = 0)
// Example: C, D, E

//* Level of a Node:
// - Distance from the root (root is at level 1, its children at level 2, etc.)
// Example: 
// A (level 1), B/C (level 2), D/E (level 3)

//* Height of a Tree:
// - Longest path from the root to a leaf
// Example: In the above tree, height = 3

//* Forest:
// - A collection of disjoint trees
// - If we remove the root of a tree, the remaining disconnected subtrees form a forest
// Example: Removing A from the first example leaves {B}, {C}, {D} as a forest

// -------------------------- SUMMARY --------------------------
// Trees are hierarchical, recursive structures
// They form the foundation for Binary Trees, N-ary Trees, Tries, Heaps, etc.
