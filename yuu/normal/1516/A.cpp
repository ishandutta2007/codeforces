#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[101];
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        while (a[i] && k) {
            a[i]--;
            k--;
            a[n]++;
        }
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}