#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> sum{0};
    while (sum.back() < n) {
        sum.push_back(sum.back() + (sum.size() + 1) / 2);
    }
    sum.back() = n;
    int m = sum.size() - 1;
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += (sum[i] - sum[i - 1]) * i;
    }
    cout << ans << "\n";
    vector<int> lim(m + 1);
    for (int i = 0; i <= m; i++) {
        lim[i] = m - 1 - i;
        if (lim[i] % 2 == 0) lim[i]--;
    }
    int need = n - sum[sum.size() - 2];
    for (int c = 1; c <= m; c += 2) {
        if (need) need--, lim[m - c] = c;
    }
    vector<int> ps(m + 1);
    for (int k = 0; k < m; k++) {
        ps[k + 1] = ps[k] + (lim[k] + 1) / 2;
    }
    while (q--) {
        int x;
        cin >> x;
        int kmin = lower_bound(ps.begin(), ps.end(), x) - ps.begin();
        kmin = max(0, kmin - 20);
        ll L = 1, R = 1LL << 40;
        while (L < R) {
            ll v = (L + R) / 2;
            int cnt = ps[kmin];
            for (int i = kmin; i < kmin + 40 && i < m; i++) {
                ll y = v >> (i - kmin);
                if (y % 2 == 0) y--;
                y = min(y, 1LL * lim[i]);
                cnt += (y + 1) / 2;
            }
            if (cnt >= x) R = v;
            else L = v + 1;
        }
        int ctz = __builtin_ctzll(L);
        cout << (kmin + ctz + (L >> ctz)) << "\n";
    }
    return 0;
}