#include <bits/stdc++.h>
using namespace std;
int n, p;
int dp[200002];
constexpr int base = 1e9 + 7;
class Node {
  public:
    Node* g[2];
    bool is_member;

    Node() : is_member(0) { g[0] = g[1] = nullptr; }

    static void Add(Node* root, int val) {
        vector<int> temp;
        while (val > 0) {
            temp.push_back(val % 2);
            val /= 2;
        }
        reverse(temp.begin(), temp.end());
        for (auto&& x : temp) {
            if (!root->g[x]) root->g[x] = new Node();
            root = root->g[x];
        }
        root->is_member = 1;
    }

    static int Count(Node* root, int length_left, int dbg_val = 0) {
        // cerr << dbg_val << " " << length_left << '\n';
        if (length_left < 0) return 0;
        if (!root) return dp[length_left];
        int ans = 0;
        if (root->is_member) {
            ans = 1;
            if (root->g[0]) {
                if (root->g[0]->g[0])
                    root->g[0]->g[0]->is_member = 1;
                else
                    (ans += Count(nullptr, length_left - 2, dbg_val * 4)) %= base;
                (ans += Count(root->g[0], length_left - 1, dbg_val * 2)) %= base;
            } else {
                (ans += Count(nullptr, length_left - 2, dbg_val * 4)) %= base;
            }

            if (root->g[1]) {
                root->g[1]->is_member = 1;
                (ans += Count(root->g[1], length_left - 1, dbg_val * 2 + 1)) %= base;
            } else {
                (ans += Count(nullptr, length_left - 1, dbg_val * 2 + 1)) %= base;
            }
        } else {
            if (root->g[0]) (ans += Count(root->g[0], length_left - 1, dbg_val * 2)) %= base;
            if (root->g[1]) (ans += Count(root->g[1], length_left - 1, dbg_val * 2 + 1)) %= base;
        }
        // cerr << dbg_val << " " << root->is_member << ' ' << length_left << ' ' << ans << '\n';
        return ans % base;
    }
};
Node* root;

void solve() {
    cin >> n >> p;
    dp[0] = 1;
    for (int i = 0; i < p; i++) {
        (dp[i + 1] += dp[i]) %= base;
        (dp[i + 2] += dp[i]) %= base;
        if (i) (dp[i] += dp[i - 1]) %= base;
    }
    root = new Node();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        Node::Add(root, a);
    }
    cout << Node::Count(root, p) << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}