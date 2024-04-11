#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a, ans = 0;
    cin >> n;
    while (n--) {
        cin >> a;
        ans |= a;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}