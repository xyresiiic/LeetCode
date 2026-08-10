#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) 
        {
            for (int j = i; j < n - i - 1; j++) 
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

    int main() 
    {
        Solution solution;
        vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        solution.rotate(matrix);

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
