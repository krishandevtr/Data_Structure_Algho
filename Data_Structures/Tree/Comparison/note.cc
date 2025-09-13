//* ========================== TREE COMPARISON ==========================

//* -------------------------- 1. BINARY SEARCH TREE (BST) --------------------------
// - Not self-balancing.
// - Height depends on insertion order → Worst case O(n).
// - Search, Insert, Delete: O(log n) average, O(n) worst.
// - Inorder traversal → sorted order.
// Use Case: Small apps, teaching basics.
// Scenario: Good if insertion order is random. 
// Example: Storing a small set of student records in memory.


//* -------------------------- 2. AVL TREE --------------------------
// - Strictly balanced (Balance Factor = -1, 0, 1).
// - Search, Insert, Delete: O(log n).
// - More rotations → higher insertion/deletion cost.
// - Provides faster lookups (shorter height than RBT).
// Use Case: Search-heavy applications (databases, indexing).
// Scenario: Dictionary lookups, IP routing tables, 
//           autocomplete suggestions where reads >> writes.


//* -------------------------- 3. RED-BLACK TREE --------------------------
// - Loosely balanced BST (height ≤ 2*log n).
// - Fewer rotations than AVL → faster inserts/deletes.
// - Slightly slower lookups than AVL.
// - Equivalent to 2-3-4 Trees (isometry).
// Use Case: Balanced performance between read & write operations.
// Scenario: Widely used in libraries and OS kernels.
// Example: C++ STL map/set, Java TreeMap/TreeSet, Linux scheduler.


//* -------------------------- 4. 2-3-4 TREE --------------------------
// - Multi-way search tree (nodes can hold 1–3 keys).
// - Always balanced; height = O(log n).
// - Insertions cause node splits; deletions may cause merges.
// - Basis for Red-Black Trees.
// Use Case: Theoretical model, databases, file systems.
// Scenario: When implementing a balanced tree with fewer height levels.
// Example: Underlying structure for Red-Black trees.


//* -------------------------- 5. B+ TREE --------------------------
// - Extension of B-Tree.
// - Internal nodes store only keys (for navigation).
// - All data stored in leaf nodes.
// - Leaf nodes are linked for fast range queries.
// - Search, Insert, Delete: O(log n).
// - Range queries: O(log n + k).
// Use Case: Databases, file systems, large datasets.
// Scenario: When both point queries & range queries are needed.
// Example: MySQL, PostgreSQL indexes, NTFS/ext4 file systems.


//* -------------------------- QUICK SUMMARY --------------------------
// - BST: Simple, but unbalanced in worst case.
// - AVL: Strict balance → faster search, slower insert/delete.
// - Red-Black: Looser balance → good overall performance, used in libraries.
// - 2-3-4 Tree: Multi-way, theoretical model equivalent to Red-Black.
// - B+ Tree: Best for databases & disk storage, supports range queries.

