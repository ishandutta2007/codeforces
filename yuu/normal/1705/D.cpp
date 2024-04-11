#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
vector<int> pos[2][2];
vector<pair<int, int>> pairs;
int ft[200001];
void update(int u) {
    for (; u <= n; u += u & -u) ft[u]++;
}
int get(int u) {
    int res = 0;
    for (; u > 0; u -= u & -u) res += ft[u];
    return res;
}
void solve() {
    cin >> n >> s >> t;
    if (s[0] != t[0]) {
        cout << "-1\n";
        return;
    }
    if (s.back() != t.back()) {
        cout << "-1\n";
        return;
    }
    pos[0][0].clear();
    pos[0][1].clear();
    pos[1][0].clear();
    pos[1][1].clear();
    for (int i = 1; i < n; i++) {
        pos[0][s[i] == s[i - 1]].emplace_back(i);
        pos[1][t[i] == t[i - 1]].emplace_back(i);
    }
    if (pos[0][0].size() != pos[1][0].size()) {
        cout << "-1\n";
        return;
    }
    pairs.clear();
    for (int i = 0; i < pos[0][0].size(); i++) {
        pairs.emplace_back(pos[0][0][i], pos[1][0][i]);
    }
    for (int i = 0; i < pos[0][1].size(); i++) {
        pairs.emplace_back(pos[0][1][i], pos[1][1][i]);
    }
    sort(pairs.begin(), pairs.end());
    reverse(pairs.begin(), pairs.end());
    for (int i = 1; i <= n; i++) ft[i] = 0;
    int64_t cost = 0;
    for (auto&& [a, b] : pairs) {
        cost += get(b);
        update(b);
    }
    cout << cost << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}