//* ========================== NUMBER OF BINARY TREES ==========================

//* Given 'n' nodes, the number of **distinct binary trees** that can be formed
// is given by the Catalan Number formula:

//* Catalan Formula:
// Number of binary trees with n nodes = Cn = (2n)! / ( (n+1)! * n! )
// Or equivalently: Cn = (2n choose n) / (n + 1)

//* Examples:

// 1. If n = 3 nodes:
// Number of different binary trees = C3
// C3 = (2*3)! / ((3+1)! * 3!) = 6! / (4! * 3!) = 720 / (24*6) = 5
// So, 5 different shaped binary trees can be created with 3 nodes

//* Visual examples of 3-node trees:
//   1)     1        2)     1        3)     2        4)     3        5)     3
//          / \             / \             / \             / \             / \
//         2   3           3   2           1   3           1   2           2   1

// 2. If n = 4 nodes:
// Number of different binary trees = C4
// C4 = (2*4)! / ((4+1)! * 4!) = 8! / (5! * 4!) = 40320 / (120*24) = 14
// So, 14 distinct binary trees can be created with 4 nodes

// 3. If n = 5 nodes:
// C5 = (2*5)! / (6! * 5!) = 42
// Meaning, 42 distinct binary trees can be made with 5 nodes

//* -------------------------- SUMMARY --------------------------
// n nodes      Number of distinct binary trees
// 1                1
// 2                2
// 3                5
// 4                14
// 5                42
// 6                132
// 7                429
// and so on...
// These numbers are called Catalan Numbers

//* Catalan numbers appear in many combinatorial problems such as:
// - Number of valid parentheses expressions
// - Number of ways to triangulate a polygon
// - Number of full binary trees with n+1 leaves


//? Max height = 2 ^n-1 
