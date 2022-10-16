#include <bits/stdc++.h>
using namespace std;
int n, d;
int a[101];
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    if ((a[n] <= d) || (a[1] + a[2] <= d)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}