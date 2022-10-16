#include <bits/stdc++.h>
using namespace std;
int n, a, b;
void solve() {
    cin >> n >> a >> b;
    if (a == 1) {
        if ((n - 1) % b == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        int64_t val = 1;
        while (val <= n) {
            if ((n - val) % b == 0) {
                cout << "Yes\n";
                return;
            }
            val *= a;
        }
        cout << "No\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}