//* ========================== TREE TRAVERSALS ==========================
// Tree traversals are algorithms for visiting each node of a tree data structure exactly once.
// The three main types—pre-order, in-order, and post-order—are defined by the order in which
// the root node is processed relative to its left and right child nodes.

//* -------------------------- PRE-ORDER TRAVERSAL --------------------------
// Order: Root -> Left -> Right
//
// Description:
// In a pre-order traversal, you visit the root node first, then recursively
// traverse its left subtree, and finally its right subtree.
//
// Use Case:
// This traversal is useful for creating a copy of a tree because the parent
// node is always copied before its children. It's also used to get the
// prefix notation (Polish notation) of an expression tree.

//* -------------------------- IN-ORDER TRAVERSAL --------------------------
// Order: Left -> Root -> Right
//
// Description:
// An in-order traversal visits the left subtree first, then the root node,
// and finally the right subtree.
//
// Use Case:
// This method is particularly useful for binary search trees, as it traverses
// the nodes in ascending (sorted) order.

//* -------------------------- POST-ORDER TRAVERSAL --------------------------
// Order: Left -> Right -> Root
//
// Description:
// A post-order traversal visits the left subtree first, then the right
// subtree, and finally the root node.
//
// Use Case:
// This traversal is commonly used to delete a tree because it ensures that
// the children are processed and deleted before their parent, preventing
// dangling pointers. It is also used to get the postfix notation (Reverse
// Polish Notation) of an expression tree.
