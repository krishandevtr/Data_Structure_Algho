//* ========================== B-TREE ========================== //
// A B-Tree is a balanced M-way search tree used in databases and file systems
// It generalizes 2-3 Trees for more than 2-3 children per node

//* -------------------------- PROPERTIES -------------------------- //
// - Order 'm': maximum number of children per node
// - Each node (except root) has:
//     - Minimum ceil(m/2)-1 keys
//     - Maximum m-1 keys
// - Each node (except root) has:
//     - Minimum ceil(m/2) children
//     - Maximum m children
// - Root has at least 1 key
// - Keys in each node are sorted
// - Height-balanced: all leaf nodes are at the same level

//* -------------------------- EXAMPLE (Order 4) -------------------------- //
//         [20, 40]
//       /    |    \
//    [10]   [30]   [50,60,70]
// - Root [20,40] has 2 keys and 3 children
// - Each child maintains sorted keys and satisfies B-Tree properties

//* -------------------------- OPERATIONS -------------------------- //
// - Search:
//     - Start at root, traverse node keys
//     - Choose correct child subtree for next search
// - Insertion:
//     - Insert key into correct leaf node
//     - If node overflows (> m-1 keys), split and push middle key up
// - Deletion:
//     - Remove key
//     - If underflow (< ceil(m/2)-1 keys), borrow from sibling or merge nodes
// - Time Complexity: O(log n)

//* -------------------------- USE CASES -------------------------- //
// - Database indexing
// - File systems (like NTFS, ext)
// - Any system requiring balanced M-way search trees
