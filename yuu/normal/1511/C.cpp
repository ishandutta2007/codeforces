#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[300001];
void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1, t; i <= q; i++) {
        cin >> t;
        int pos = 1;
        while (a[pos] != t) pos++;
        cout << pos << ' ';
        while (pos > 1) {
            swap(a[pos - 1], a[pos]);
            pos--;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}