#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int depth = 0;
        int ans = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                depth++;
                ans = max(ans, depth);
            }
            else if (c == ')')
            {
                depth--;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "(1+(2*3)+((8)/4))+1";
    int result = solution.maxDepth(s);
    cout << result << endl;
    return 0;
}