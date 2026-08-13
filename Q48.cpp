#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    void rotate(vector<vector<int>>& matrix) 
    {
        //Tanspose the matrix
        int n = matrix.size();
        for (int i = 0; i < n; i++) 
        {
            for (int j = i; j < n; j++) 
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //rotate the matrix 
        for(int i = 0; i < n; i++) 
        {
            int left = 0;
            int right = n - 1;
            while(left < right) 
            {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
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

