#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    int ans = 0;
    for (int i=1, r; i<=n; i++) {
        cin >> r;
        ans += (r!=2);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}