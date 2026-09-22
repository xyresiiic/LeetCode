#include<iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<long long> resultArray(vector<int>& nums, int k)
    {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums)
        {
            vector<long long> newDp(k, 0);

            newDp[num % k]++;

            for (int r = 0; r < k; r++)
            {
                if (dp[r] > 0) {
                    int newR = (r * num) % k;
                    newDp[newR] += dp[r];
                }
            }

            dp = newDp;

            for (int r = 0; r < k; r++)
            {
                ans[r] += dp[r];
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 3;

    vector<long long> result = solution.resultArray(nums, k);

    for (long long count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}