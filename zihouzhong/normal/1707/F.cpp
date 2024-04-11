#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, t, w;
    cin >> n >> m >> t >> w;
    t = min(t, 1 << __builtin_ctz(n));
    int lim = __lg(n - 1) + 1;
    vector<int> a(1 << (lim + 1));
    for (int i = 0; i < 1 << lim; i++) {
        a[i | (1 << lim)] = i < n ? -1 : 0;
    }
    int extra = 0, bad = 0;
    auto upd = [&](int l, int i, int v) {
        int x = a[(2 << l) + i], y = a[(3 << l) + i], &z = a[(1 << l) + i];
        if (t >> l & 1) {
            if (!~x || !~y || x == y) z = x & y;
            else z = 0, bad += v;
        } else {
            if (!~x && !~y) z = -1, extra += v;
            else if (!~x || !~y) z = x | y;
            else z = x ^ y;
        }
    };
    for (int i = lim - 1; ~i; i--) {
        for (int j = 0; j < 1 << i; j++) upd(i, j, 1);
    }
    auto set = [&](int p, int v) {
        for (int i = lim - 1; ~i; i--) {
            upd(i, p & ((1 << i) - 1), v);
        }
    };
    while (m--) {
        int p, v;
        cin >> p >> v, p--;
        set(p, -1);
        a[(1 << lim) + p] = v, set(p, 1);
    }
    int q;
    cin >> q;
    while (q--) {
        int p, v, P;
        cin >> p >> v >> P, p--;
        set(p, -1);
        a[(1 << lim) + p] = v, set(p, 1);
        if (bad) { cout << "0\n"; continue; }
        int e = w * (extra + (a[1] == -1)), x = 1;
        for (int y = 2; e; e >>= 1, y = 1LL * y * y % P) {
            if (e & 1) x = 1LL * x * y % P;
        }
        cout << x << "\n";
    }
    return 0;
}