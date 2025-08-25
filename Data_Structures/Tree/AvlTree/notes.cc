//* ========================== AVL TREE ==========================
// An AVL Tree is a **self-balancing Binary Search Tree (BST)** where:
// 1. For every node, the height difference (Balance Factor) between the left and right subtrees is at most **1**.
// 2. It ensures O(log n) time complexity for search, insertion, and deletion operations by maintaining balance.
// 3. It is named after its inventors Adelson-Velsky and Landis.

//* -------------------------- PROPERTIES --------------------------
// 1. Balance Factor (BF) = height(left subtree) - height(right subtree)
//    - Valid BF values: -1, 0, +1
// 2. If any node's BF becomes < -1 or > +1 after an operation, rotations are applied.
// 3. Inorder traversal of AVL gives elements in **sorted order** (like BST).
// 4. No duplicate values.

//* -------------------------- OPERATIONS & TIME COMPLEXITY --------------------------
// - Search:     O(log n)   (always balanced height)
// - Insertion:  O(log n)   (may involve 1 or 2 rotations)
// - Deletion:   O(log n)   (may involve 1 or 2 rotations)

//* -------------------------- ROTATIONS IN AVL TREE --------------------------

// 1. **Right Rotation (LL Case)** – Left-heavy imbalance
//    Triggered when: Node is unbalanced due to insertion in **left-left** position.
//
//    BEFORE ROTATION:
//          z
//         /
//        y
//       /
//      x
//
//    AFTER RIGHT ROTATION (around z):
//        y
//       / \
//      x   z


// 2. **Left Rotation (RR Case)** – Right-heavy imbalance
//    Triggered when: Node is unbalanced due to insertion in **right-right** position.
//
//    BEFORE ROTATION:
//      z
//       \
//        y
//         \
//          x
//
//    AFTER LEFT ROTATION (around z):
//        y
//       / \
//      z   x


// 3. **Left-Right Rotation (LR Case)** – Left-Right imbalance
//    Triggered when: Node is unbalanced due to insertion in **left-right** position.
//
//    BEFORE ROTATION:
//         z
//        /
//       y
//        \
//         x
//
//    STEP 1: Left rotation on y
//         z
//        /
//       x
//      /
//     y
//
//    STEP 2: Right rotation on z (FINAL):
//        x
//       / \
//      y   z


// 4. **Right-Left Rotation (RL Case)** – Right-Left imbalance
//    Triggered when: Node is unbalanced due to insertion in **right-left** position.
//
//    BEFORE ROTATION:
//      z
//       \
//        y
//       /
//      x
//
//    STEP 1: Right rotation on y
//      z
//       \
//        x
//         \
//          y
//
//    STEP 2: Left rotation on z (FINAL):
//        x
//       / \
//      z   y


//* -------------------------- ADVANTAGES OVER BST --------------------------
// 1. Guaranteed O(log n) operations, unlike unbalanced BST which can degrade to O(n).
// 2. Prevents skewed tree formations even with sorted insertions.
// 3. Suitable for applications needing frequent insertions/deletions while maintaining order.

//* -------------------------- EXAMPLE AVL TREE --------------------------
// Insertions: 10, 20, 30, 40, 50
//
//       30
//      /  \
//    20    40
//   /        \
// 10          50
//
// (Tree stays balanced due to rotations)

//* -------------------------- DRAWBACK --------------------------
// - Slightly more complex to implement due to rotations and height updates.
// - May have a bit more overhead compared to a simple BST if data is already random.
//
//! Conclusion:
// AVL Trees ensure **consistent and efficient performance** for dynamic datasets 
// by maintaining balance through rotations after every modification.
