#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (n > m) {
        cout << "No\n";
    } else {
        if (n % 2) {
            cout << "Yes\n";
            for (int i = 1; i < n; ++i) {
                cout << "1 ";
            }
            cout << m - n + 1 << "\n";
        } else {
            if (m % 2) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
                for (int i = 1; i < n - 1; ++i) {
                    cout << "1 ";
                }
                int x = (m - (n - 2)) / 2;
                cout << x << " " << x << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}