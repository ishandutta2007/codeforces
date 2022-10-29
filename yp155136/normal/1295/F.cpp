#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define F first
#define S second
const ll mod = 998244353;

ll ppow(ll a, ll n) {
    ll ret = 1, now = a;
    while (n) {
        if (n & 1) {
            ret = (ret * now) % mod;
        }
        now = (now * now) % mod;
        n >>= 1;
    }
    return ret;
}

ll iinv(ll x) {
    return ppow(x, mod - 2);
}

const int N = 56;
const int P = 10 * N;

ll dp[N][P];
ll l[N], r[N];
bool have[N][P];
pii p[P];
ll sz[P];

ll C(int n, int m) {
    m = min(m, n - m);
    ll ret = 1;
    for (ll i = 1; i <= m; ++i) {
        ret *= iinv(i);
        ret %= mod;
        ret *= (n - i + 1);
        ret %= mod;
    }
    return ret;
}

ll H(int n, int m) {
    return C(n + m - 1, m);
}

int main () {
    ll n; scanf("%lld", &n);
    vector<ll> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(mod - 1);
    ll ans = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld%lld", &l[i], &r[i]);
        ans *= iinv(r[i] - l[i] + 1);
        ans %= mod;
        v.push_back(l[i]); v.push_back(l[i] - 1);
        v.push_back(r[i]); v.push_back(r[i] + 1);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    int m = v.size();
    v.push_back(mod - 1);
    for (int i = 0; i < m; ++i) {
        p[i + 1] = make_pair(v[i], v[i + 1] - 1);
        sz[i + 1] = p[i + 1].S - p[i + 1].F + 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (l[i] <= p[j].F && p[j].F <= r[i]) {
                have[i][j] = true;
            }
        }
    }
    dp[0][m] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!have[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            for (int ii = i - 1; ii >= 0; --ii) {
                ll val = H(sz[j], i - ii);
                for (int k = j + 1; k <= m; ++k) {
                    dp[i][j] += dp[ii][k] * val;
                    dp[i][j] %= mod;
                }
                if (!have[ii][j]) break;
            }
        }
    }
    ll tot = 0;
    for (int j = 1; j <= m; ++j) {
        tot += dp[n][j];
        tot %= mod;
    }
    printf("%lld\n", tot * ans % mod);
}