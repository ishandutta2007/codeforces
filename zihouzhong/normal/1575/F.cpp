#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, m, K, f[maxn], p[maxn], s[maxn], fact[maxn], finv[maxn];
unordered_map<int, int> cnt;

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int binom(int n, int m) {
    return 1LL * fact[n] * finv[m] % P * finv[n - m] % P;
}

int solve(int x) {
    static unordered_map<int, int> mp;
    if (mp.count(x)) return mp[x];
    int ans = 0;
    for (int i = 0; i <= m; i++) ans = (ans + 1LL * p[i] * s[i + x]) % P;
    return mp[x] = ans;
}

int main() {
    scanf("%d %d", &n, &K);
    for (int i = fact[0] = finv[0] = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x), cnt[x]++;
    }
    f[0] = K - 1;
    for (int i = 1; i < n; i++) {
        int p = 1LL * i * qp(n, P - 2) % P;
        int q = 1LL * (n - i) * qp(n, P - 2) % P * qp(K - 1, P - 2) % P;
        f[i] = (1LL * p * f[i - 1] + 1) % P * qp(q, P - 2) % P;
    }
    for (int i = n; i; i--) {
        s[i - 1] = (s[i] + f[i - 1]) % P;
    }
    m = cnt[-1];
    for (int i = 0; i <= m; i++) {
        p[i] = 1LL * binom(m, i) * qp(K - 1, m - i) % P * qp(qp(K, m), P - 2) % P;
    }
    int ans = 0, tot = K;
    for (auto &p : cnt) if (~p.first) {
        (ans += solve(p.second)) %= P, tot--;
    }
    ans = (ans + 1LL * tot * solve(0)) % P;
    ans = (ans - 1LL * (K - 1) * s[0] % P + P) % P;
    printf("%lld\n", 1LL * ans * qp(K - 1, P - 2) % P);
    return 0;
}