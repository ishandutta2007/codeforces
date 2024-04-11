#include <bits/stdc++.h>
using namespace std;
int nx[1000002][20];
int a[1000002];
int x[1000002];
int n;
vector<pair<int, int>> tests[1000002];
class trie {
  public:
    trie* g[2];
    int right_most;
    trie() : right_most(0) { g[0] = g[1] = nullptr; }

    static void add(trie* root, int x, int pos) {
        for (int i = 19; i >= 0; i--) {
            root->right_most = pos;
            int b = (x >> i) & 1;
            if (root->g[b] == nullptr) root->g[b] = new trie();
            root = root->g[b];
        }
        root->right_most = pos;
    }

    void add(int x, int pos) { add(this, x, pos); }
    // find x such that x ^ current < a and x is right most
    int find(int current, int a, int level = 19) {
        if (level == -1) return -1;
        int o = (current >> level) & 1;
        if ((a >> level) & 1) {
            int res = -1;
            if (g[o] != nullptr) res = g[o]->right_most;
            if (g[1 - o] != nullptr) {
                if (g[1 - o]->right_most > res) res = max(res, g[1 - o]->find(current, a, level - 1));
            }
            return res;
        } else {
            if (g[o] == nullptr) return -1;
            return g[o]->find(current, a, level - 1);
        }
    }
} tree;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i >= 1; i--) {
        for (int j = 0; j < 20; j++) {
            if ((a[i] >> j) & 1)
                nx[i][j] = nx[i + 1][j];
            else
                nx[i][j] = i;
        }
    }
    for (int i = 1; i <= n; i++) x[i] = x[i - 1] ^ a[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        sort(nx[i], nx[i] + 20);

        for (int j = 0, k, current = a[i]; j < 20; j++) {
            k = j;
            while ((k < 19) && (nx[i][k + 1] == nx[i][j])) k++;
            // cerr << "ijk: " << i << ' ' << j << ' ' << k << '\n';
            if (nx[i][j] - i > ans) tests[nx[i][j] - 1].emplace_back(i, current);
            // cerr << nx[i][j] << ' ' << current << '\n';
            current &= a[nx[i][j]];
            // cerr << "ijk: " << i << ' ' << j << ' ' << k << ' ' << current << ' ' << nx[i][j] << '\n';
            j = k;
            if (j == 19) {
                if (n + 1 - i > ans) tests[n].emplace_back(i, current);
            }
        }

        tree.add(x[i], i);
        // cerr<<tree.right_most<<'\n';
        for (auto&& [b, a] : tests[i]) {
            if (i - b + 1 < ans) continue;
            int right_most = tree.find(x[b - 1], a);
            // cerr << i << ' ' << b << ' ' << a << ' ' << right_most << '\n';
            ans = max(ans, right_most - b + 1);
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}