#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;
int n;
int a[1000001];
queue<int> q[8192];
int f[8192];
// Update f[x] = y
void update(int x, int y) {
    if (f[x] > 5000) f[x] = 5000;
    while (f[x] > y) {
        q[f[x]].push(x);
        f[x]--;
    }
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < 8192; i++) f[i] = 5001;
    update(0, 0);
    for (int i = 1, old; i <= n; i++) {
        while (!q[a[i]].empty()) {
            int x = q[a[i]].front();
            q[a[i]].pop();
            update(x ^ a[i], a[i]);
        }
    }
    vector<int> ans;
    for (int i = 0; i < 8192; i++)
        if (f[i] <= 5000) ans.push_back(i);
    cout << ans.size() << '\n';
    for (auto&& x : ans) cout << x << ' ';
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}