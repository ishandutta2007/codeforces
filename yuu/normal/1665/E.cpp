#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];

class Trie {
  public:
    class Node {
      public:
        vector<int> pos;
        int next[2];
        Node() { next[0] = next[1] = 0; }
    };
    vector<Node> nodes;

    Trie() {
        nodes.reserve(6e5);
        Clear();
    }

    void Clear() {
        nodes.clear();
        nodes.emplace_back();
    }

    void Insert(int x, int id) {
        int root = 0;
        for (int i = 29; i >= 0; i--) {
            if (!nodes[root].next[(x >> i) & 1]) {
                nodes[root].next[(x >> i) & 1] = nodes.size();
                nodes.emplace_back();
            }
            root = nodes[root].next[(x >> i) & 1];
            nodes[root].pos.push_back(id);
        }
    };

    int FindMinOr(int l, int r) {
        vector<int> special_append;
        int root = 0;
        int ans = 0;
        for (int i = 29; i >= 0; i--) {
            bool must_one = false;
            auto it = partition(special_append.begin(), special_append.end(), [i](const int& x) { return ((x >> i) & 1) == 0; });
            if ((root == -1) || (nodes[root].next[0] == 0)) {  // can only use special_append
                int cnt = 0;
                if ((special_append.size() < 2) || ((special_append[1] >> i) & 1)) {
                    must_one = true;
                }
            } else {  // can use a node
                if ((special_append.size() < 2) || ((special_append[1] >> i) & 1)) {
                    bool has_special = (!special_append.empty()) && (((special_append[0] >> i) & 1) == 0);
                    auto& node = nodes[nodes[root].next[0]];
                    int low_pos = lower_bound(node.pos.begin(), node.pos.end(), l) - node.pos.begin();
                    if (low_pos >= node.pos.size()) {
                        must_one = true;
                    } else if (node.pos[low_pos] > r) {
                        must_one = true;
                    } else if (low_pos + 1 == node.pos.size()) {
                        if (!has_special) {
                            must_one = true;
                            special_append.push_back(a[node.pos[low_pos]]);
                        }
                    } else if (node.pos[low_pos + 1] > r) {
                        if (!has_special) {
                            must_one = true;
                            special_append.push_back(a[node.pos[low_pos]]);
                        }
                    } else {  // can zero
                    }
                }
            };
            if (must_one == false) special_append.erase(it, special_append.end());

            ans *= 2;
            ans += must_one;
            if (root != -1) {
                root = nodes[root].next[must_one];
                if (root == 0) root = -1;
            }
        }
        return ans;
    }
} trie;
void solve() {
    cin >> n;
    trie.Clear();
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) trie.Insert(a[i], i);
    cin >> q;
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        cout << trie.FindMinOr(l, r) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}