#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, vector<int>& temp)
    {
        if (i == nums.size()) 
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        solve(i + 1, nums, temp);

        temp.pop_back();
        solve(i + 1, nums, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);

    for (const auto& subset : result)
    {
        cout << "[";
        for (size_t i = 0; i < subset.size(); ++i)
        {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}