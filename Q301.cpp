class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int index, int left, int right, int balance, string cur) {
        if (index == s.size()) {
            if (left == 0 && right == 0 && balance == 0) {
                ans.insert(cur);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            if (left > 0) {
                dfs(s, index + 1, left - 1, right, balance, cur);
            }

            dfs(s, index + 1, left, right, balance + 1, cur + c);
        }
        else if (c == ')') {
            if (right > 0) {
                dfs(s, index + 1, left, right - 1, balance, cur);
            }

            if (balance > 0) {
                dfs(s, index + 1, left, right, balance - 1, cur + c);
            }
        }
        else {
            dfs(s, index + 1, left, right, balance, cur + c);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;

        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        dfs(s, 0, left, right, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};