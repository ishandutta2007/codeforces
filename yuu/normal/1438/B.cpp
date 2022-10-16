#include <bits/stdc++.h>
using namespace std;
int n;
int64_t b[1001];
set<int64_t> s;
void solve() {
    cin >> n;
    s.clear();
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s.insert(b[i]);
    }
    if (s.size() < n) cout << "YES\n";
    else cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}