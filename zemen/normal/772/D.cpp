#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;
int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}
int mul(ll a, ll b) {
    return a * b % mod;
}
int sqr(ll a) {
    return mul(a, a);
}

const int maxn = 1100100;
int cnt[maxn];
int s1[maxn];
int s2[maxn];
int d[maxn];
int pow2[maxn];
int p10[maxn];

int dig(int n, int k) {
    return (n / p10[k]) % 10;
}

int setDig(int n, int k, int d) {
    int res = (n / p10[k + 1]) * p10[k + 1];
    res += d * p10[k];
    res += n % p10[k];
    return res;
}

vector<int> digOrd[6][10];

const int M = 1e6;
void conv(int *a, bool inv = false) {
    for (int pos = 0; pos < 6; ++pos) {
        if (!inv) {
            for (int d = 8; d >= 0; --d) {
                for (int i: digOrd[pos][d]) {
                    int to = setDig(i, pos, d + 1);
                    udd(a[i], a[to]);
                }
            }
        } else {
            for (int d = 0; d <= 8; ++d) {
                for (int i: digOrd[pos][d]) {
                    int to = setDig(i, pos, d + 1);
                    udd(a[i], mod - a[to]);
                }
            }
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    pow2[0] = 1;
    for (int i = 1; i < maxn; ++i)
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);
    p10[0] = 1;
    forn (i, 8)
        p10[i + 1] = p10[i] * 10;

    forn (pos, 6) {
        forn (i, M) {
            digOrd[pos][dig(i, pos)].push_back(i);
        }
    }

    int n;
    scanf("%d", &n);
    forn (i, n) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
        udd(s1[a], a);
        udd(s2[a], sqr(a));
    }
    conv(cnt);
    conv(s1);
    conv(s2);
    forn (i, M) {
        if (cnt[i] == 0)
            continue;
        else if (cnt[i] == 1) {
            d[i] = s2[i];
        } else {
            int p2 = pow2[cnt[i] - 2];
            d[i] = mul(p2, sqr(s1[i]));
            udd(d[i], mul(p2, s2[i]));
        }
    }
    conv(d, true);
    ll res = 0;
    forn (i, M) {
        res ^= ll(d[i]) * i;
    }
    cout << res << '\n';
}