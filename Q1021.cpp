#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s)
    {
        string ans;
        int depth = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                if (depth > 0)
                    ans += c;
                depth++;
            }
            else
            {
                depth--;

                if (depth > 0)
                    ans += c;
            }
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    string s = "(()())(())";
    string result = solution.removeOuterParentheses(s);
    cout << result << endl; // Output: "()()()"
    return 0;
}