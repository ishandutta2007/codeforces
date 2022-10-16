#include <bits/stdc++.h>
using namespace std;
void solve() {
    int x;
    cin >> x;
    int y = 0;
    int ans = 0;
    for (int i = 1; y < x; i++) {
        ans++;
        y += i;
    }
    int rem = y - x;
    if (rem == 1) ans++;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ;
    int t = 1;
    cin >> t;
    while (t--) solve();
}