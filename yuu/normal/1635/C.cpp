#include <bits/stdc++.h>
using namespace std;
int n;
int a[200002];
vector<tuple<int, int, int>> ans;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (a[n - 1] > a[n]) {
        cout << "-1\n";
        return;
    }
    if (a[n] < 0) {
        if (is_sorted(a + 1, a + n + 1))
            cout << "0\n";
        else
            cout << "-1\n";
    } else {
        cout << n - 2 << '\n';
        for (int i = n - 2; i >= 1; i--) cout << i << ' ' << n - 1 << ' ' << n << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}