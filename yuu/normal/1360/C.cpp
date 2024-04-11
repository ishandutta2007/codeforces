#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += a[i] % 2;
    if (cnt % 2 == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (abs(a[i] - a[j]) == 1) {
                cout << "YES\n";
                return;
            }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}