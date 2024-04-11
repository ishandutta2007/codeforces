#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

/// g:gcd(a, b), ax+by=g
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
    if (b == 0) {
        if (a >= 0) return EG{a, 1, 0};
        else return EG{-a, -1, 0};
    } else {
        auto e = ext_gcd(b, a % b);
        return EG{e.g, e.y, e.x - a / b * e.y};
    }
}

ll inv_mod(ll x, ll md) {
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

const int MN = 402;
ll MD, MDMD;

ll fact[MN], iFac[MN];
ll C[MN][MN];
void first() {
    fact[0] = 1;
    for (int i = 1; i < MN; i++) fact[i] = fact[i-1] * i % MD;
    for (int i = 0; i < MN; i++) iFac[i] = inv_mod(fact[i], MD);
    C[0][0] = 1;
    for (int i = 1; i < MN; i++) {
        C[i][0] = C[i-1][0];
        for (int j = 1; j < MN; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MD;
        }
    }
}

ll ans[MN];

ll dp[MN][MN] = {}, ndp[MN][MN] = {}; // num, sum

void add(int _f, int sm, ll _x) {
    for (int i = 0; i < MN; i++) for (int j = 0; j < MN; j++) ndp[i][j] = 0;
    ll f = 1, x = 1;
    for (int k = 0; k < MN; k++) {
        for (int i = 0; i + k < MN; i++) {
            for (int j = 0; j + k * sm < MN; j++) {
                if (dp[i][j] == 0) continue;
                ndp[i + k][j + k * sm] += f * dp[i][j] * x % MD * C[i + k][k];
                if (abs(ndp[i + k][j + k * sm]) > MDMD) {
                    ndp[i + k][j + k * sm] %= MD;
                }
            }
        }
        f *= _f; x = (x * _x) % MD;
    }
    for (int i = 0; i < MN; i++) for (int j = 0; j < MN; j++) {
        dp[i][j] = (ndp[i][j]) ? (ndp[i][j] % MD) : 0;
        if (dp[i][j] < 0) dp[i][j] += MD;
    }
}

void exec() {
    ans[1] = 1;
    dp[0][0] = 1;
    for (int i = 2; i < MN; i++) add(i % 2 ? 1 : -1, i, 2);
    for (int n = 2; n < MN; n++) {
        ans[n] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == 0) continue;
                ans[n] += dp[i][j] * fact[n - j + i] % MD * C[n - j + i][i] % MD;
            }
        }
        ans[n] %= MD;
        add(-1, n, ans[n]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int t;
    cin >> t >> MD; MDMD = 7 * MD * MD;
    first();
    exec(); ans[2] = 2;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}