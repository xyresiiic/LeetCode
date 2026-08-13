#include<iostream>
#include<vector>
using namespace std;

//Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        // First pass: mark the rows and columns that need to be set to zero
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Second pass: set the marked rows and columns to zero
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }  
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    solution.setZeroes(matrix);

    for (const auto& row : matrix) 
    {
        for (const auto& elem : row) 
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;

}