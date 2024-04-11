#include <bits/stdc++.h>
using namespace std;
int n[4], m;
int a[4][150001];
vector<int> b[150001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<pair<int, int>> s;
void solve() {
    for (int i = 0; i < 4; i++) cin >> n[i];
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= n[i]; j++) cin >> a[i][j];
    }
    for (int i = 1; i < 4; i++) {
        while (!q.empty()) q.pop();
        q.emplace(1e9, -1);
        for (int j = 1; j <= n[i - 1]; j++) q.emplace(a[i - 1][j], j);
        for (int j = 1; j <= n[i]; j++) b[j].clear();
        cin >> m;
        for (int j = 1, x, y; j <= m; j++) {
            cin >> x >> y;
            b[y].push_back(x);
        }
        for (int j = 1; j <= n[i]; j++) {
            sort(b[j].begin(), b[j].end());
            while (binary_search(b[j].begin(), b[j].end(), q.top().second)) {
                s.push_back(q.top());
                q.pop();
            }
            a[i][j] += q.top().first;
            if (a[i][j] > 1e9) a[i][j] = 1e9;
            while (!s.empty()) {
                q.push(s.back());
                s.pop_back();
            }
        }
    }
    int ans = *min_element(a[3] + 1, a[3] + n[3] + 1);
    if (ans >= 1e9) ans = -1;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}