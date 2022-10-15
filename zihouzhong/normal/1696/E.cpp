#include <bits/stdc++.h>
using namespace std;

const int maxn = 400010, P = 1000000007;
int n, a[maxn], fact[maxn], finv[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = fact[0] = finv[0] = 1; i < maxn; i++) {
        fact[i] = 1LL * i * fact[i - 1] % P;
        finv[i] = qp(fact[i], P - 2);
    }
    auto binom = [&](int x, int y) -> int {
        if (x < y || y < 0) return 0;
        return 1LL * fact[x] * finv[y] % P * finv[x - y] % P;
    };
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        (ans += binom(i + a[i], i + 1)) %= P;
    }
    cout << ans << "\n";
    return 0;
}