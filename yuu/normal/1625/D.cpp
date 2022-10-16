#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[300001];
int separator;
int significant;
map<int, vector<pair<int, int>>> groups;
vector<int> ans;

class BinaryTrie {
  public:
    int id;
    BinaryTrie* g[2];

    BinaryTrie() : id(-1), g{nullptr, nullptr} {}

    ~BinaryTrie() {
        if (g[0]) delete (g[0]);
        if (g[1]) delete (g[1]);
    }

    static void Add(BinaryTrie* root, int num, int id) {
        static vector<int> bits;
        bits.clear();
        for (int i = 1; i <= 30; i++) {
            bits.push_back(num % 2);
            num /= 2;
        }
        reverse(bits.begin(), bits.end());
        for (auto&& b : bits) {
            if (root->g[b] == nullptr) root->g[b] = new BinaryTrie();
            root = root->g[b];
            root->id = id;
        }
    }

    static pair<int, int> FindPair(BinaryTrie* root, BinaryTrie* paired, int value) {
        if (value == 0) return {root->id, paired->id};
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++) {
                if (static_cast<bool>(root->g[a]) && static_cast<bool>(paired->g[b])) {
                    if ((a ^ b) > (value % 2)) {
                        return {root->g[a]->id, paired->g[b]->id};
                    }
                }
            }
        for (int a = 0; a <= 1; a++)
            for (int b = 0; b <= 1; b++) {
                if (static_cast<bool>(root->g[a]) && static_cast<bool>(paired->g[b])) {
                    if ((a ^ b) >= (value % 2)) {
                        auto res = FindPair(root->g[a], paired->g[b], value / 2);
                        if (res.first) return res;
                    }
                }
            }
        return {0, 0};
    }
};

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    if (k == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
        return;
    }

    separator = __lg(k) + 1;
    significant = (1 << separator) - 1;

    int reversed_k = 0;
    for (int i = 1; i <= 30; i++) {
        (reversed_k *= 2) += k % 2;
        k /= 2;
    }
    for (int i = 1; i <= n; i++) groups[a[i] >> separator].emplace_back(a[i] & significant, i);
    for (auto&& [group, items] : groups) {
        auto root = new BinaryTrie();
        for (auto&& [val, id] : items) {
            BinaryTrie::Add(root, val, id);
        }
        auto res = BinaryTrie::FindPair(root, root, reversed_k);
        if (res.first) {
            ans.push_back(res.first);
            ans.push_back(res.second);
        } else {
            ans.push_back(items[0].second);
        }
        delete root;
        items.clear();
    }
    if (ans.size() <= 1) {
        cout << "-1\n";
        return;
    }
    cout << ans.size() << '\n';
    for (auto&& x : ans) cout << x << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}