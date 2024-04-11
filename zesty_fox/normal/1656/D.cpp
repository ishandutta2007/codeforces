#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

template <typename T> inline T read() {
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        f |= (ch == '-'), ch = getchar();
    while (isdigit(ch))
        x = (x * 10) + (ch ^ 48), ch = getchar();
    return !f ? x : -x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

ll quick_pow(ll x, ll p, ll mod) {
    ll ans = 1;
    while (p) {
        if (p & 1)
            ans = (__int128)ans * x % mod;
        x = (__int128)x * x % mod;
        p >>= 1;
    }
    return ans;
}

bool Miller_Rabin(ll p) {
    if (p < 2)
        return 0;
    if (p == 2)
        return 1;
    if (p == 3)
        return 1;
    ll d = p - 1, r = 0;
    while (!(d & 1))
        ++r, d >>= 1;
    for (ll k = 0; k < 10; ++k) {
        ll a = rand() % (p - 2) + 2;
        ll x = quick_pow(a, d, p);
        if (x == 1 || x == p - 1)
            continue;
        for (int i = 0; i < r - 1; ++i) {
            x = (__int128)x * x % p;
            if (x == p - 1)
                break;
        }
        if (x != p - 1)
            return 0;
    }
    return 1;
}

ll Pollard_Rho(ll x) {
    ll s = 0, t = 0;
    ll c = (ll)rand() % (x - 1) + 1;
    int step = 0, goal = 1;
    ll val = 1;
    for (goal = 1;; goal *= 2, s = t, val = 1) {
        for (step = 1; step <= goal; ++step) {
            t = ((__int128)t * t + c) % x;
            val = (__int128)val * abs(t - s) % x;
            if ((step % 127) == 0) {
                ll d = __gcd(val, x);
                if (d > 1)
                    return d;
            }
        }
        ll d = __gcd(val, x);
        if (d > 1)
            return d;
    }
}

ll max_factor, lim, res;
void fac(ll x) {
    if (x <= max_factor || x < 2)
        return;
    if (x <= lim) {
        res = x;
        return;
    }
    if (Miller_Rabin(x)) {
        max_factor = max(max_factor, x);
        return;
    }
    ll p = x;
    while (p >= x)
        p = Pollard_Rho(x);
    while ((x % p) == 0)
        x /= p;
    fac(x), fac(p);
}

ll n;
void solve() {
    n = rdll();
    ll l = 1, r = 2e9;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (mid * (mid + 1) / 2 <= n)
            l = mid;
        else
            r = mid - 1;
    }
    lim = l;
    if (l <= 1)
        puts("-1");
    else {
        ll x = 2;
        while (x <= l) {
            if (n % x == (x / 2)) {
                cout << x << '\n';
                return;
            }
            x *= 2;
        }

        x = n;
        while (x % 2 == 0)
            x /= 2;
        res = 0;
        fac(x);
        if (!res)
            puts("-1");
        else
            cout << res << '\n';
    }
}

int main() {
    int T = rdi();
    while (T--)
        solve();
    return 0;
}