#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    cout << 2 << '\n';
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            int u = i;
            while (u <= n) {
                cout << u << ' ';
                u *= 2;
            }
        }
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