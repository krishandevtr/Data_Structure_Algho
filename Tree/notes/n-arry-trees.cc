//* ========================== N-ARY TREE ==========================
// An N-ary tree is a tree in which each node can have at most N children.
// Example: In a 3-ary tree, each node can have 0, 1, 2, or 3 children.

//* -------------------------- TYPES OF N-ARY TREES --------------------------

//* 1. Strict N-ary Tree (also called Full N-ary Tree):
//    - Every internal node has exactly N children
//    - Leaf nodes have 0 children
//
//* Example (Strict 3-ary tree):
//            A
//         /  |  \
//        B   C   D
//      /|\  /|\  /|\
//     E F G H I J K L M
//
// Here:
// - A has exactly 3 children (B, C, D)
// - B, C, D each have exactly 3 children
// - E, F, G, ... M are leaf nodes with 0 children
//
//* Properties of a Strict N-ary Tree:
// - If it has i internal nodes, total number of children = N * i
// - Number of leaf nodes = (N - 1) * i + 1
// - Every non-leaf node strictly has N children

//* 2. Non-Strict N-ary Tree (General N-ary Tree):
//    - Each node can have at most N children (0 to N)
//    - No requirement that all internal nodes must have exactly N children
//
//* Example (Non-strict 3-ary tree):
//            A
//         /  |  \
//        B   C   D
//       / \     |
//      E   F    G
//
// Here:
// - A has 3 children (B, C, D)
// - B has 2 children (E, F)
// - C has 0 children
// - D has 1 child (G)
// - This is valid because no node exceeds 3 children
// - It is NOT strict because not every internal node has exactly 3 children

//* -------------------------- DIFFERENCE --------------------------
// Strict N-ary Tree:
// - Internal nodes MUST have exactly N children
// - Leaf nodes MUST have 0 children
// - More "rigid" structure
//
// Non-Strict N-ary Tree:
// - Nodes can have between 0 and N children
// - More flexible structure, closer to real-world hierarchies

//* -------------------------- USE CASES --------------------------
// - General N-ary Tree (Non-strict): File system hierarchy (folders with varying children)
// - Strict N-ary Tree: Complete m-way tries, fixed branching data structures

