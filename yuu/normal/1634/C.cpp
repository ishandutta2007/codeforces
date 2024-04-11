#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
    cin >> n >> k;
    if (n % 2) {
        if (k == 1) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << i << '\n';
        } else {
            cout << "NO\n";
        }
        return;
    }
    cout << "YES\n";
    for (int turn = 1; turn <= 2; turn++) {
        int val = turn;
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 1; j <= k; j++) {
                cout << val << " \n"[j == k];
                val += 2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}