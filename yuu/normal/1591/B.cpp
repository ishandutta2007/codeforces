#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int mx = n;
    for (int i = n; i >= 1; i--) {
        if (a[i] > a[mx]) {
            mx = i;
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}