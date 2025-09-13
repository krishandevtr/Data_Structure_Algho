//* ========================== 2-3 TREE ========================== //
// A 2-3 Tree is a balanced search tree where each node can have 2 or 3 children
// and store 1 or 2 keys.

//* -------------------------- NODE TYPES -------------------------- //
// 1. 2-Node: 
//    - Contains 1 key
//    - Has 2 children (Left, Right)
// 2. 3-Node:
//    - Contains 2 keys (k1 < k2)
//    - Has 3 children (Left, Middle, Right)

//* -------------------------- PROPERTIES -------------------------- //
// - Height-balanced: all leaf nodes are at the same level
// - Keys inside a node are sorted
// - Child subtrees follow BST property:
//   - For 2-node with key k: Left < k < Right
//   - For 3-node with keys k1 < k2: Left < k1 < Middle < k2 < Right

//* -------------------------- EXAMPLE -------------------------- //
//         [30]
//       /      \
//    [10,20]   [40,50]
// - Root [30] is a 2-node
// - Left child [10,20] is a 3-node
// - Right child [40,50] is a 3-node

//* -------------------------- OPERATIONS -------------------------- //
// - Search: similar to BST but check multiple keys per node
// - Insertion:
//   - Insert key into the correct leaf
//   - If leaf overflows (3 keys), split and push middle key up
// - Deletion:
//   - Remove key
//   - If underflow (<1 key), borrow from sibling or merge nodes
// - Time Complexity: O(log n)

//* -------------------------- USE CASES -------------------------- //
// - Used in balanced search trees, database indexing, and as a base for B-Trees


//* ========================== B-TREE ========================== //
// B-Tree is a generalization of 2-3 Tree for M-way search trees
// Widely used in databases and file systems

//* -------------------------- PROPERTIES -------------------------- //
// - Order m: max number of children a node can have
// - Each node (except root) has:
//     - ceil(m/2)-1 to m-1 keys
//     - ceil(m/2) to m children
// - Root has at least 1 key
// - Keys in a node are sorted
// - Height-balanced: all leaf nodes are at the same level

//* -------------------------- EXAMPLE (Order 4) -------------------------- //
//         [20, 40]
//       /    |    \
//    [10]   [30]   [50,60,70]
// - Root [20,40] has 2 keys and 3 children
// - Each child node maintains sorted keys

//* -------------------------- OPERATIONS -------------------------- //
// - Search: similar to multi-key binary search
// - Insertion:
//   - Insert into correct leaf
//   - If node overflows (> m-1 keys), split and push middle key up
// - Deletion:
//   - Remove key
//   - If underflow (< ceil(m/2)-1 keys), borrow from sibling or merge nodes
// - Time Complexity: O(log n)

//* -------------------------- USE CASES -------------------------- //
// - Databases indexing
// - File systems (ext, NTFS, etc.)
// - Any system needing balanced M-way search trees
