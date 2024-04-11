#include <bits/stdc++.h>
using namespace std;
int n;
int a[4];
void solve() {
    cin >> n;
    for (int i = 0; i < 4; i++) cin >> a[i];
    for (int i = 0; i < 16; i++) {
        int b[4];
        for (int j = 0; j < 4; j++) b[j] = 0;
        for (int j = 0; j < 4; j++)
            if ((i >> j) & 1) {
                b[j]++;
                b[(j + 1) % 4]++;
            }
        for (int j = 0; j < 5; j++) {
            if (j == 4) {
                cout << "YES\n";
                return;
            }
            if (b[j] > a[j]) break;
            if (b[j] + n - 2 < a[j]) break;
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