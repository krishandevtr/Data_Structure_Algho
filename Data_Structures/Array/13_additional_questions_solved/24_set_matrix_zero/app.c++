#include <iostream>
#include <vector>
//*Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
using namespace std;

void markRow(int i, vector<vector<int>> &arr, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1; // Mark as -1 (temporary marker)
        }
    }
} //*n

// Function to mark an entire column with -1 (except where the element is 0)
void markCol(int j, vector<vector<int>> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1; // Mark as -1 (temporary marker)
        }
    }
} //* m

// Brute force approach to solve the problem
void bruteForce(vector<vector<int>> &arr, int n, int m)
{
    // First pass: Mark rows and columns with -1 for all 0 elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(i, arr, m); // Mark the entire row
                markCol(j, arr, n); // Mark the entire column
            }
        }
    } //* n*m

    // Second pass: Replace all -1s with 0s
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
} //* n*m

void betterSol( vector<vector<int>> &arr, int n, int m)
{
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                col[i] = 1;
                row[j] = 1;
            }
        }
    }// * n +m 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (col[i] || row[j])
            {
                arr[i][j] = 0;
            }
        } //* n +m
    }
}

// * Big O( 2(n *m)) = n*m , bigO(n+m)

/**
 * ! In here we cannot optimize the matrix time because we cannot change the (n2)
 * ! But we can optimize the space to 1 in above algho we are taking an array of n and m to hash 
 * ! But we can make that more simpler because , we can use the col[0] and row [0] to be the marker
 * ! But there is a problem when we visualize the matrix we can see that the first el will be common to the row and the col so we need to avoid the collison it is not a big deal so use a variable for the col[o] or or row[0]
 *  */ 


vector<vector<int>> optimal(vector<vector<int>>matrix,int n, int m){
    int col0;
    for(int i =0; i<n ; i++){
        for (int j = 0; j<m; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0; 
                if(j!=0){
                  matrix[0][j] = 0; 
              }else{
                col0 = 0;
              }
            }

        }
    }
    for(int i =1; i<n ; i++){
        for (int j = 1; j<m; j++){
            if(matrix[0][j]!=0){
                //check for the columns or row
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix [i][j] = 0;
                }
            }

        }

    }
    if(matrix[0][0] == 0){
        for(int j = 0; j<m;j++ ){
            matrix[0][j] =0;
        }
    }
    if(col0 == 0){
        for(int i= 0; i<m;i++ ){
            matrix[i][0] =0;
        }
    }

    return matrix;

}