//* ========================== TREE REPRESENTATION ==========================

// Trees can be represented in two main ways:
// 1. Using Arrays
// 2. Using Linked Lists

//! -------------------------- 1. ARRAY REPRESENTATION --------------------------
// Idea: Store the nodes in a sequential array and use index positions
// to maintain parent-child relationships

//  For Binary Tree (special case):
// - If the root is stored at index 1 (instead of 0):
//   Left child of node at index i = index (2 * i)
//   Right child of node at index i = index (2 * i + 1)
//   Parent of node at index i = index (i / 2)

// Example:
// Elements: A, B, C, D, E, F, G
// Store them as:
//
// Index:   1   2   3   4   5   6   7
// Node :   A   B   C   D   E   F   G
//
// Tree looks like:
//           A(1)
//         /     \
//      B(2)     C(3)
//     /  \     /  \
//   D(4) E(5) F(6) G(7)
//
// Relationships:
// - Left child of A(1) = index 2 = B
// - Right child of A(1) = index 3 = C
// - Parent of E(5) = index 2 = B

//? Formulas , ELements = i , left child : 2i , right child: 2*i+1, parent: i/2

// Advantages of Array Representation:
// - Easy to compute parent/child relationships
// - Very efficient for Complete Binary Trees
//
// Disadvantages:
// - Wastes space for sparse trees (many NULL entries)
// - Hard to resize dynamically

//! -------------------------- 2. LINKED  REPRESENTATION --------------------------
// Each node is represented by a structure/class with data and references (pointers) to children
//
// struct Node {
//     char data;
//     Node* left;
//     Node* right;   // (for binary trees)
// };
//
// Example (Binary Tree):
// A
// ├── B
// │   ├── D
// │   └── E
// └── C
//     ├── F
//     └── G
//
// Node representation:
// A -> left = B, right = C
// B -> left = D, right = E
// C -> left = F, right = G
//
// For General Trees (N-ary):
// - Each node has a pointer to its first child and next sibling
// (known as "First Child / Next Sibling Representation")
//
// struct Node {
//     char data;
//     Node* firstChild;
//     Node* nextSibling;
// };
//
//* This allows representing any N-ary tree efficiently in linked form.

// -------------------------- SUMMARY --------------------------
//* Array Representation -> Best for complete binary trees
//* Linked List Representation -> Best for general / dynamic trees
