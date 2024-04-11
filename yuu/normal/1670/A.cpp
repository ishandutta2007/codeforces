#include <bits/stdc++.h>
using namespace std;
int n;
int a[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int neg = 0;
    for (int i = 1; i <= n; i++) neg += (a[i] < 0);
    for (int i = 1; i <= neg; i++) a[i] = -abs(a[i]);
    for (int i = neg + 1; i <= n; i++) a[i] = abs(a[i]);
    if (is_sorted(a + 1, a + n + 1)) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}