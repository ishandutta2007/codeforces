#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    partition(a + 1, a + n + 1, [](const auto& value) { return (value % 2) == 0; });
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2 == 0) {
            ans += n - i;
        } else {
            for (int j = i + 1; j <= n; j++) ans += (gcd(a[i], a[j]) > 1);
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