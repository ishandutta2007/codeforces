#include <bits/stdc++.h>
using namespace std;
int k, n;
int v;
map<string, int> id = {{"white", 0}, {"yellow", 1}, {"green", 2}, {"blue", 3}, {"red", 4}, {"orange", 5}};

constexpr int64_t base = 1'000'000'007;
int64_t w[64];
class binary_trie {
  public:
    using pointer = binary_trie*;
    pointer g[2];
    int depth;
    int colour;
    int64_t f[6];
    binary_trie(int depth, bool dummy = false) : depth(depth), colour(-1) {
        g[0] = g[1] = nullptr;
        if (dummy)
            for (int i = 0; i < 6; i++) f[i] = w[depth];
        else
            for (int i = 0; i < 6; i++) f[i] = 0;
    }

    static void add(pointer root, int64_t x, int c) {
        vector<int> dir;
        while (x > 0) {
            dir.push_back(x % 2);
            x /= 2;
        }
        dir.pop_back();
        reverse(dir.begin(), dir.end());
        for (auto&& b : dir) {
            if (root->g[b] == nullptr) {
                root->g[b] = new binary_trie(root->depth - 1);
            }
            root = root->g[b];
        }
        root->colour = c;
    }
    void get() {
        if (depth == 1) {
            for (int c = ((colour == -1) ? 0 : colour); c <= ((colour == -1) ? 5 : colour); c++) {
                f[c] = 1;
            }
            return;
        }
        if (g[0] == nullptr)
            g[0] = new binary_trie(depth - 1, true);
        else
            g[0]->get();
        if (g[1] == nullptr)
            g[1] = new binary_trie(depth - 1, true);
        else
            g[1]->get();
        for (int c = ((colour == -1) ? 0 : colour); c <= ((colour == -1) ? 5 : colour); c++) {
            int64_t sum_left = 0;
            int64_t sum_right = 0;
            for (int j = 0; j < 6; j++)
                if ((j != c) && (j != (c ^ 1))) {
                    sum_left += g[0]->f[j];
                    sum_right += g[1]->f[j];
                }
            sum_left %= base;
            sum_right %= base;
            f[c] = (sum_left * sum_right) % base;
        }
    }
    void debug(int64_t id) {
        if (g[0] != nullptr) {
            g[0]->debug(id * 2);
        }
        if (g[1] != nullptr) {
            g[1]->debug(id * 2 + 1);
        }
        cerr << "ID: " << id << ' ' << depth << '\n';
        for (int i = 0; i < 6; i++) cerr << f[i] << " \n"[i + 1 == 6];
    }
};

void solve() {
    cin >> k >> n;
    w[1] = 1;
    for (int i = 2; i <= k; i++) {
        w[i] = (((w[i - 1] * w[i - 1])%base) * 16) % base;
    }
    auto root = new binary_trie(k);
    int64_t v;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> v >> s;
        binary_trie::add(root, v, id[s]);
        // cerr << s << ' ' << id[s] << '\n';
    }
    // root->debug(1);
    root->get();
    int64_t ans = 0;
    for (int i = 0; i < 6; i++) ans += root->f[i];
    ans %= base;
    cout << ans << '\n';
    // root->debug(1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}