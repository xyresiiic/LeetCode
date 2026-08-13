#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr)
    {
        int m=arr.size();
        int n=arr[0].size();
        vector<int> ans;
        int minr=0, maxr=m-1;
        int minc=0, maxc=n-1;
        while (minr<=maxr && minc<=maxc)
        {
            for (int j = minc; j <= maxc; j++) 
            {
                ans.push_back(arr[minr][j]);
            }
            minr++;

            for (int i = minr; i <= maxr; i++) 
            {
                ans.push_back(arr[i][maxc]);
            }
            maxc--;

            if (minr <= maxr) 
            {
                for (int j = maxc; j >= minc; j--) 
                {
                    ans.push_back(arr[maxr][j]);
                }
                maxr--;
            }

            if (minc <= maxc) 
            {
                for (int i = maxr; i >= minr; i--) 
                {
                    ans.push_back(arr[i][minc]);
                }
                minc++;
            }
        }
        return ans;
    }
    
};

int main()
{
    Solution solution;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = solution.spiralOrder(arr);

    for (const auto& elem : result) 
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
        