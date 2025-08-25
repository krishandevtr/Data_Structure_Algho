//* ========================== BINARY SEARCH TREE (BST) ==========================
// A Binary Search Tree is a special type of binary tree where each node follows:
// 1. All nodes in the left subtree of a node contain values less than the node's value.
// 2. All nodes in the right subtree of a node contain values greater than the node's value.
// 3. Both left and right subtrees are also BSTs.




// Degree of Node: Number of children (0, 1, or 2 in BST).

//* -------------------------- PROPERTIES --------------------------
// 1. Inorder traversal of BST gives elements in sorted order.
// 2. Average case complexity assumes tree is balanced.
// 3. No duplicate values 
// 4. Operations and Time Complexity:
//    - Search:     O(log n) / O(n)   (average / worst case)
//    - Insertion:  O(log n) / O(n)
//    - Deletion:   O(log n) / O(n)

//* -------------------------- TYPES OF BST --------------------------
// 1. Balanced BST: Height is minimized for n nodes, ensuring O(log n) operations.
// 2. Unbalanced BST: Resembles a linked list in worst case (degenerate tree).

//* -------------------------- EXAMPLE BST --------------------------
// Visual Representation:
//
//        50       <- Root (Level 1)
//       /  \
//     30    70    <- Level 2
//    / \    / \
//  20  40  60  80 <- Level 3
//


// Drawbacks of a basic BST:
// 1. The height of the tree depends on the order of insertion.
// 2. We cannot control the insertion order in general.
// 3. If nodes are inserted in sorted order, the BST becomes skewed,
//    leading to poor performance (O(n) instead of O(log n)).

//! Need for height control:
// - To maintain efficient operations, we need a way to control the height of the tree.
// - Standard BST does not automatically balance itself.

//! Solution: AVL Tree
// - AVL Tree is a self-balancing Binary Search Tree (BST).
// - It automatically maintains balance after insertions and deletions.
// - Balance Factor = height(left subtree) - height(right subtree)
// - Allowed Balance Factor values: -1, 0, +1
// - If the balance factor goes out of this range, rotations are performed:
//     1. Right Rotation (LL case)
//     2. Left Rotation (RR case)
//     3. Left-Right Rotation (LR case)
//     4. Right-Left Rotation (RL case)
// - This ensures that height remains O(log n), keeping search, insert, and delete efficient.
