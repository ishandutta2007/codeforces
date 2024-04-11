#include <bits/stdc++.h>
using namespace std;
int n, l;
int a[101];
void solve() {
    cin >> n >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    int weight = 1;
    for (int j = 1; j <= l; j++) {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] % 2)
                sum++;
            else
                sum--;
        for (int i = 1; i <= n; i++) a[i] /= 2;
        if (sum > 0) ans += weight;
        weight *= 2;
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