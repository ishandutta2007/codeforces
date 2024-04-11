#include <bits/stdc++.h>
using namespace std;
int n;
vector<int64_t> s[200001];
vector<int> order;
int u[200001];
int64_t ans[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> u[i];
    for (int i = 1; i <= n; i++) s[i].clear();
    order.clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        s[u[i]].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        sort(s[i].begin(), s[i].end());
        reverse(s[i].begin(), s[i].end());
        for (int j = 1; j < s[i].size(); j++) s[i][j] += s[i][j - 1];
    }
    for (int i = 1; i <= n; i++) order.push_back(i);
    sort(order.begin(), order.end(), [](const int &a, const int &b) { return s[a].size() > s[b].size(); });
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = 1, mx = n; i <= n; i++) {
        while ((!order.empty()) && (s[order.back()].size() < i)) order.pop_back();
        if (order.empty()) break;
        for (auto &&id : order) {
            int sz = s[id].size() - s[id].size() % i;
            ans[i] += s[id][sz - 1];
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}