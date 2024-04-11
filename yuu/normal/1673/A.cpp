#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a[200001];
void solve() {
    cin >> s;
    n = s.size();
    s = '0' + s;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + s[i] - 'a' + 1;
    }
    if (n == 1) {
        cout << "Bob " << a[1] << '\n';
        return;
    } else {
        int mx = a[n - n % 2];
        if (n % 2) mx = max(mx, a[n] - a[1]);
        cout << "Alice " << mx - (a[n] - mx) << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}