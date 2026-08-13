#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            // Rotate the matrix by 90 degrees
            vector<vector<int>> rotated(n, vector<int>(n));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    rotated[c][n - 1 - r] = mat[r][c];
                }
            }
            mat = rotated;
        }
        return false;
    }
};

        
 
int main() {
    Solution solution;
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    bool result = solution.findRotation(mat, target);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}