//* ========================== 2-3-4 TREE ==========================
// A 2-3-4 Tree is a self-balancing multi-way search tree. 
// It is a specific type of B-tree of order 4.
// Each node can have:
//   - 2 children and 1 value   (2-node)
//   - 3 children and 2 values  (3-node)
//   - 4 children and 3 values  (4-node)

//* -------------------------- PROPERTIES --------------------------
// 1. All leaves are at the same level (perfectly balanced).
// 2. Node values are kept in sorted order.
// 3. Insertion and splitting maintain balance automatically.
// 4. Height grows slowly → O(log n).
// 5. No duplicates (in standard definition).

// Degree of Node: Number of children (between 2 and 4 for non-leaf nodes).

//* -------------------------- OPERATIONS & COMPLEXITY --------------------------
// - Search:    O(log n)
// - Insertion: O(log n)
// - Deletion:  O(log n)
// - Traversal: O(n)

//* -------------------------- EXAMPLE STRUCTURE --------------------------
//
//         [20 | 40]            <- Root (3-node with 2 values, 3 children)
//        /    |    \
//    [10]   [30]   [50 | 60]   <- Internal nodes
//
// Rules:
// - Keys inside nodes are always sorted.
// - Subtrees divide the key space: 
//   * Left of 20  → values < 20
//   * Between 20 & 40 → values between 20 and 40
//   * Right of 40 → values > 40
//

//* -------------------------- INSERTION RULES --------------------------
// 1. Always insert into a leaf.
// 2. If target node is a 4-node (3 values), split it before descending:
//    - Middle value moves up to parent.
//    - Node splits into two smaller nodes (2-node each).
// 3. Splits may propagate up to root, increasing height.
// 4. Tree stays balanced automatically.

//* -------------------------- DELETION RULES --------------------------
// 1. Remove key from leaf (simple case).
// 2. If deleting from internal node, replace with predecessor/successor.
// 3. If a node becomes underfull (fewer than 1 value), merge or borrow 
//    from siblings to maintain properties.
// 4. Tree re-balances automatically.

//* -------------------------- TYPES OF NODES --------------------------
// - 2-node: 1 key, 2 children
// - 3-node: 2 keys, 3 children
// - 4-node: 3 keys, 4 children

//* -------------------------- ADVANTAGES --------------------------
// 1. Always balanced → guaranteed O(log n).
// 2. Efficient for disk-based storage (used in databases, file systems).
// 3. Can store multiple values per node, reducing tree height.
// 4. Basis for Red-Black Trees (they are isometric to 2-3-4 Trees).

//* -------------------------- DRAWBACKS --------------------------
// 1. Implementation is more complex than simple BST.
// 2. Requires splitting and merging logic for insertions and deletions.
// 3. Not as widely used in memory structures as Red-Black Trees, 
//    but important in databases and file systems.
