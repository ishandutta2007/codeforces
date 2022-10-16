#include <bits/stdc++.h>
using namespace std;
int n, m, len;
map<string, int> pos;
string s[100001];
string model;
string current;
vector<int> matches;
void backtrack(int u) {
    if (u == len) {
        if (pos.count(current)) {
            matches.push_back(pos[current]);
        }
    } else {
        current[u] = '_';
        backtrack(u + 1);
        current[u] = model[u];
        backtrack(u + 1);
    }
}
vector<int> g[100001];
vector<int> order;
int done[100001];
bool dfs(int u) {
    done[u] = 1;
    for (int v : g[u])
        if (!done[v]) {
            if (dfs(v)) return true;
        } else if (done[v] == 1) {
            return true;
        }
    done[u] = -1;
    order.push_back(u);
    return false;
}
void solve() {
    cin >> n >> m >> len;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        pos[s[i]] = i;
    }
    current.resize(len);
    for (int i = 1, mt; i <= m; i++) {
        cin >> model >> mt;
        matches.clear();
        backtrack(0);
        for (auto&& x : matches) {
            if (x == mt) {
                swap(x, matches.back());
                break;
            }
        }
        if (matches.empty() || (matches.back() != mt)) {
            cout << "NO\n";
            return;
        }
        matches.pop_back();
        for (auto&& x : matches) {
            g[mt].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!done[i]) {
            if (dfs(i)) {
                cout << "NO\n";
                return;
            }
        }
    }
    reverse(order.begin(), order.end());
    cout << "YES\n";
    for (auto&& x : order) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}