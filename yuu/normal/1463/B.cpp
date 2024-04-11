#include <bits/stdc++.h>
using namespace std;
int n;
int a[51];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int64_t cost[2];
    cost[0] = cost[1] = 0;
    for (int i = 1; i <= n; i++) {
        cost[i % 2] += abs(a[i] - 1);
    }
    int mod = cost[1] < cost[0];
    for (int i = 1; i <= n; i++)
        if (i % 2 == mod) cout << 1 << " \n"[i == n];
        else cout << a[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}