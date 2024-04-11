#include <bits/stdc++.h>
using namespace std;
int n, b, r;
void solve() {
    cin >> n >> r >> b;
    while (b >= 0) {
        int mx = (r - 1) / (b + 1) + 1;
        for (int j = 0; j < mx; j++) {
            cout << 'R';
            r--;
        }
        if (b) cout << 'B';
        b--;
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}