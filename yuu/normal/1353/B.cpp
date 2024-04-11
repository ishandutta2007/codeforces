#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[31];
int b[31];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= k; i++) {
        if (a[i] >= b[n - i + 1]) break;
        swap(a[i], b[n - i + 1]);
    }
    cout << accumulate(a + 1, a + n + 1, 0) << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}