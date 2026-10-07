#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char c : s)
        {
            if (c == '(')
            {
                open++;
            }
            else
            {
                if (open > 0)
                    open--;
                else
                    ans++;
            }
        }

        ans += open;

        return ans;
    }
};

int main() {
    Solution solution;
    string s = "())";
    int result = solution.minAddToMakeValid(s);
    cout << "Minimum additions needed: " << result << endl;
    return 0;
}