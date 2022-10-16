#include <bits/stdc++.h>
using namespace std;
constexpr int inf = 1e9 + 9e1;
int n;
int a[200001];
int l[200002];
int r[200002];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    l[1] = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] < l[i - 1]) {
            l[i] = inf;
        } else {
            l[i] = a[i] - l[i - 1];
        }
    }
    if (l[n] == 0) {
        cout << "YES\n";
        return;
    }
    r[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < r[i + 1]) {
            r[i] = inf;
        } else {
            r[i] = a[i] - r[i + 1];
        }
    }
    r[n + 1] = 0;
    for (int i = 1; i < n; i++) {  // swap i and i + 1
        if (l[i - 1] == inf) break;
        if (r[i + 2] == inf) continue;
        if (a[i + 1] < l[i - 1]) continue;
        if (a[i] < r[i + 2]) continue;
        if (a[i] - r[i + 2] != a[i + 1] - l[i - 1]) continue;
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}