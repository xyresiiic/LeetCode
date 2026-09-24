#include<iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        int target = total - x;

        if (target < 0)
            return -1;

        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++)
        {
            sum += nums[right];

            while (left <= right && sum > target)
            {
                sum -= nums[left];
                left++;
            }

            if (sum == target)
            {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return maxLen == -1 ? -1 : n - maxLen;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    int result = solution.minOperations(nums, x);
    cout << "Minimum operations: " << result << endl; // Output: 2
    return 0;
}