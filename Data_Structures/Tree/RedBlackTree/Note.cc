//* ========================== RED-BLACK TREE ==========================
// A Red-Black Tree is a self-balancing  or Height Balanced  Binary Search Tree(BST).
// It guarantees O(log n) operations by enforcing extra color + balancing rules.
// Invented to simulate the balancing properties of 2-3-4 Trees using a binary tree.

//* -------------------------- PROPERTIES --------------------------
// 1. Every node is either RED or BLACK.
// 2. Root is always BLACK.
// 3. All leaves (NULL pointers) are considered BLACK.
// 4. Red Node Rule: A red node cannot have a red parent (no two reds in a row).
// 5. Black Height Rule: Every path from a node to descendant NULL leaves 
//    has the same number of black nodes (black-height).
// → These properties ensure balanced height, max ~ 2*log2(n).

//* -------------------------- COMPLEXITY --------------------------
// - Search:    O(log n)
// - Insertion: O(log n) (may involve recoloring + rotations)
// - Deletion:  O(log n) (fixing underflow with recoloring/rotations)
// - Traversal: O(n)

//* -------------------------- EXAMPLE STRUCTURE --------------------------
//
//          (10)B                <- Root (Black)
//         /     \
//     (5)R       (20)R
//               /     \
//           (15)B     (25)B
//
// - Black height property maintained.
// - Red nodes always have black children.
//

//* -------------------------- INSERTION RULES --------------------------
// 1. Insert like a normal BST (new node starts RED).
// 2. If Red-Black properties are violated, fix using:
//    - Recoloring
//    - Rotations (LL, RR, LR, RL)
// 3. Root is always set to BLACK at the end.

//* -------------------------- DELETION RULES --------------------------
// 1. Delete like a BST (use successor if internal).
// 2. If a BLACK node is removed, it may cause double-black issue.
// 3. Fix via rotations and/or recoloring until properties are restored.

//* -------------------------- ADVANTAGES --------------------------
// 1. Always balanced → O(log n) guaranteed.
// 2. Simpler implementation than AVL for large-scale use.
// 3. Widely used in libraries (C++ STL `map`, `set`; Java `TreeMap`, `TreeSet`).
// 4. Equivalent to 2-3-4 Trees (isometry).

//* -------------------------- DRAWBACKS --------------------------
// 1. Not as tightly balanced as AVL Trees (may have slightly taller height).
// 2. More complex than simple BST.
// 3. Extra space needed for color bit.

//* -------------------------- USE CASES --------------------------
// - C++ STL `map`, `multimap`, `set`, `multiset`
// - Java `TreeMap`, `TreeSet`
// - Linux Kernel scheduler, memory management
// - Associative containers requiring ordered keys
