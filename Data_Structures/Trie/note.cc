//* ========================== TRIE FAMILY ========================== // 
// A Trie is a tree-like data structure used to store strings efficiently. 
// Each path from root to a node represents a prefix of a word.
// Tries are highly efficient for prefix search, autocomplete, and dictionary-like operations.

//* -------------------------- GENERAL PROPERTIES -------------------------- //
// - Root node is empty (does not store any character)
// - Each node contains:
//     - Map/array of children nodes (one for each possible character)
//     - End-of-word flag (isWord) to mark completion of a word
// - Height = length of longest word
// - Shared prefixes are stored once, reducing redundant storage
// - Space complexity depends on alphabet size and number of words

//* -------------------------- TYPES OF TRIES -------------------------- //

// 1. Standard Trie (Prefix Tree)
// - Each node stores a single character
// - Pros: Fast search, O(L) where L = word length
// - Cons: High memory usage for large alphabets
// - Example:
//     Words: "cat", "cap", "bat"
//             root
//             /  \
//            c    b
//           / \
//          a   a
//         /     \
//        t       p
// - Leaf nodes (t, p, b) indicate end of words

// 2. Compressed Trie / Patricia Trie
// - Chains of single-child nodes are merged into a single node storing a string
// - Reduces memory usage
// - Slightly more complex to implement
// - Example:
//     Words: "cat", "cap", "car"
//             root
//              |
//             ca
//           /  |  \
//          t   p   r

// 3. Suffix Trie
// - Stores all suffixes of a string
// - Useful for substring search, pattern matching, DNA sequence analysis
// - Memory usage is high: O(n^2) for string of length n
// - Example:
//     Word: "banana"
//     Suffixes: "banana", "anana", "nana", "ana", "na", "a"
//     Partial structure:
//             root
//              |
//              b
//              a
//              n
//              a
//              n
//              a

// 4. Ternary Search Trie (TST)
// - Each node has 3 pointers: left (<), middle (=), right (>)
// - Memory-efficient compared to standard trie
// - Supports ordered traversal
// - Example:
//     Words: "cat", "cap", "bat"
//             root 'c'
//            /   |   \
//          <     =    >
//         'b'    'a'   -
//        /       \
//      ...        t/p

//* -------------------------- OPERATIONS -------------------------- //
// 1. Insertion:
//     - Traverse characters from root
//     - Create new nodes for missing characters
//     - Mark end-of-word at last character
//     - Time Complexity: O(L)

// 2. Search:
//     - Traverse path for each character
//     - If path exists and end-of-word flag is true → word exists
//     - Time Complexity: O(L)

// 3. Prefix Search (Autocomplete):
//     - Follow path for given prefix
//     - Traverse subtree to collect all words with that prefix
//     - Time Complexity: O(P + K), P = prefix length, K = number of matching words

// 4. Deletion:
//     - Unmark end-of-word flag
//     - Remove nodes if they have no children and are not part of another word
//     - Time Complexity: O(L)

//* -------------------------- USE CASES / SCENARIOS -------------------------- //
// - Autocomplete / Search Suggestions: Google, IDE code completion
// - Spell Checking: Verify and suggest correct words
// - IP Routing: Longest prefix match in routing tables
// - Word Games / Dictionaries: Scrabble, Boggle
// - Pattern Matching / Substring Search: DNA or text analysis using suffix trie
// - Storing Large Datasets: Efficient storage for millions of strings with shared prefixes

//* -------------------------- ADVANTAGES -------------------------- //
// - Fast search, insertion, and prefix queries: O(L)
// - Efficient for prefix-based operations
// - Shared prefixes reduce redundant storage

//* -------------------------- DISADVANTAGES -------------------------- //
// - High memory usage for large alphabets (Standard Trie)
// - Complex implementation for compressed, suffix, and TST tries
// - Not ideal for sparse datasets with long strings and few shared prefixes
