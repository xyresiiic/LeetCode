#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:

    set<string> merge(set<string> a, set<string> b)
    {
        set<string> res;

        for (auto &x : a)
        {
            for (auto &y : b)
            {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> parse(string &expression, int &i)
    {
        set<string> result;
        set<string> current;

        current.insert("");

        while (i < expression.size() && expression[i] != '}') 
        {

            if (expression[i] == ',')
            {
                for (auto &s : current)
                    result.insert(s);

                current.clear();
                current.insert("");
                i++;
            }

            else if (expression[i] == '{')
            {
                i++;

                set<string> inside = parse(expression, i);

                current = merge(current, inside);

                i++;
            }

            else
            {
                set<string> single;

                single.insert(string(1, expression[i]));

                current = merge(current, single);

                i++;
            }
        }

        for (auto &s : current)
            result.insert(s);

        return result;
    }

    vector<string> braceExpansionII(string expression)
    {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};

int main()
{
    Solution solution;

    string expression = "{a,b}{c,{d,e}}";
    vector<string> result = solution.braceExpansionII(expression);

    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}