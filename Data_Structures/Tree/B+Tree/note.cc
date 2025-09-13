//* ========================== B+ TREE ==========================
// A B+ Tree is a self-balancing m-ary search tree, commonly used in databases
// and file systems. It is an extension of the B-Tree with some key differences:
//   - Internal nodes only store keys (used for navigation).
//   - All actual data records are stored in the leaf nodes.
//   - Leaf nodes are linked sequentially for fast range queries.

//* -------------------------- PROPERTIES --------------------------
// 1. All leaves are at the same level (balanced).
// 2. A node can have between ⌈m/2⌉ and m children (for order m tree).
// 3. Internal nodes act as index (routing keys).
// 4. Leaf nodes contain the actual data and are linked like a linked list.
// 5. Supports both point queries and range queries efficiently.

//* -------------------------- OPERATIONS & COMPLEXITY --------------------------
// - Search:    O(log n)   (only leaf nodes hold data)
// - Insertion: O(log n)   (split may propagate upward)
// - Deletion:  O(log n)   (merge/borrow logic at leaves)
// - Range Query: O(log n + k)  (k = number of results, very efficient)
// - Traversal: O(n) (via leaf node chain)

//* -------------------------- EXAMPLE STRUCTURE --------------------------
//
// Internal Nodes (Index):
//          [30 | 60]
//         /    |    \
//   [10|20]  [40|50]  [70|80|90]   <- Leaf nodes
//
// - Internal nodes (like [30|60]) guide the search.
// - Actual data lives in leaf nodes ([10|20], [40|50], etc.).
// - Leaf nodes are linked: [10|20] -> [40|50] -> [70|80|90]
//

//* -------------------------- INSERTION RULES --------------------------
// 1. Always insert into a leaf node (data lives in leaves).
// 2. If leaf is full, split the node:
//    - Promote the first key of the new node to parent as separator.
//    - Parent may split recursively up to root.
// 3. Root split increases tree height by 1.

//* -------------------------- DELETION RULES --------------------------
// 1. Delete key from leaf.
// 2. If leaf underflows (fewer than ⌈m/2⌉ entries), borrow or merge with sibling.
// 3. Adjust parent keys as necessary.
// 4. Tree remains balanced automatically.

//* -------------------------- ADVANTAGES --------------------------
// 1. Excellent for databases and file systems (disk-friendly).
// 2. Leaf node chaining makes range queries & sequential access very efficient.
// 3. Internal nodes are small (index only), reducing memory & I/O cost.
// 4. Always balanced with guaranteed O(log n) operations.

//* -------------------------- DRAWBACKS --------------------------
// 1. More complex implementation compared to BST/AVL.
// 2. Slightly slower for single record lookup than AVL (more pointer chasing).
// 3. Purely in-memory structures often prefer AVL/Red-Black, 
//    but B+ Trees dominate in storage systems (due to block-based access).

//* -------------------------- USE CASES --------------------------
// - Databases (MySQL, PostgreSQL indexes).
// - File systems (NTFS, ReFS, ext4).
// - Any system needing efficient range queries and block/disk-based access.
