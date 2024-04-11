#include <bits/stdc++.h>
using namespace std;
int n, h;
int a[1001];
void solve() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int sum = a[n] + a[n - 1];
    int cnt = h / sum * 2;
    h %= sum;
    if (h > 0) {
        h -= a[n];
        cnt++;
    }
    if (h > 0) cnt++;
    cout << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}