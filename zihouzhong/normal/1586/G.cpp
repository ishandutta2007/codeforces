#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010, P = 1000000007;
int n, q, c[maxn], f[maxn], mp[maxn], vis[maxn];
struct node { int a, b, id; } a[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

void add(int p, int v) {
    for (; p <= 2 * n; p += p & -p) red(c[p] += v - P);
}

int query(int p) {
    int s = 0;
    for (; p; p -= p & -p) red(s += c[p] - P);
    return s;
}

int sum(int l, int r) {
    return l > r ? 0 : (query(r) - query(l - 1) + P) % P;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].a >> a[i].b, a[i].id = i;
    }
    sort(a + 1, a + n + 1, [&](node x, node y) { return x.a < y.a; });
    for (int i = 1; i <= n; i++) {
        mp[a[i].id] = i;
    }
    for (int i = n; i; i--) {
        f[i] = (query(a[i].b) + 1) % P;
        add(a[i].b, f[i]);
    }
    cin >> q;
    while (q--) {
        int x; cin >> x;
        vis[mp[x]] = 1;
    }
    memset(c, 0, sizeof(c));
    int ans = 0;
    for (int i = n; i; i--) {
        if (vis[i]) add(a[i].b, 1);
        if (sum(a[i].b, 2 * n)) (ans += f[i]) %= P;
    }
    cout << ans << '\n';
    return 0;
}