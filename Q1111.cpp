#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        vector<int> ans;
        int depth = 0;

        for (char c : seq)
        {
            if (c == '(')
            {
                depth++;
                ans.push_back(depth % 2);
            }
            else
            {
                ans.push_back(depth % 2);
                depth--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    string seq = "(()())";
    vector<int> result = solution.maxDepthAfterSplit(seq);

    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}