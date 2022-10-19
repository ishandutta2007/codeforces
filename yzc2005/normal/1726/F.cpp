#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, t, g[N], c[N], o[N], st[N], ed[N];
long long dp[N], s[N];

const int M = N * 5;
int val[M << 2];

void init() {
    fill(val, val + (M << 2), n + 1);
}

void cover(int p, int l, int r, int ll, int rr, int x) {
    if (l >= ll && r <= rr) {
        val[p] = x;
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= ll) {
        cover(p << 1, l, mid, ll, rr, x);
    }
    if (mid < rr) {
        cover(p << 1 | 1, mid + 1, r, ll, rr, x);
    }
}

int query(int p, int l, int r, int pos) {
    if (l == r) {
        return val[p];
    }
    int res = val[p];
    int mid = (l + r) >> 1;
    if (mid >= pos) {
        return min(res, query(p << 1, l, mid, pos));
    } else {
        return min(res, query(p << 1 | 1, mid + 1, r, pos));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> t;

    for (int i = 1; i <= n; ++i) {
        cin >> g[i] >> c[i];
    }
    
    for (int i = 2; i <= n; ++i) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    vector<int> pos;

    for (int i = 1; i <= n; ++i) {
        o[i] = (t - (c[i] + s[i]) % t) % t;
        st[i] = (g[i] + o[i]) % t;
        ed[i] = o[i];

        pos.emplace_back(st[i]);
        pos.emplace_back(ed[i]);
        pos.emplace_back(o[i]);
        pos.emplace_back((g[i] - 1 + o[i] + 1ll * t) % t);
    }

    pos.emplace_back((t - c[1]) % t);

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    for (int i = 1; i <= n; ++i) {
        st[i] = lower_bound(pos.begin(), pos.end(), st[i]) - pos.begin() + 1;
        ed[i] = lower_bound(pos.begin(), pos.end(), ed[i]) - pos.begin() + 1;
        o[i] = lower_bound(pos.begin(), pos.end(), o[i]) - pos.begin() + 1;
    }

    int m = pos.size();
    init();

    for (int i = n; i >= 2; --i) {
        int j = query(1, 1, m, o[i]);
        if (j == n + 1) {
            dp[i] = s[n] - s[i];
        } else {
            dp[i] = dp[j] + s[j] - s[i];

            int x = (pos[o[i] - 1] - pos[o[j] - 1] + t) % t;
            assert(x >= g[j]);
            // cerr << "i = " << i << ", o = " << o[i] << ", j = " << j << ", g = " << g[j] << ", x = " << x << "\n";
            dp[i] += t - x;
        }
        
        // cerr << "i = " << i << ", st = " << st[i] << ", ed = " << ed[i] << "\n";
        if (st[i] < ed[i]) {
            cover(1, 1, m, st[i], ed[i] - 1, i);
        } else {
            cover(1, 1, m, st[i], m, i);
            if (ed[i] > 1) {
                cover(1, 1, m, 1, ed[i] - 1, i);
            }
        }
    }

    long long ans = 1e18;
    for (int i = 1; i <= m; ++i) {
        int x = (pos[i - 1] + c[1]) % t;
        if (x >= g[1]) {
            continue;
        }

        int j = query(1, 1, m, i);
        long long res = 0;
        
        if (j == n + 1) {
            res = s[n];
        } else {
            res = dp[j] + s[j];

            int x = (pos[i - 1] - pos[o[j] - 1] + t) % t;
            assert(x >= g[j]);
            // cerr << "i = " << i << ", j = " << j << ", g = " << g[j] << ", x = " << x << "\n";
            res += t - x;
        }

        ans = min(ans, res);
    }

    cout << ans << "\n";

    return 0;
}