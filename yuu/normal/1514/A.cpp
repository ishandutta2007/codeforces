#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int r = sqrt(a[i]);
        while (r * r > a[i]) r--;
        while (r * r < a[i]) r++;
        if (r * r != a[i]) {
            cout << "YES\n";
            return;
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