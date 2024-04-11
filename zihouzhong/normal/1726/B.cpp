#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        cout << "No\n"; return;
    }
    if (n % 2 == 1) {
        cout << "Yes\n";
        for (int i = 1; i < n; i++) {
            cout << 1 << " ";
        }
        cout << m - n + 1 << "\n";
    } else if (m % 2 == 0) {
        cout << "Yes\n";
        for (int i = 1; i < n - 1; i++) {
            cout << 1 << " ";
        }
        cout << (m - n + 2) / 2 << " " << (m - n + 2) / 2 << "\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}