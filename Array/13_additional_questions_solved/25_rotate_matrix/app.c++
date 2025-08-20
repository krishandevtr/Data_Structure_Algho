#include <iostream>
#include <vector>
using namespace std;

//? THis is also known as the rotate the image 

//* The approach to this problem will be create an copy matrix of size n *m then place the elements in the correct order


vector<vector<int>> bruteForce(const vector<vector<int>>& matrix,int n,int m) {
    vector<vector<int>> result(m, vector<int>(n)); //* sc: bigO(n*m)
    for(int i = 0;i<n; i++){
        for(int j = 0; j<m; j++){
            result[j][(n-1)-i] =  matrix[i][j]; // * bigO(n*m)
        }
    }
     return result;   
}


//* It is easy to do the Optimization because we need to find the transpose of the matrix and reverse the matrix
/**
 * ! First column is the first row
 * ! Second column is the second row 
 * ! Third column is the third row
 * * How to transpose the given matrix it is simple when you look the diagonal it doesnot change then if you observe the tranporsed matrix you can see,
 * * take a small square , first two element in the row and the two elements in the second row swap the other elements that is not part of the diagonal
 */

vector<vector<int>> rotateMatrix(vector<vector<int>>& mat,int n , int m) {
    for (int i = 0; i < n; i++) {//Transpose
        for (int j = i + 1; j < m; j++) { // j = i + 1 avoids redundant swaps
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int k =0; k<m; k++){
        reverse(mat[k].begin(), mat[k].end());
    }

}
    
