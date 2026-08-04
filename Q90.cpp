#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, vector<int>& nums, vector<int>& temp)
    {
        ans.push_back(temp);

        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i - 1])
                continue;

            temp.push_back(nums[i]);
            solve(i + 1, nums, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        solve(0, nums, temp);

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);

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