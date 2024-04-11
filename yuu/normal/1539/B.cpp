#include <bits/stdc++.h>
using namespace std;
int n, q;
string s;
int val[100001];
void solve() {
    cin >> n >> q;
    cin >> s;
    for (int i = 0; i < n; i++) val[i + 1] = s[i] - 'a' + 1;
    for (int i = 1; i <= n; i++) val[i] += val[i - 1];
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        cout << val[r] - val[l - 1] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}