#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<int>> ans(cols, vector<int>(rows));

        for (int i = 0; i < rows; i++) 
        {
            for (int j = 0; j < cols; j++) 
            {
                ans[j][i] = matrix[i][j];
            }
        }

        return ans;
    }
};


int main() 
{
    Solution solution;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> transposedMatrix = solution.transpose(matrix);

    for (const auto& row : transposedMatrix) 
    {
        for (const auto& elem : row) 
        {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}