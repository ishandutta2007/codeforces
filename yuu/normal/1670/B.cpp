#include <bits/stdc++.h>
using namespace std;
int n, k;
int spec[256];
string s;
class Node {
public:
    Node* prev;
    bool spec;
    bool done;
} node[100000];
vector<Node*> special;
vector<Node*> new_special;
void solve() {
    cin >> n >> s;
    for (int i = 'a'; i <= 'z'; i++) spec[i] = 0;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        char c;
        cin >> c;
        spec[c] = 1;
    }
    int last_spec = 0;
    for (int i = 0; i < n; i++)
        if (spec[s[i]]) {
            last_spec = i;
        }

    if (last_spec == 0) {
        cout << "0\n";
        return;
    }

    for (int i = 0; i <= last_spec; i++) node[i].spec = spec[s[i]];
    for (int i = 0; i <= last_spec; i++) node[i].done = 0;
    node[0].prev = nullptr;
    for (int i = 1; i <= last_spec; i++) node[i].prev = &node[i - 1];
    special.clear();
    for (int i = 0; i <= last_spec; i++)
        if (node[i].spec) special.push_back(&node[i]);
    int ans = 0;
    while (true) {
        bool stop = true;
        new_special.clear();
        for (auto&& p : special) {
            if (p->prev) {
                stop = false;
                p->prev->done = true;
                p->prev = p->prev->prev;
            }
        }
        if (stop) break;
        ans++;
        for (auto&& p : special)
            if (!p->done) new_special.push_back(p);
        swap(special, new_special);
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}