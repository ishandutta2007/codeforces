#include <bits/stdc++.h>
using namespace std;

class trie_t {
public:
    trie_t* g[2];
    int count;

    trie_t() : g{nullptr, nullptr}, count{0} {}

    static void change(trie_t* root, const int& val, const int& d) {
        for (int i = 30; i >= 0; i--) {
            const int b = (val >> i) & 1;
            if (root->g[b] == nullptr) root->g[b] = new trie_t();
            root = root->g[b];
            root->count += d;
        }
    }

    static int get_max(trie_t* root, const int& val) {
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            const int b = (val >> i) & 1;
            if (root->g[1 ^ b] && root->g[1 ^ b]->count) {
                ans ^= (1 << i);
                root = root->g[1 ^ b];
            } else {
                assert(root->g[b] && root->g[b]->count);
                root = root->g[b];
            }
        }
        return ans;
    }
};
trie_t* tree = new trie_t();
int q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    trie_t::change(tree, 0, 1);
    cin >> q;
    while (q--) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') trie_t::change(tree, x, 1);
        else if (c == '-') trie_t::change(tree, x, -1);
        else cout << trie_t::get_max(tree, x) << '\n';
    }
}