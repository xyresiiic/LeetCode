#include <iostream>
#include <vector>
using namespace std;

class Solution {
    struct Node {
        int prod = 1;
        long long cnt[5] = {};
    };

    int n, k;
    vector<Node> tree;

    Node mergeNode(const Node& L, const Node& R) {
        Node res;

        res.prod = (L.prod * R.prod) % k;

        // Prefixes ending inside L
        for (int r = 0; r < k; ++r)
            res.cnt[r] = L.cnt[r];

        // Prefixes containing all of L + a prefix of R
        for (int r = 0; r < k; ++r) {
            int nr = (L.prod * r) % k;
            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    Node makeNode(long long x) {
        Node node;
        node.prod = x % k;
        node.cnt[node.prod] = 1;
        return node;
    }

    void build(int p, int l, int r, const vector<int>& nums) {
        if (l == r) {
            tree[p] = makeNode(nums[l]);
            return;
        }

        int m = l + (r - l) / 2;
        build(p * 2, l, m, nums);
        build(p * 2 + 1, m + 1, r, nums);

        tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            tree[p] = makeNode(val);
            return;
        }

        int m = l + (r - l) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, val);
        else
            update(p * 2 + 1, m + 1, r, idx, val);

        tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
    }

    Node query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return tree[p];

        int m = l + (r - l) / 2;

        if (qr <= m)
            return query(p * 2, l, m, ql, qr);

        if (ql > m)
            return query(p * 2 + 1, m + 1, r, ql, qr);

        Node L = query(p * 2, l, m, ql, qr);
        Node R = query(p * 2 + 1, m + 1, r, ql, qr);

        // Order matters because we're dealing with prefixes.
        return mergeNode(L, R);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;

        tree.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // This update persists.
            update(1, 0, n - 1, index, value);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back((int)res.cnt[x]);
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    vector<vector<int>> queries = {
        {0, 6, 1, 2},
        {2, 7, 0, 3},
        {4, 8, 2, 1}
    };

    vector<int> result = solution.resultArray(nums, k, queries);
    cout << "Result: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}