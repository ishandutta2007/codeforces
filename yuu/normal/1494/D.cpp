#include <bits/stdc++.h>
using namespace std;
int n;
int a[501][501];
int c[1001];
int r[1001];
int solve(vector<int>& e, int old_boss, int old_mx) {
    if (e.size() == 1) {
        c[e[0]] = a[e[0]][e[0]];
        return e[0];
    }
    int boss = ++n;
    int mx = 0;
    for (int i : e) {
        for (int j : e) mx = max(mx, a[i][j]);
        if (mx == old_mx) {
            boss = old_boss;
            n--;
        }
        c[boss] = mx;
        int split = partition(e.begin(), e.end(), [i, &mx](const int& j) { return a[i][j] == mx; }) - e.begin();
        assert(split && (split != e.size()));
        vector<int> other;
        while (e.size() > split) {
            other.push_back(e.back());
            e.pop_back();
        }
        if (e.size() > other.size()) {
            r[solve(e, boss, mx)] = boss;
            r[solve(other, boss, mx)] = boss;
        } else {
            r[solve(other, boss, mx)] = boss;
            r[solve(e, boss, mx)] = boss;
        }
        if (r[boss] == boss) r[boss] = 0;
        break;
    }
    return boss;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    vector<int> all;
    for (int i = 1; i <= n; i++) all.push_back(i);
    int boss = solve(all, 0, -1);
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << c[i] << " \n"[i == n];
    cout << boss << '\n';
    for (int i = 1; i <= n; i++)
        if (r[i]) {
            cout << i << ' ' << r[i] << '\n';
        }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}