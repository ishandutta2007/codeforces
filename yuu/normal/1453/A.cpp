#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    set <int> s;
    for (int i=1, x; i<=n; i++) {
        cin >> x;
        s.insert(x);
    }
    for (int i=1, x; i<=m; i++) {
        cin >> x;
        s.insert(x);
    }
    cout<<n+m-s.size()<<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}