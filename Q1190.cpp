#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> st;
        string cur = "";

        for (char c : s)
        {
            if (c == '(')
            {
                st.push(cur);
                cur = "";
            }
            else if (c == ')')
            {
                reverse(cur.begin(), cur.end());

                cur = st.top() + cur;
                st.pop();
            }
            else
            {
                cur += c;
            }
        }

        return cur;
    }
};

int main()
{
    Solution solution;
    string s = "(ed(et(oc))el)";
    string result = solution.reverseParentheses(s);
    cout << result << endl;
    return 0;
}