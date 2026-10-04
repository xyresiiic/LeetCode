class Solution
{
public:
    vector<string> ans;

    void solve(string cur, int open, int close, int n)
    {
        if (cur.size() == 2 * n)
        {
            ans.push_back(cur);
            return;
        }

        if (open < n)
        {
            solve(cur + "(", open + 1, close, n);
        }

        if (close < open)
        {
            solve(cur + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        solve("", 0, 0, n);
        return ans;
    }
};