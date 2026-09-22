#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        deque<int> dq;
        long long sum = 0;
        int left = 0;
        int ans = 0;

        for (int right = 0; right < chargeTimes.size(); right++) {
            sum += runningCosts[right];

            while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[right])
                dq.pop_back();

            dq.push_back(right);

            while (!dq.empty() &&
                   chargeTimes[dq.front()] +
                   (long long)(right - left + 1) * sum > budget) {

                sum -= runningCosts[left];

                if (dq.front() == left)
                    dq.pop_front();

                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> chargeTimes = {1, 3, 5, 2, 4};
    vector<int> runningCosts = {2, 1, 3, 4, 5};
    long long budget = 10;

    int result = solution.maximumRobots(chargeTimes, runningCosts, budget);
    cout << "Maximum number of robots: " << result << endl;

    return 0;
}