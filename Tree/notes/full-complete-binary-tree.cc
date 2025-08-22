//* Difference between Full Binary Tree and Complete Binary Tree:
//
// 1. Full or strict Binary Tree:
//    - Every node has either 0 or 2 children (never exactly 1 child).
//    - All leaf nodes may not be at the same level.
//    - Example: 
//             A
//           /   \
//          B     C
//         / \   / \
//        D   E F   G
//    - Here, every node has either 2 children or none → FULL.
//
//* 2. Complete Binary Tree:
//    - All levels are completely filled except possibly the last level.
//    - In the last level, all nodes must be as far left as possible.
//    - Example:
//             A
//          /    \
/          B      C
//        / \    /
//       D   E  F
//    - This is COMPLETE (last level not full, but filled from left).
//
//* Key Difference:
//* - FULL focuses on "0 or 2 children" property.
//* - COMPLETE focuses on "levels filled left-to-right".
