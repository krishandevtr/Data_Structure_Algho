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

