#include <bits/stdc++.h>
using namespace std;
int n;
int a[200000];
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int total_and = (1 << 20) - 1;
    for (int i = 0; i < n; i++)
        if (a[i] != i) total_and &= a[i];
    cout << total_and << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}