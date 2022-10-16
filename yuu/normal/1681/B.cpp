#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;
    int top = 1;
    for (int i = 1, b; i <= m; i++) {
        cin >> b;
        top += b;
        while (top > n) top -= n;
    }
    cout << a[top] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}