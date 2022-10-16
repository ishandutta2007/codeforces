#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001];
int cnt[1'000'001];
vector<pair<int, int>> ans;
bool make(int x) {
    ans.clear();
    for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    for (int i = n; i >= 1; i--)
        if (cnt[a[i]]) {
            if (a[i] >= x) return 0;
            if (!cnt[x - a[i]]--) {
                cnt[x - a[i]] = 0;
                return 0;
            }
            if (!cnt[a[i]]--) return 0;
            ans.emplace_back(a[i], x - a[i]);
            x = a[i];
        }
    return 1;
}

void solve() {
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++)
        if (make(a[i] + a[n])) {
            cout << "YES\n";
            cout << a[i] + a[n] << '\n';
            for (auto&& [x, y] : ans) cout << x << ' ' << y << '\n';
            for (int j = 1; j <= n; j++) cnt[a[j]] = 0;
            return;
        }
    cout << "NO\n";
    for (int i = 1; i <= n; i++) cnt[a[i]] = 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}