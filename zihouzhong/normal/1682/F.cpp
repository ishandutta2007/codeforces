#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010, P = 1000000007;
int n, q, a[maxn], c1[maxn], c2[maxn], ans[maxn];
ll b[maxn];
vector<array<int, 3>> Q[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

void add(int *c, int p, int v) {
    for (; p <= n; p += p & -p) red(c[p] += v - P);
}

int query(int *c, int p) {
    int s = 0;
    for (; p; p -= p & -p) red(s += c[p] - P);
    return s;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i], b[i] += b[i - 1];
    }
    for (int i = 1, l, r; i <= q; i++) {
        cin >> l >> r, l--, r--;
        Q[l].push_back({l, i, 1});
        Q[r + 1].push_back({l, i, P - 1});
    }
    auto solve = [&]() {
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));
        vector<ll> V(b, b + n);
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int i = n - 1; ~i; i--) {
            int k = lower_bound(V.begin(), V.end(), b[i]) - V.begin() + 1;
            add(c1, k, a[i + 1] - a[i]);
            add(c2, k, (b[i] % P + P) * (a[i + 1] - a[i]) % P);
            for (auto &p : Q[i]) {
                k = lower_bound(V.begin(), V.end(), b[p[0]]) - V.begin() + 1;
                int sum = ((b[p[0]] % P + P) * query(c1, k) - query(c2, k) + P) % P;
                ans[p[1]] = (ans[p[1]] + 1LL * p[2] * sum) % P;
            }
        }
    };
    solve();
    for (int i = 0; i < n; i++) {
        b[i] = (ll)1e18 - b[i];
    }
    solve();
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}