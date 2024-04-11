#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    if (a[1] >= 2) {
        cout << "YES\n";
        return;
    }
    if (a[1] == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    } else {
        assert(a[1] == 1);
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) {
                cout << "NO\n";
                return;
            }
        }
        for (int i = 1; i < n; i++) {
            if (a[i + 1] == a[i] + 1) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}