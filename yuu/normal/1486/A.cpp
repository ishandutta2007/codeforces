#include <bits/stdc++.h>
using namespace std;
int n;
int64_t h[101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    h[0] = -1;
    for (int i = 1; i <= n; i++) {
        if (h[i] <= h[i - 1]) {
            cout << "NO\n";
            return;
        } else {
            h[i + 1] += h[i] - h[i - 1] - 1;
            h[i] = h[i - 1] + 1;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}