#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int total = 0;
    for (int i = 1; i <= n; i++) total ^= a[i];
    if (total == 0) {
        cout << "YES\n";
        return;
    }
    // total != 0 -> at least 3
    int now = 0, prefix = 0;
    for (int i = 1; i <= n; i++) {
        now ^= a[i];
        if (now == total) {
            prefix = i;
            break;
        }
    }
    now = 0;
    for (int i = n; i > prefix; i--) {
        now ^= a[i];
        if (now == total) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}