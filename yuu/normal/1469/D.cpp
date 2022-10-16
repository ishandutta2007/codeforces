#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ans;
int a[200001];
int turn = 2;
void solve() {
    int n;
    cin >> n;
    // n = ++turn;
    for (int i = 1; i <= n; i++) a[i] = i;
    ans.clear();
    int last = n - 1;
    while (a[n] > 2) {
        int r = sqrt(a[n]);
        while (r * r > a[n]) r--;
        if (r == 1) r = 2;
        assert(a[r] == r);
        while (last > r) {
            ans.emplace_back(last, n);
            a[last] = (a[last] - 1) / a[n] + 1;
            assert(a[last] == 1);
            last--;
        }
        int nx = (a[n] - 1) / r + 1;
        assert(nx >= r);
        ans.emplace_back(n, r);
        a[n] = nx;
        if (r == 2) {
            while (a[n] > 2) {
                ans.emplace_back(n, r);
                a[n] = (a[n] - 1) / r + 1;
            }
        }
        ans.emplace_back(r, n);
        a[r] = (a[r] - 1) / a[n] + 1;
        assert(a[r] == 1);
        last = r - 1;
    }
    cerr << n << '\n';
    assert(a[n] == 2);
    for (int i = 1; i < n; i++) assert(a[i] == 1);
    assert(ans.size() <= n + 5);
    cout << ans.size() << '\n';
    for (auto&& [x, y] : ans) cout << x << ' ' << y << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}