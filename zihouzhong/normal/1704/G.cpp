#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2e5;

void solve() {
    int n, m;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) {
        cin >> x;
    }
    cin >> m;
    vector<ll> b(m);
    for (ll &x : b) {
        cin >> x;
    }
    vector<ll> c(n), d(m);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + (i ? 2 * a[i - 1] : 0) + (i > 1 ? a[i - 2] : 0);
    }
    for (int i = 0; i < m; i++) {
        d[i] = b[i] + (i ? 2 * b[i - 1] : 0) + (i > 1 ? b[i - 2] : 0);
    }
    bitset<maxn> good;
    {
        for (int i = 0; i <= n - m; i++) {
            good[i] = 1;
        }
        vector<int> p1(n), p2(m - 2);
        iota(p1.begin(), p1.end(), 0);
        sort(p1.begin(), p1.end(), [&](int i, int j) { return c[i] < c[j]; });
        iota(p2.begin(), p2.end(), 2);
        sort(p2.begin(), p2.end(), [&](int i, int j) { return d[i] < d[j]; });
        bitset<maxn> cur;
        int i1 = 0, i2 = 0;
        for (int j : p2) {
            while (i1 < n && c[p1[i1]] <= d[j]) cur.flip(p1[i1++]);
            while (i2 < n && c[p1[i2]] < d[j] - 1) cur.flip(p1[i2++]);
            good &= cur >> j;
        }
    }
    auto test = [&](ll a, ll b, int i) -> bool {
        i += 2, b += a;
        int even = i - 1 - (i - 1) % 2;
        a += 1LL * even * (even / 2 + 1) / 2;
        b -= even / 2 + 1;
        if (b < -i || b > 0) return 0;
        b *= -1;
        ll l = b * (b - 1) / 2;
        ll r = b * (2 * i - b - 1) / 2;
        return l <= a && a <= r;
    };
    auto construct = [&](ll a, ll b, int i, auto &res) {
        i += 2, b += a;
        int even = i - 1 - (i - 1) % 2;
        a += 1LL * even * (even / 2 + 1) / 2;
        b -= even / 2 + 1;
        b *= -1;
        vector<bool> take(i);
        for (int j = i - 1; ~j && b; j--) {
            ll l = b * (b - 1) / 2;
            ll r = b * (2 * j - b - 1) / 2;
            if (l <= a && a <= r) continue;
            take[j] = 1, a -= j, b--;
        }
        for (int j = 0; j < i; j++) {
            if (take[j] ^ (j % 2 == 0)) res.push_back(i - j - 1);
        }
    };
    for (int i = 0; i <= n - m; i++) {
        if (good[i] && test(b[0] - a[i], b[1] - a[i + 1], i)) {
            vector<int> res;
            for (int j = 2; j < m; j++) {
                if (c[i + j] < d[j]) res.push_back(i + j);
            }
            construct(b[0] - a[i], b[1] - a[i + 1], i, res);
            cout << res.size() << "\n";
            for (int x : res) {
                cout << x + 1 << " ";
            }
            cout << "\n"; return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}