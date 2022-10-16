#include <bits/stdc++.h>
using namespace std;
int n;
int c[200001];
int l[21];
int r[21];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) c[i] = 0;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        c[a]++;
    }
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    unsigned lim = n;
    lim = bit_ceil(lim);
    for (int i = 0; (1 << i) <= lim; i++) {
        l[i] = i ? l[i - 1] : 0;
        while ((l[i] < n) && (c[l[i] + 1] <= (1 << i))) l[i]++;
        r[i] = i ? r[i - 1] : n;
        while ((r[i] > 1) && (n - c[r[i] - 1] <= (1 << i))) r[i]--;
    }
    int ans = 1e9;
    for (int i = 0; (1 << i) <= lim; i++)
        for (int j = 0; (1 << j) <= lim; j++) {
            int rem = n - c[l[i]] - (n - c[r[j]]);
            if (rem < 0) continue;
            if (rem == 0) rem = 1;
            rem = bit_ceil(static_cast<unsigned>(rem));
            int res = (1 << i) + (1 << j) + rem - n;
            ans = min(ans, res);
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