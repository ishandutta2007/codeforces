#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100006;
const int mod = 1000000007;

vector<int> G[N];
vector<ll> szz;
int sz[N];
ll p[N];

void dfs(int now, int par, int n) {
    sz[now] = 1;
    for (int i: G[now]) {
        if (i == par) continue;
        dfs(i, now, n);
        sz[now] += sz[i];
        szz.push_back(sz[i] * 1ll * (n - sz[i]));
    }
}

void go() {
    int n; scanf("%d", &n);
    for (int i = 0; i <= n; ++i) {
        G[i].clear();
    }
    szz.clear();
    for (int i = 1; i < n; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs(1, 1, n);
    sort(szz.begin(), szz.end());
    reverse(szz.begin(), szz.end());
    ll ans = 0;
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%lld", &p[i]);
    }
    sort(p + 1, p + m + 1);
    reverse(p + 1, p + m + 1);
    if ((int)szz.size() < m) {
        int del = m - (int)szz.size();
        for (int j = 2; j <= 1 + del; ++j) {
            p[1] *= p[j];
            p[1] %= mod;
        }
        for (int j = 2; j <= m; ++j) {
            p[j] = p[j + del];
        }
    }
    for (int i = 0; i < (int)szz.size(); ++i) {
        if (i + 1 <= m) {
            ans += szz[i] * p[i + 1] % mod;
            ans %= mod;
        }
        else {
            ans += szz[i];
            ans %= mod;
        }
    }
    printf("%lld\n", ans);
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}