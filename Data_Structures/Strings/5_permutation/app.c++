#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> Permutation(string str) {
    vector<string> result;

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (i != j) {
                string value = "";
                value += str[i];
                value += str[j];
                result.push_back(value);
            }
        }
    }
    return result;
}


void perm(char str[], int k) {
    static int A[10] = {0}; // To track used characters
    static char res[10];    // To store current permutation
    int i;

    if (str[k] == '\0') {  // Base case: end of string
        res[k] = '\0';     // Null-terminate the result
        cout << res << endl; // Print the permutation
    } else {
        for (i = 0; str[i] != '\0'; i++) { // Iterate over the string
            if (A[i] == 0) { // If the character is not used
                res[k] = str[i]; // Set character in the result
                A[i] = 1;        // Mark as used
                perm(str, k + 1); // Recurse for the next character
                A[i] = 0;        // Backtrack: unmark the character
            }
        }
    }
}




int main(){



}
